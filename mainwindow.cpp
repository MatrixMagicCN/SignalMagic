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
#include <QAreaSeries>
#include <QLineSeries>
#include <QtCharts>
#include <QtDebug>

#include "./ui_mainwindow.h"

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

  targetRect->setPen(QPen(Qt::red, 5));
  targetRect->setRect(-130, 30, 100, 100);
  scene->addItem(targetRect);
  QGraphicsTextItem *bus = new QGraphicsTextItem;
  bus->setPlainText("Bus");
  bus->setDefaultTextColor(QColor("red"));
  bus->setFont(QFont("Source Code Pro", 20));
  bus->setPos(-110, -20);
  scene->addItem(bus);

  QGraphicsTextItem *car = new QGraphicsTextItem;
  car->setPlainText("Car");
  car->setDefaultTextColor(QColor("red"));
  car->setFont(QFont("Source Code Pro", 20));
  car->setPos(150, 100);
  scene->addItem(car);
  QGraphicsRectItem *carRect = new QGraphicsRectItem;
  carRect->setPen(QPen(Qt::red, 5));
  carRect->setRect(120, 150, 150, 150);
  scene->addItem(carRect);

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
  /*Charts */

  QLineSeries *series = new QLineSeries();
  series->append(0, 0);
  series->append(1, 1);
  series->append(2, 2);
  series->append(3, 3);
  series->append(4, 4);
  series->append(5, 5);
  series->append(6, 6);
  *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6)
          << QPointF(18, 3) << QPointF(20, 2);
  QChart *chart = new QChart();
  chart->setTitle("Image Information");
  chart->addSeries(series);
  chart->legend()->hide();
  chart->createDefaultAxes();
  chart->setPos(500, 000);
  chart->resize(400, 400);
  scene->addItem(chart);

  QLineSeries *series0 = new QLineSeries();
  QLineSeries *series1 = new QLineSeries();
  *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7)
           << QPointF(12, 6) << QPointF(16, 7) << QPointF(18, 5);
  *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2)
           << QPointF(12, 3) << QPointF(16, 4) << QPointF(18, 3);

  QAreaSeries *seriesA = new QAreaSeries(series0, series1);
  seriesA->setName("Batman");
  QPen pen(0x059605);
  pen.setWidth(3);
  seriesA->setPen(pen);
  QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
  gradient.setColorAt(0.0, 0x3cc63c);
  gradient.setColorAt(1.0, 0x26f626);
  gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
  seriesA->setBrush(gradient);

  QChart *chartA = new QChart();
  chartA->addSeries(seriesA);
  chartA->setTitle("Image areachart");
  chartA->createDefaultAxes();
  chartA->axes(Qt::Horizontal).first()->setRange(0, 20);
  chartA->axes(Qt::Vertical).first()->setRange(0, 10);
  chartA->legend()->hide();
  chartA->setPos(500, -400);
  chartA->resize(400, 400);
  scene->addItem(chartA);

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

void MainWindow::resizeEvent(QResizeEvent *event) {
  qDebug() << "resize.\n";
  qDebug() << this->width();
  qDebug() << this->height();
  qDebug() << ui->graphicsView->width();
  qDebug() << ui->graphicsView->height();
}
