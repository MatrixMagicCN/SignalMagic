#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), scene(new QGraphicsScene) {
  ui->setupUi(this);
  ui->graphicsView->setScene(scene);
  scene->addText("HELLO WORLD.");
  scene->addRect(-50, -50, 100, 100);
  scene->addEllipse(-5, -5, 10, 10);
  scene->update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

