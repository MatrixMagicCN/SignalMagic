#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QChart>
#include <QMainWindow>
//#include <QtCharts>
#include <QtContainerFwd>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class QGraphicsPixmapItem;
class QGraphicsItem;
class QPixmap;
class QGraphicsTextItem;
class QGraphicsRectItem;
class QGraphicsWidget;
// class QChart;
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
    Ui::MainWindow *ui = nullptr;
    QGraphicsScene *scene = nullptr;
    QGraphicsPixmapItem *backGround = nullptr;
    QGraphicsPixmapItem *frontEnd = nullptr;
    QGraphicsTextItem *infoText = nullptr;
    QGraphicsRectItem *targetRect = nullptr;
    QPixmap *backPixmap = nullptr;
    QPixmap *frontPixmap = nullptr;
    QGraphicsWidget *chartLine = nullptr;
    QGraphicsWidget *chartArea = nullptr;
    QList<QGraphicsItem *> *itemList = nullptr;

    //    QGraphicsTextItem *sceneText;
};
#endif // MAINWINDOW_H
