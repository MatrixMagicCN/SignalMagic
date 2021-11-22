#include "mainwindow.h"

#include <QBrush>
#include <QColor>
#include <QFont>
//#include <QFormLayout>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
//#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
//#include <QGroupBox>
//#include <QLabel>
//#include <QLineEdit>
#include <QList>
//#include <QPainter>
#include <QPen>
//#include <QStyleOptionGraphicsItem>

#include "./ui_mainwindow.h"
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
  infoText->setDefaultTextColor(QColor("red"));
  infoText->setFont(QFont("Source Code Pro",20));
//  QFont
  infoText->setPos(-900,-400);
  scene->addItem(infoText);
  targetRect->setPen(QPen(Qt::red,5));
  targetRect->setRect(-50,-50,100,100);
  scene->addItem(targetRect);

  /*QGraphicsProxyWidget                               */
  //  QGroupBox *groupBox = new QGroupBox("Contact Details");
  //  QLabel *numberLabel = new QLabel("Telephone number");
  //  QLineEdit *numberEdit = new QLineEdit;

  //  QFormLayout *layout = new QFormLayout;
  //  layout->addRow(numberLabel, numberEdit);
  //  groupBox->setLayout(layout);
  //  QGraphicsProxyWidget *proxy = scene->addWidget(groupBox);
  /*                               */
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

