#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene),background(new QGraphicsPixmapItem), backPixmap(new QPixmap){
  ui->setupUi(this);
  backPixmap->load(":/pic/back_SignalMagic_logo.png");
  ui->graphicsView->setScene(scene);
  background->setPixmap(*backPixmap);
  background->setOffset(-400,-300);
  scene->addItem(background);
  scene->addText("HELLO WORLD.");
  scene->addRect(-50, -50, 100, 100);
  scene->addEllipse(-5, -5, 10, 10);
  scene->update();
}

MainWindow::~MainWindow()
{
    delete background;
    delete scene;
    delete backPixmap;
    delete ui;
}

