#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtContainerFwd>
//#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class QGraphicsPixmapItem;
class QGraphicsItem;
class QPixmap;
class QGraphicsTextItem;
class QGraphicsRectItem;
// class QGraphicsTextItem;
// template<typename T> class QList;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   protected:
    void resizeEvent(QResizeEvent *event) override;

   private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *backGround;
    QGraphicsPixmapItem *frontEnd;
    QGraphicsTextItem *infoText;
    QGraphicsRectItem *targetRect;
    QPixmap *backPixmap;
    QPixmap *frontPixmap;
    QList<QGraphicsItem *> *itemList;

//    QGraphicsTextItem *sceneText;
};
#endif // MAINWINDOW_H
