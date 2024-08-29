#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
int main(int argc, char **argv)
{
    // 检查命令行参数
    if (argc != 2)
    {
        std::cout << "Usage: ./display_image <image_path>" << std::endl;
        return -1;
    }

    // 读取图像
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_COLOR);

    // 检查是否成功读取图像
    if (image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // 创建窗口并显示图像
    cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
    cv::imshow("Display Image", image);

    // 等待用户按键后关闭窗口
    cv::waitKey(0);

    return 0;
}