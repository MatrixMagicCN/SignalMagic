#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QImage>
#include <QtDebug>
#include <QString>
#include <QTime>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w;
    {
    QPixmap *pixmap=new QPixmap(":/pic/SignalMagic_logo.png");
    QSplashScreen *splash=new QSplashScreen(*pixmap,Qt::WindowStaysOnTopHint);
    splash->show();
    a.processEvents();
    w=new MainWindow;
    w->show();
    QTime cutime=QTime::currentTime();
    while(QTime::currentTime()<cutime.addSecs(2));
    splash->finish(w);
    delete splash;
    delete pixmap;
    }
    return a.exec();
}
