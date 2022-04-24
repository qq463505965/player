#ifndef TIMELINE_H
#define TIMELINE_H

#include <QObject>
#include <QWidget>
#include <QBoxLayout>
#include <QPainter>
#include <QLineEdit>
#include <QToolButton>
#include <QSpacerItem>
#include <QLayout>
#include <QLabel>
#include <QComboBox>
#include <QFrame>

#include "sonic_panel.h"
#include "sonic_waveform.h"
#include "functions.h"


class timeline: public QWidget
{
    Q_OBJECT
public:
    timeline();
    ~timeline()= default;


    QLineEdit *current_moment = nullptr;
    QSpacerItem *spacer = nullptr;
    QLabel *zoom = nullptr;
    QComboBox *zoom_box = nullptr;
    QHBoxLayout *h_layout = nullptr;
    QVBoxLayout *v_layout = nullptr;

    sonic_panel *sonic_panel_frame = nullptr;

    sonic_waveform *sonic_waveform_frame = nullptr;

    QSlider *slider = nullptr;

    void resizeEvent(QResizeEvent *event);
    void nothing();

    qint16 sonic_waveform_width = 1;
    qint16 sonic_waveform_height = 1;
signals:
    void send_info_to_sonic_waveform_frame(qint16 x, qint16 y, qint16 w, qint16 h);

public slots:
    void generate_pcm_slot(QString video_filename);
    void generate_pixmaps_slot(QString pcm_filename);

private:


};

#endif // TIMELINE_H
