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
//#include <QList>
//#include <QPainter>
#include <QPen>
//#include <QStyleOptionGraphicsItem>
#include <QAreaSeries>
//#include <QChart>
#include <QGraphicsWidget>
#include <QLineSeries>
#include <QtCharts>
#include <QtDebug>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      scene(new QGraphicsScene),
      backGround(new QGraphicsPixmapItem),
      frontEnd(new QGraphicsPixmapItem),
      infoText(new QGraphicsTextItem),
      targetRect(new QGraphicsRectItem),
      backPixmap(new QPixmap),
      frontPixmap(new QPixmap),
      //      chartA(new QChart),
      //      chartB(new QGraphicsWidget),
      itemList(new QList<QGraphicsItem *>) {
  ui->setupUi(this);
  //  scene->setSceneRect(-800,-400,1600,800);
  backPixmap->load(":/pic/back_SignalMagic_logo.png");
  frontPixmap->load(":/pic/test.jpg");
  ui->graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  //  ui->graphicsView->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
  //  qDebug() << ui->graphicsView->mapFromScene(0, 0);
  //  qDebug() << ui->graphicsView->mapToScene(0, 0);
  //  qDebug() << "front width:" << frontPixmap->width();
  //  qDebug() << "front height:" << frontPixmap->height();
  //  qDebug() << "back width:" << backPixmap->width();
  //  qDebug() << "back height:" << backPixmap->height();

  ui->graphicsView->setScene(scene);
  backGround->setPixmap(*backPixmap);
  frontEnd->setPixmap(*frontPixmap);
  scene->addItem(backGround);
  scene->addItem(frontEnd);

  infoText->setPlainText("HELLO WORLD.\nThis is a example.\n");
  infoText->setDefaultTextColor(QColor("red"));
  infoText->setFont(QFont("Source Code Pro", 15));
  //  infoText->setPos(0, 0);
  scene->addItem(infoText);
  /*
    targetRect->setPen(QPen(Qt::red, 5));
    //  targetRect->setRect(-130, 30, 100, 100);
    scene->addItem(targetRect);
    QGraphicsTextItem *bus = new QGraphicsTextItem;
    bus->setPlainText("Bus");
    bus->setDefaultTextColor(QColor("red"));
    bus->setFont(QFont("Source Code Pro", 20));
    //  bus->setPos(-110, -20);
    scene->addItem(bus);

    QGraphicsTextItem *car = new QGraphicsTextItem;
    car->setPlainText("Car");
    car->setDefaultTextColor(QColor("red"));
    car->setFont(QFont("Source Code Pro", 20));
    //  car->setPos(150, 100);
    scene->addItem(car);
    QGraphicsRectItem *carRect = new QGraphicsRectItem;
    carRect->setPen(QPen(Qt::red, 5));
    //  carRect->setRect(120, 150, 150, 150);
    scene->addItem(carRect);
  */
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

  QChart *tempChart = new QChart();
  //  chartLine = static_cast<QChart *>(chartLine);
  chartLine = tempChart;
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
  tempChart->setTitle("Image Information");
  tempChart->addSeries(series);
  tempChart->legend()->hide();
  tempChart->createDefaultAxes();
  tempChart->setPos(700, 0);
  tempChart->resize(400, 400);
  scene->addItem(tempChart);

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

  tempChart = new QChart();
  chartArea = tempChart;
  tempChart->addSeries(seriesA);
  tempChart->setTitle("Image areachart");
  tempChart->createDefaultAxes();
  tempChart->axes(Qt::Horizontal).first()->setRange(0, 20);
  tempChart->axes(Qt::Vertical).first()->setRange(0, 10);
  tempChart->legend()->hide();
  tempChart->setPos(700, 400);
  tempChart->resize(400, 400);
  scene->addItem(tempChart);

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
  //  qDebug() << "resize.\n";
  //  qDebug() << this->width();
  //  qDebug() << this->height();
  //  qDebug() << event->size().width();
  //  qDebug() << event->size().height();
  //  qDebug() << "graphicsView:" << ui->graphicsView->width();
  //  qDebug() << "graphicsView:" << ui->graphicsView->height();
  //  qDebug() << "cent:" << ui->centralwidget->width();
  //  qDebug() << "cent:" << ui->centralwidget->height();
  //  qDebug() << "scene:" << scene->width();
  //  qDebug() << "scene:" << scene->height();
  int width = (ui->graphicsView->width() - backPixmap->width()) / 2;
  int height = (ui->graphicsView->height() - backPixmap->height()) / 2;
  //  qDebug() << width;
  //  qDebug() << height;
  if (width < 0) width = 0;
  if (height < 0) height = 0;
  backGround->setPos(width, height);
  width = (ui->graphicsView->width() - frontPixmap->width()) / 2;
  height = (ui->graphicsView->height() - frontPixmap->height()) / 2;
  //  qDebug() << width;
  //  qDebug() << height;

  if (width < 0) width = 0;
  if (height < 0) height = 0;
  frontEnd->setPos(width, height);

  width = ui->graphicsView->width() - 400;
  height = 0;
  if (width < 0) width = 0;
  //  qDebug() << ui->graphicsView->height() - 400;
  chartLine->setPos(width, height);

  width = ui->graphicsView->width() - 400;
  height = 400;
  if (width < 0) width = 0;
  //  qDebug() << ui->graphicsView->height() - 400;
  chartArea->setPos(width, height);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  //  qDebug() << "Mouse Press Event.";
  //  qDebug() << event->pos();
  //  qDebug() << event->x();
  //  qDebug() << event->y();
  //  qDebug() << event->screenPos();
}
