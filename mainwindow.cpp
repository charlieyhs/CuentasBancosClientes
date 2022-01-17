#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include "altaclienteform.h"
#include "altacuentaform.h"
#include "verclientesform.h"
#include "vercuentasform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAlta_de_Clientes_triggered(){
    loadSubWindow(new AltaClienteForm(this));
}

void MainWindow::on_actionAlta_de_Cuentas_triggered(){
    loadSubWindow(new AltaCuentaForm(this));
}

void MainWindow::on_actionVer_Clientes_triggered(){
    loadSubWindow(new VerClientesForm(this));
}

void MainWindow::on_actionVer_Cuentas_triggered(){
    loadSubWindow(new VerCuentasForm(this));
}

void MainWindow::on_actionSalir_triggered(){
    close();
}

void MainWindow::loadSubWindow(QWidget *widget){
    int x,y,w,h;
    x = geometry().x()/2;
    y = geometry().y()/2;
    w = widget->sizeHint().width()+30;
    h = widget->sizeHint().height()+30;

    auto window = ui->mdiArea->addSubWindow(widget);
    window->setWindowTitle(widget->windowTitle());
    window->setWindowIcon(widget->windowIcon());
    window->setGeometry(x,y,w,h);
    window->show();
}
