##

    os.getcwa() 获取python代码运行的当前目录

    output_path = os.path.join(os.getcwd(), "detection_result.jpg")路径拼接

    cv2.imwrite(output_path, res)   将图像写入文件
