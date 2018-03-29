//
// Created by tekatod on 3/29/18.
//

#include <iostream>
#include "camera.h"

void camera::camera_choosed(const QCameraInfo& info, QCameraViewfinder* finder, QCameraImageCapture* image_capture) {
    this->set_up_camera(info, finder, image_capture);
}

void camera::set_up_camera(const QCameraInfo& info, QCameraViewfinder* finder, QCameraImageCapture* image_capture) {
    this->tear_down_camera();
    m_qcamera = new QCamera(info);
    m_qcamera->setViewfinder(finder);
    m_resolutions = m_qcamera->supportedViewfinderResolutions();
    image_capture = new QCameraImageCapture(m_qcamera);
    m_qcamera->setCaptureMode(QCamera::CaptureStillImage);
    image_capture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);
    m_focus = m_qcamera->focus();
    m_exposure = m_qcamera->exposure();
    m_max_zoom = m_focus->maximumDigitalZoom();
    m_qcamera->start();
    m_exposure->setAutoAperture();
    emit camera_ready();
}

qreal camera::get_max_frame_rate() const {
    return m_max_frame_rate;
}

qreal camera::get_min_frame_rate() const {
    return m_min_frame_rate;
}

const QList<QSize>& camera::get_resolutions() const {
    return m_resolutions;
}

camera::~camera() {
    this->tear_down_camera();
}

void camera::tear_down_camera() {
    if(m_qcamera) {
        if (m_qcamera->state() == QCamera::ActiveState) {
            m_qcamera->stop();
        }
        if (m_qcamera->state() == QCamera::LoadedState) {
            m_qcamera->unload();
        }
    }
}

qreal camera::get_max_zoom() const {
    return m_max_zoom;
}

void camera::change_zoom(int zoom) {
    if(m_focus) {
        m_focus->zoomTo(0, (qreal)zoom);
    }
}
