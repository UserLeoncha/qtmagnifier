#include "dialog.h"

#define window_width
#define window_height
#define widget_width
#define widget_height

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //slots
    connect(&timer, SIGNAL(timeout()), this, SLOT(updatelabel()));
    timer.start(5);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    label->resize(640, 480);

}

Dialog::~Dialog() {

}

void Dialog::updatelabel() {
    QScreen *screen = QGuiApplication::primaryScreen();
    if (QScreen *primaryScreen = QGuiApplication::primaryScreen()) {
        screen = primaryScreen;
    }
    QRect captureRect(640, 300, 640, 480);
    QPixmap originalPixmap = screen->grabWindow(0, captureRect.x(), captureRect.y(), captureRect.width(), captureRect.height());
    label->setPixmap(originalPixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
