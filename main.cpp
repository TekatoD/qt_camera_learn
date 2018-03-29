#include <iostream>
#include <QtMultimedia/QCameraInfo>
#include <QtWidgets/QApplication>
#include "camera.h"
#include "camera_i.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    camera_i cam_i;
    cam_i.show();
    return app.exec();
}