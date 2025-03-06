#include <opencv2/opencv.hpp>
#include <uwebsockets/App.h>
#include <iostream>

cv::CascadeClassifier face_cascade;

void detectFaces(cv::Mat &frame) {
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(frame, faces, 1.3, 5);

    for (const auto &face : faces) {
        cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
    }
}

int main() {
    if (!face_cascade.load(".../models/haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade\n";
        return -1;
    }

    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening camera\n";
        return -1;
    }

    uWS::App().ws<struct PerSocketData>("/face", {
        .message = [](auto *ws, std::string_view msg, uWS::OpCode opCode) {
            cv::Mat frame;
            cap.read(frame);
            detectFaces(frame);
            std::vector<uchar> buffer;
            cv::imencode(".jpg", frame, buffer);
            ws->send(std::string(buffer.begin(), buffer.end()), uWS::BINARY);
        }
    }).listen(9001, [](auto *token) {
        if (token) {
            std::cout << "WebSocket server running on ws://localhost:9001\n";
        }
    }).run();

    return 0;
}
