#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logmodelextended.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    logs = new LogModelExtended(this);
    ui->treeView->setModel(logs);
    logs->addStandardMessage(trUtf8("Prowerka Info"),1,0);
    logs->addStandardMessage(trUtf8("Проверка Warning"),1,1);
    logs->addStandardMessage(trUtf8("Проверка Error"),1,2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
