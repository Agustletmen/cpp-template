#include<iostream>
#include<libavcodec/avcodec.h>
#include<libavdevice/avdevice.h>
#include<libavfilter/avfilter.h>
#include<libavformat/avformat.h>
#include<libavutil/avutil.h>
#include<libswscale/swscale.h>

#include <opencv2/opencv.hpp>



using namespace cv;
using namespace std;

// 全局变量：人脸分类器（提前加载，避免重复初始化）
CascadeClassifier face_cascade;

/**
 * @brief 初始化人脸分类器
 * @param cascade_path Haar 分类器模型路径
 * @return 初始化成功返回 true，失败返回 false
 */
bool initFaceDetector(const string& cascade_path) {
    // 加载分类器模型
    if (!face_cascade.load(cascade_path)) {
        cerr << "[ERROR] Failed to load face cascade model: " << cascade_path << endl;
        cerr << "Please check the path of 'haarcascade_frontalface_default.xml'" << endl;
        return false;
    }
    cout << "[INFO] Face detector initialized successfully!" << endl;
    return true;
}

/**
 * @brief 打开摄像头并实时人脸识别
 * @param camera_index 摄像头索引（0=默认摄像头）
 * @param width 分辨率宽度
 * @param height 分辨率高度
 */
void openCameraWithFaceDetection(int camera_index = 0, int width = 1280, int height = 720) {
    // 1. 打开摄像头
    VideoCapture cap;
#ifdef _WIN32
    cap.open(camera_index, CAP_DSHOW);  // Windows 降低延迟
#else
    cap.open(camera_index);
#endif

    if (!cap.isOpened()) {
        cerr << "[ERROR] Failed to open camera (index: " << camera_index << ")" << endl;
        return;
    }

    // 2. 配置摄像头参数
    cap.set(CAP_PROP_FRAME_WIDTH, width);
    cap.set(CAP_PROP_FRAME_HEIGHT, height);
    cap.set(CAP_PROP_BUFFERSIZE, 1);  // 降低延迟

    int actual_w = cap.get(CAP_PROP_FRAME_WIDTH);
    int actual_h = cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "[INFO] Camera resolution: " << actual_w << "x" << actual_h << endl;
    cout << "[INFO] Usage: Press 'q'/ESC to exit, 's' to save frame" << endl;

    // 3. 实时处理帧
    Mat frame, gray_frame;
    vector<Rect> faces;  // 存储检测到的人脸矩形（x, y, width, height）

    while (true) {
        // 读取一帧
        bool ret = cap.read(frame);
        if (!ret) {
            cerr << "[WARNING] Failed to read frame" << endl;
            break;
        }

        // 4. 预处理：转换为灰度图（人脸检测对灰度图更高效）
        cvtColor(frame, gray_frame, COLOR_BGR2GRAY);
        equalizeHist(gray_frame, gray_frame);  // 直方图均衡化，增强对比度（提高检测准确率）

        // 5. 人脸检测
        face_cascade.detectMultiScale(
            gray_frame,          // 输入灰度图
            faces,               // 输出检测到的人脸矩形
            1.1,                 // 缩放因子（每次缩小10%）
            3,                   // 相邻检测阈值（多次检测确认才视为人脸）
            0 | CASCADE_SCALE_IMAGE,  // 检测标志
            Size(30, 30)         // 最小人脸尺寸（小于此尺寸不检测）
        );

        // 6. 标注人脸：在原帧中画矩形和文字
        for (size_t i = 0; i < faces.size(); ++i) {
            Rect face = faces[i];
            // 画矩形框（绿色，线条粗细2）
            rectangle(
                frame,
                face,
                Scalar(0, 255, 0),  // BGR：绿色
                2
            );
            // 标注文字“Face + 序号”（红色，字体大小0.8）
            string face_text = "Face " + to_string(i + 1);
            putText(
                frame,
                face_text,
                Point(face.x, face.y - 10),  // 文字在矩形上方
                FONT_HERSHEY_SIMPLEX,
                0.8,
                Scalar(0, 0, 255),  // BGR：红色
                2
            );
        }

        // 显示检测到的人脸数量
        string count_text = "Detected Faces: " + to_string(faces.size());
        putText(
            frame,
            count_text,
            Point(10, 30),
            FONT_HERSHEY_SIMPLEX,
            0.8,
            Scalar(255, 0, 0),  // BGR：蓝色
            2
        );

        // 显示画面
        imshow("OpenCV Camera + Face Detection", frame);

        // 键盘事件
        int key = waitKey(1) & 0xFF;
        if (key == 'q' || key == 27) {
            cout << "[INFO] Exiting program..." << endl;
            break;
        } else if (key == 's') {
            string save_path = "face_detection_frame_" + to_string(time(nullptr)) + ".jpg";
            imwrite(save_path, frame);
            cout << "[INFO] Frame saved to: " << save_path << endl;
        }
    }

    // 释放资源
    cap.release();
    destroyAllWindows();
}

int main() {
    // 关键：指定 Haar 分类器模型路径（根据实际路径修改！）
    string cascade_path = "haarcascade_frontalface_default.xml";  // 若模型在项目根目录
    // 若模型在 OpenCV 安装目录，示例路径（Windows）：
    // string cascade_path = "C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml";
    // 示例路径（Linux）：
    // string cascade_path = "/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";

    // 初始化人脸检测器
    if (!initFaceDetector(cascade_path)) {
        return 1;  // 初始化失败，退出程序
    }

    // 打开摄像头并做人脸识别
    openCameraWithFaceDetection(0, 1280, 720);

    return 0;
}
