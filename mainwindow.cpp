#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QColor>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QStyleOptionGraphicsItem>
//#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene),backGround(new QGraphicsPixmapItem),frontEnd(new QGraphicsPixmapItem),infoText(new QGraphicsTextItem),targetRect(new QGraphicsRectItem), backPixmap(new QPixmap),frontPixmap(new QPixmap),itemList(new QList<QGraphicsItem*>)
{
  ui->setupUi(this);
  scene->setSceneRect(-800,-400,1600,800);
  backPixmap->load(":/pic/back_SignalMagic_logo.png");
  frontPixmap->load(":/pic/test.jpg");
  ui->graphicsView->setScene(scene);
//  ui->graphicsView->setAlignment(Qt::AlignLeft|Qt::AlignTop);
  ui->graphicsView->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  backGround->setPixmap(*backPixmap);
  backGround->setPos(-800,-400);
  frontEnd->setPixmap(*frontPixmap);
  frontEnd->setPos(-512,-384);
  scene->addItem(backGround);
//  scene->addEllipse(-25, -25, 50, 50);
  scene->addItem(frontEnd);
//  scene->addRect(-50, -50, 100, 100);

  infoText->setPlainText("HELLO WORLD.\nThis is a example.\n");
  infoText->setDefaultTextColor(QColor("black"));
//  QFont
  infoText->setPos(-900,-400);
  scene->addItem(infoText);
  targetRect->setRect(-50,-50,100,100);
//  QPen pen(QBrush(QColor("red")),10);
//  rectPainer->begin();
//  rectPainer->setPen(QPen(QBrush(QColor("red")),10));
//  rectPainer->drawRect(-50,-50,100,100);
//  QStyleOptionGraphicsItem optionGraphicsItem;
//  targetRect->paint(rectPainer,&optionGraphicsItem);
  scene->addItem(targetRect);
//  scene->addText("HELLO WORLD.");
//  qDebug()<< ui->graphicsView->sceneRect();
//  *itemList=scene->items();
//  qDebug()<<itemList->first()->scenePos();
//  qDebug()<< ui->graphicsView->mapToScene(0,0);
//  itemList->first()->setPos(ui->graphicsView->mapToScene(-800,-400));
//  qDebug()<< scene->sceneRect();
//  qDebug()<< ui->graphicsView->alignment();
//  qDebug()<< ui->graphicsView->sceneRect();
//  qDebug()<< ui->graphicsView->size();
  scene->update();
}

MainWindow::~MainWindow()
{
//    delete sceneText;
    delete itemList;
    delete backGround;
    delete scene;
    delete backPixmap;
    delete frontEnd;
    delete frontPixmap;
    delete ui;
}

