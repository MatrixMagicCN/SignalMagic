#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QImage>
#include <QtDebug>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QImage image;
//    qDebug() << image.load(":/pic/SignalMagic_logo.png");
//    qDebug() << image.format();
//    qDebug() << image.size();
    QPixmap pixmap(":/pic/SignalMagic_logo.png");
    QSplashScreen splash(pixmap,Qt::WindowStaysOnTopHint);
    splash.show();
    a.processEvents();
//    splash.finish(&w);
    MainWindow w;
    w.show();
    return a.exec();
}
