//
// Created by tekatod on 3/29/18.
//

#pragma once


#include <QtCore/QObject>
#include <QtMultimedia/QCamera>
#include <QtWidgets/QComboBox>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimedia/QCameraImageCapture>

class camera : public QObject {
    Q_OBJECT
public:
    camera() = default;

public slots:
    void camera_choosed(const QCameraInfo&, QCameraViewfinder*, QCameraImageCapture*);
    void change_zoom(int);


signals:
    void camera_ready();

private:
    void set_up_camera(const QCameraInfo& info, QCameraViewfinder* finder, QCameraImageCapture*);

    void tear_down_camera();

private:
    QCamera* m_qcamera;
    qreal m_max_frame_rate;
    qreal m_min_frame_rate;
    QList<QSize> m_resolutions;
    QCameraFocus* m_focus;
    QCameraExposure* m_exposure;
    qreal m_max_zoom;
public:
    qreal get_max_zoom() const;

public:
    qreal get_max_frame_rate() const;

    qreal get_min_frame_rate() const;

    const QList<QSize>& get_resolutions() const;

    ~camera();
};
