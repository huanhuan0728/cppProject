## 创建新目录

在 Linux 命令行中，你可以使用 `mkdir` 命令在当前目录下创建一个文件夹。例如，你想创建一个名为 **"output"** 的文件夹来存放检测结果，可以执行以下命令：

```bash
mkdir output
```

---

## **详细解释**

1. **`mkdir` 命令**：用于创建新的目录。
2. **默认创建在当前目录**：

- 你当前所在的目录可以用 `pwd` 命令查看：

```bash
    pwd
```

- `mkdir output` 会在此目录下创建 `output/` 文件夹。

---

### **进阶用法**

#### **1. 创建文件夹并避免报错**

如果你不确定文件夹是否已经存在，可以加上 `-p` 选项：

```bash
mkdir -p output
```

- `-p`（--parents）：如果文件夹已存在，不会报错。

#### **2. 确认文件夹是否创建成功**

```bash
ls -l
```

- 列出当前目录下的所有文件和文件夹。

#### **3. 进入 `output/` 目录**

```bash
cd output
```

- 进入 `output/` 目录，之后可以在这里存储文件。

#### **4. 将 Python 输出文件保存在 `output/` 目录**

如果你的 Python 代码要保存检测结果到 `output/` 文件夹，可以这样修改：

```python
import os
import cv2

# 确保 output 目录存在

    output_dir = "output"
    os.makedirs(output_dir, exist_ok=True)

# 生成保存路径

    output_path = os.path.join(output_dir, "detection_result.jpg")

# 保存图片

    cv2.imwrite(output_path, image)
    print(f"检测结果已保存至: {output_path}")
```

---

这样，你的 YOLO 目标检测结果就会自动保存到 `output/` 文件夹中了！🚀
如果你还有其他 Linux 相关问题，欢迎继续提问！

## 删除空文件夹

### **1. 删除空文件夹**

如果 `output` 文件夹是空的，可以使用：

```bash
rmdir output
```

- **`rmdir` 只能删除空目录**，如果目录非空，会报错。

---

### **2. 强制删除非空文件夹**

如果 `output` 目录里面有文件，可以使用：

```bash
rm -rf output
```

- **`-r`（recursive）：递归删除文件夹及其所有内容**
- **`-f`（force）：强制删除，不提示确认**

⚠ **危险提示**：

- `rm -rf` 是一个**强制删除**命令，操作时要小心，**避免误删重要文件**。
- 你可以先用 `ls output/` 查看 `output` 目录里的内容，确保没有误删的文件。

---

### **3. 先确认后删除**

```bash
rm -r -i output
```

- **`-i`（interactive）：交互式删除，每次删除前询问 "是否删除？"**
- 适用于防止误删。

### **4. 确保删除后目录不存在**

你可以在删除后执行：

```bash
ls -l
```

**总结**
| 命令 | 适用情况 |
|------|-------|
| `rmdir output` | 仅删除 **空** 目录 |
| `rm -rf output` | 强制删除 **非空** 目录（⚠ 危险） |
| `rm -r -i output` | 逐个确认删除 |

## 移动文件

### 在 Linux 中，使用`mv`命令可以移动文件或目录。以下是详细步骤和常见用法：

#### 基本语法

```bash
mv [选项] 源文件或目录 目标目录或路径
```

#### 常见用法

1.  **移动单个文件到目录**

```bash
mv 文件名 目标目录/
```

示例：

```bash
mv file.txt /home/user/documents/
```

2.  **移动多个文件到目录**

```bash
mv 文件1 文件2 ... 目标目录/
```

示例：

```bash
mv file1.txt file2.txt /home/user/documents/
```

3.  **移动并重命名文件**

```bash
mv 原文件名 目标目录/新文件名
```

示例：

```bash
mv file.txt /home/user/documents/newfile.txt
```

4.  **移动目录**

```bash
mv 目录名 目标目录/
```

示例：

```bash
mv my_folder /home/user/documents/
```

#### 常用选项

• `-i`：覆盖前提示确认（防止误覆盖）。

```bash
mv -i file.txt /目标目录/
```

• `-f`：强制覆盖，不提示（谨慎使用）。

```bash
mv -f file.txt /目标目录/
```

• `-v`：显示操作细节（verbose 模式）。

```bash
mv -v file.txt /目标目录/
```

#### 注意事项

1.  **目标目录必须存在**：若目标目录不存在，`mv`会尝试将源文件/目录重命名为目标路径（可能导致意外结果）。
2.  **同名文件覆盖**：默认直接覆盖目标目录中的同名文件（除非系统别名设置了`-i`）。
3.  **权限问题**：若目标目录无写入权限，需使用`sudo`或调整权限。
4.  **特殊字符处理**：文件名含空格或特殊字符时，用引号包裹或转义符`\`。
    示例：

```bash
mv "my file.txt" /目标目录/
mv my\ file.txt /目标目录/
```

#### 示例验证

1.  创建测试文件：

```bash
touch test.txt
mkdir test_dir
```

2.  移动文件到目录：

```bash
mv test.txt test_dir/
```

3.  检查结果：

```bash
ls test_dir/
# 应看到 test.txt 存在
```

## 复制文件

使用 `cp` 命令复制文件到指定路径的文件夹

### **1. 基础复制操作**

**命令格式**：

```bash
cp [选项] 源文件路径 目标文件夹路径/
```

**示例**：

```bash
# 将当前目录下的 file.txt 复制到 /home/user/documents/ 目录
cp file.txt /home/user/documents/
```

**注意**：目标路径末尾的 `/` 可明确表示这是一个文件夹，避免歧义（如果目标路径不是目录会报错）。

---

### **2. 常用选项**

| 选项 | 说明                           |
| ---- | ------------------------------ |
| `-v` | 显示复制进度（verbose）        |
| `-i` | 覆盖前提示确认（interactive）  |
| `-p` | 保留文件属性（权限、时间戳等） |
| `-r` | 递归复制目录（用于复制文件夹） |
| `-f` | 强制覆盖，不提示（force）      |

**示例**：

```bash
# 保留属性并显示进度（适合备份）
cp -p -v file.txt /backup/

# 递归复制整个目录（包括子目录）
cp -r my_folder/ /target/path/
```

---

### **3. 处理目标路径不存在的情况**

如果目标路径不存在，需先创建目录：

```bash
# 先创建目录，再复制文件
mkdir -p /home/user/new_folder/ && cp file.txt /home/user/new_folder/
```

`-p` 选项会自动创建父级目录（如路径中有多级不存在）。

---

### **4. 重命名文件**

在复制时直接指定新文件名：

```bash
# 复制 file.txt 到目标目录并重命名为 data.txt
cp file.txt /target/path/data.txt
```

---

### **5. 覆盖已有文件**

• **默认直接覆盖**：如果目标路径有同名文件，`cp` 会直接覆盖（无提示）。
• **安全覆盖**：使用 `-i` 选项，覆盖前确认：

```bash
cp -i file.txt /target/path/
```

---

### **6. 高级替代工具：`rsync`**

`rsync` 支持增量复制和进度显示，适合大文件或远程同步：

```bash
# 基本用法（保留属性并显示进度）
rsync -avh file.txt /target/path/
```

---

### **总结**

• **基础命令**：`cp 源文件 目标路径/`
• **保留属性**：加 `-p`
• **复制目录**：加 `-r`
• **避免覆盖风险**：加 `-i`

## 创建空文件

### touch

创建一个新的空文件，或者更新已有的文件的时间戳（如果文件已经存在，不会覆盖内容）
三种时间戳 ：修改时间、访问时间、状态变更时间

```bash
touch 文件名
```

### 重定向符合 >

（快速创建文件或者覆盖内容,创建一个空文件，或者清空已有文件的内容

```bash
> newfile.txt       # 创建空文件newfile.txt
echo "内容“ > file  # 将内容写进文件（覆盖原有内容）
```

## 创建 conda 环境

1.基本命令

```bash
conda create --name 环境名
```

指定 python 版本

```bash
conda create --name 环境名 python=版本号
conda create --name myenv python=3.9
```

2. 创建环境时直接安装包

```bash
conda create --name 环境名 python=版本号 包1 包2 ...
```

3. 激活环境

```bash
conda activate 环境名

# 退出环境
conda deactivate

# 查看所有环境
conda env list

# 删除环境
conda env remove --name 环境名

# 克隆环境
conda create --name 新环境名 --clone 原环境名
```

4. 检查环境

```bash
# 检查python环境
python --version

# 查看已经安装的包
conda list
```

## 登陆 orange π 的终端查看日志

```bash
ssh -p 10005 orangepi@ngsk.tech

# 密码
ngsk0809

tail -n 200 lift_runtime/runtime.log
```

## 将日志从服务器拷贝到本地

```bash
scp -P 10005 orangepi@ngsk.tech:/home/orangepi/lift_runtime/runtime.log /Users/xuhuanlu/Desktop/nenggeProject/log/

scp -P 10005 orangepi@ngsk.tech:/home/orangepi/lift_runtime/runtime.log "/Users/xuhuanlu/Desktop/nenggeProject/log/runtime_$(date +%Y%m%d%H%M%S).log"
```
