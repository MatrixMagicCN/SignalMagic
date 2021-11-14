#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QImage>
#include <QtDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QImage image("SignalMagic_logo.png");
    QImage image;
    qDebug() << image.load("test.jpg");
    qDebug() << image.format();
    qDebug() << image.size();
    MainWindow w;
    w.show();
    return a.exec();
}
