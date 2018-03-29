//
// Created by tekatod on 3/29/18.
//


#include <QtWidgets/QLayout>
#include <iostream>
#include "camera_i.h"

camera_i::camera_i(QWidget* parent) : QWidget(parent), m_camera() {
    this->setWindowTitle("camera");
    m_combo_box = new QComboBox();
    m_resolutions_box= new QComboBox();
    m_view_finder = new QCameraViewfinder(this);
    m_cap_button = new QPushButton("capture");
    m_zoom_slider = new QSlider(Qt::Horizontal);
    auto* layout1 = new QGridLayout;
    layout1->addWidget(m_combo_box);
    layout1->addWidget(m_resolutions_box);
    layout1->addWidget(m_view_finder);
    layout1->addWidget(m_cap_button);
    layout1->addWidget(m_zoom_slider);
    this->setLayout(layout1);
    QObject::connect(this, SIGNAL(camera_choose(const QCameraInfo&, QCameraViewfinder*, QCameraImageCapture*)),
                     &m_camera, SLOT(camera_choosed(const QCameraInfo&, QCameraViewfinder*, QCameraImageCapture*)));
    QObject::connect(m_combo_box, SIGNAL(currentIndexChanged(int)),
                     this, SLOT(combo_box_change(int)));
    QObject::connect(&m_camera, SIGNAL(camera_ready()), this, SLOT(camera_changed()));
    QObject::connect(m_zoom_slider, SIGNAL(valueChanged(int)), &m_camera, SLOT(change_zoom(int)));
    m_cameras = QCameraInfo::availableCameras();
    for(auto&& info : m_cameras) {
        m_combo_box->addItem(info.deviceName());
    }
    if(!m_cameras.empty()) {
        emit camera_choose(m_cameras.first(), m_view_finder, m_image_capture);
    }
}

void camera_i::combo_box_change(int i) {
        emit camera_choose(m_cameras[i], m_view_finder, m_image_capture);
}

void camera_i::camera_changed() {
    m_resolutions_box->clear();
    auto& resolutions = m_camera.get_resolutions();
    for(auto&& r : resolutions) {
        m_resolutions_box->addItem(QString(r.width() + " x " + r.height()));
    }
}