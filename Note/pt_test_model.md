# 代码的作用

首先确保你有一个已经训练好的 yolo 模型，比如`best.pt`，一个 video 文件。代码将会获取你的视频后，对视频的每帧进行检测，绘制检测框和类名，最后输出一个视频

# 使用方法

## 项目结构

```
-yourProject
|--pt_test_model.py
|--vedio
||--yourvideo.mp4
```

在运行代码之后，会在当前目录下生成一个 result_video 文件

```
-yourProject
|--pt_test_model.py
|--vedio
||--yourvideo.mp4
|--result_video
||--video_name
|||--result_video.mp4
```

## 使用步骤

```bash
# 下载必要的库文件
pip install ultralytics

# 进入你的项目所在的工作目录
cd yourProject

#运行
python pt_test_model.py

```

# 源码

```python
from ultralytics import YOLO
import cv2
import torch
import os

# 检查是否有可用的GPU
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(f'Using device: {device}')

# 加载预训练的YOLO模型
model = YOLO('best.pt')
model.to(device)

# 打开视频文件
video_path = 'video/89_1742982387.mp4'
cap = cv2.VideoCapture(video_path)  # 替换为你的视频文件路径

# 获取视频的基本信息
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = cap.get(cv2.CAP_PROP_FPS)

# 提取文件名
base_name = os.path.basename(video_path)

# 去掉文件拓展名，只保留文件名
folder_name = os.path.splitext(base_name)[0]

# 创建用于保存结果图片的文件夹（如果不存在则创建）
result_dir = os.path.join("reslut_video", folder_name)

if not os.path.exists(result_dir):
    os.makedirs(result_dir)

# 定义输出视频的保存路径和编码方式
output_path = os.path.join(result_dir, "result_video.mp4")
fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # mp4编码
out = cv2.VideoWriter(output_path, fourcc, fps, (frame_width, frame_height))

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # 使用YOLO模型进行检测
    results = model(frame, verbose=False)
    boxes = results[0].boxes  # 获取检测框
    class_ids = boxes.cls  # 获取类别ID
    confidences = boxes.conf  # 获取置信度
    class_names = results[0].names  # 类别名称列表

    # 遍历每个检测框并绘制
    for i in range(len(boxes)):
        box = boxes[i].xyxy[0]  # 获取框坐标
        x1, y1, x2, y2 = map(int, box)  # 转换为整数坐标

        conf = confidences[i]
        cls = int(class_ids[i])
        label = f"{class_names[cls]}: {conf:.2f}"

        # 绘制边框
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # 计算文本大小
        (text_width, text_height), baseline = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 2)

        # 标签放置在检测框下方，避免超出图像范围
        # 如果下方空间不足，则放置在框上方
        if y2 + text_height + baseline > frame_height:
            text_org = (x1, y1 - 10)
        else:
            text_org = (x1, y2 + text_height + baseline)

        cv2.putText(frame, label, text_org, cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # 将处理后的帧写入输出视频
    out.write(frame)

# 释放视频流和写入对象
cap.release()
out.release()

```

# 解析

## 打开视频文件

```python
cap = cv2.VideoCapture(video_path)
```

cv2.VideoCapture 是 opencv 库中用于视频捕捉的一个类，能够从视频或者摄像头捕获帧

## 获取视频的像素、帧数信息

```python
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
fps = cap.get(cv2.CAP_PROP_FPS)
```

`cv2.CAP_PROP_FRAME_WIDTH`和`cv2.CAP_PROP_FRAME_HEIGHT`表示视频帧的像素尺寸，是整数。但是`cap.get()`返回的可能是浮点数（比如 1920.0），强制转换为 int 可以避免后续处理（比如创建视频写入对象`cv2.VideoWriter`）时的类型错误。

`cap.get()`的返回值类型通常是`float`,即使属性本身是整数。
但是帧率可以是浮点数，如`cv2.CAP_PROP_FPS`表示视频帧率（如 29.97）通常保留小数精度，因此无需转换

## 定义输出路径和编码方式

```python
base_name = os.path.basename(video_path)
folder_name = os.path.splitext(base_name)[0]
result_dir = os.path.join("reslut_video", folder_name)

if not os.path.exists(result_dir):
    os.makedirs(result_dir)

output_path = os.path.join(result_dir, "result_video.mp4")
fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # mp4编码
out = cv2.VideoWriter(output_path, fourcc, fps, (frame_width, frame_height))
```

这里是在创建输出的文件路径以及定义输出视频的编码方式

`cv2.VideoWriter_fourcc`生成一个整数形式的 FourCC 编码标识符，这个代码定义了视频的压缩格式。常见的类型包括：`XVID`、`MJPG`、`MPV4`
如果是在 C++中则直接传递四个字符参数：

```cpp
int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D');
```

## 处理视频中的帧

### 获取帧

```python
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break
```

`cap.isOpened()`是`cv2.VideoCapture`的成员函数，用于检查视频捕获对象是否成功初始化并准备好进行读取操作，在处理流程中起到验证作用

- 无参数调用：不需要任何的参数，直接通过对象调用
- 布尔值返回值类型：true 表示资源已就绪，可进行 read()等操作，返回 false 表示未打开或者失败

`cap.read()`:cap 在上面提到是一个视频输入的对象，调用 read()方法从该对象中获取一帧图像。该方法的返回值有两个：

- ret:表示读取是否成功的布尔值，如果为 false，则可能读取失败或者已经读取完
- frame：读取到的图像帧

### 使用 YOLO 模型检测，获取检测到的目标的基本信息

```python
    # 使用YOLO模型进行检测
    results = model(frame, verbose=False)
    boxes = results[0].boxes  # 获取检测框
    class_ids = boxes.cls  # 获取类别ID
    confidences = boxes.conf  # 获取置信度
    class_names = results[0].names  # 类别名称列表
```

`results`是一个列表，这里的 frame 只对应了一张图像，所以 results[0]对应的是该图像的处理结果，如果是多张图像，可以像下面这样

```python
frames = [frame1, frame2, frame3]  # 多张图像列表
results = model(frames)

# 我们可以遍历每张图片的结果
for result in results:
    print(result.boxes)
```

results[0]的属性如下：

| 属性                 | 说明                                                                   |
| -------------------- | ---------------------------------------------------------------------- |
| results[0].boxes     | 检测框信息（坐标、置信度、类别 ID），操作方式与之前描述的 boxes 一致。 |
| results[0].masks     | （分割模型）分割掩码，格式为 torch.Tensor 或二进制掩码。               |
| results[0].keypoints | （姿态估计模型）关键点坐标和置信度。                                   |
| results[0].orig_img  | 原始图像（numpy.ndarray 格式），可用于可视化。                         |
| results[0].names     | 类别名称字典（如 {0: 'person', 1: 'car', ...}）。                      |

`boxes`里的属性如下：

| 属性       | 数据类型（Tensor） | 说明                                                               |
| ---------- | ------------------ | ------------------------------------------------------------------ |
| **.xyxy**  | [N, 4]             | 检测框的绝对坐标，格式为 [左上 x, 左上 y, 右下 x, 右下 y]。        |
| **.xyxyn** | [N, 4]             | 归一化坐标（相对于图像尺寸），范围 [0, 1]。                        |
| **.xywh**  | [N, 4]             | 检测框的中心点坐标及宽高，格式为 [中心 x, 中心 y, 宽度, 高度]。    |
| **.xywhn** | [N, 4]             | 归一化的中心点坐标及宽高（范围 [0, 1]）。                          |
| **.conf**  | [N]                | 每个检测框的置信度（0~1 之间）。                                   |
| **.cls**   | [N]                | 每个检测框的类别 ID（整数，需通过 results.names 映射到类别名称）。 |
| **.data**  | [N, 6]             | 所有检测信息的合并张量，格式为 [x1, y1, x2, y2, conf, cls]。       |
| **.id**    | [N]                | （仅多目标跟踪模型）每个检测框的目标 ID。                          |

### 绘制检测框

```python
 # 遍历每个检测框并绘制
    for i in range(len(boxes)):
        box = boxes[i].xyxy[0]  # 获取框坐标
        x1, y1, x2, y2 = map(int, box)  # 转换为整数坐标

        conf = confidences[i]
        cls = int(class_ids[i])
        label = f"{class_names[cls]}: {conf:.2f}"

        # 绘制边框
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

        # 计算文本大小
        (text_width, text_height), baseline = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 2)

        # 标签放置在检测框下方，避免超出图像范围
        # 如果下方空间不足，则放置在框上方
        if y2 + text_height + baseline > frame_height:
            text_org = (x1, y1 - 10)
        else:
            text_org = (x1, y2 + text_height + baseline)

        cv2.putText(frame, label, text_org, cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
```

`for i in range(len(boxes))`分别绘制同一帧中的多个检测框

```
cv2.putText(frame, label, text_org, cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
```

​ 参数如下：

- frame: 输入图像（直接修改原图）。
- label: 要绘制的文本内容（如 "person 0.95"）。
- text_org: 文本左下角起始坐标 (x, y)。
- cv2.FONT_HERSHEY_SIMPLEX: 字体类型，与 getTextSize 一致。
- 0.5: 字体缩放比例。
- (0, 255, 0): 文本颜色（BGR 格式，此处为绿色）。
- 2: 文本线宽。

后面部分主要是改进显示问题，如果检测框在图像的顶部的时候，label 可能会显示在图像之外，就是看不到了

### 将处理后的帧写入视频

```python
    out.write(frame)
```

## 最后释放 cap 和 out 对象

```python
cap.release()
out.release()
```
