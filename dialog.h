#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QScreen>
#include <QPixmap>
#include <QLabel>
#include <QApplication>
#include <QTimer>
#include <QRect>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QTimer timer;
    QLabel *label = new QLabel(this);

private slots:
    void updatelabel();
};
#endif // DIALOG_H
