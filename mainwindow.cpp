#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qtosgwidget.h"
#include "osghud.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QtOSGWidget* qOsg = new QtOSGWidget(1,1,this);
    qOsg->addHud(createHud());
    ui->setupUi(this);
    ui->verticalLayout->addWidget(qOsg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
