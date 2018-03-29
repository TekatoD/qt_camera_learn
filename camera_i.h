//
// Created by tekatod on 3/29/18.
//

#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QComboBox>
#include <QtMultimedia/QCameraInfo>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimedia/QCameraImageCapture>
#include <QtWidgets/QPushButton>
#include "camera.h"

class camera_i : public QWidget {
    Q_OBJECT
public:
    explicit camera_i(QWidget* parent = 0);

public slots:
    void combo_box_change(int);
    void camera_changed();

signals:
    void camera_choose(const QCameraInfo&, QCameraViewfinder*, QCameraImageCapture*);



private:
    QList<QCameraInfo> m_cameras;
    QComboBox* m_combo_box;
    QComboBox* m_resolutions_box;
    camera m_camera;
    QCameraViewfinder* m_view_finder;
    QCameraImageCapture* m_image_capture;
    QPushButton* m_cap_button;
    QSlider* m_zoom_slider;
};

