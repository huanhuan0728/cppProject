#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
    // 检查命令行参数是否传入相机索引
    if (argc < 2)
    {
        std::cerr << "用法: " << argv[0] << " <camera_index>" << std::endl;
        return -1;
    }

    // 将命令行参数转换为整数，相机索引
    int cameraIndex = std::atoi(argv[1]);

    // 打开相机
    cv::VideoCapture capture(cameraIndex);
    if (!capture.isOpened())
    {
        std::cerr << "打开相机失败" << std::endl;
        return -1;
    }

    // 创建显示窗口
    cv::namedWindow("Input frame from the camera", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Grayscale input camera", cv::WINDOW_AUTOSIZE);

    while (true)
    {
        cv::Mat frame;
        // 读取一帧
        if (!capture.read(frame))
        {
            std::cerr << "读取帧失败" << std::endl;
            break;
        }

        // 显示彩色帧
        cv::imshow("Input frame from the camera", frame);

        // 转换为灰度图像
        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // 显示灰度图像
        cv::imshow("Grayscale input camera", grayFrame);

        // 等待20ms，并检测是否按下'q'键退出
        char key = static_cast<char>(cv::waitKey(20));
        if (key == 'q' || key == 'Q')
            break;
    }

    // 释放资源
    capture.release();
    cv::destroyAllWindows();
    return 0;
}
