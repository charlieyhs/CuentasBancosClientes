#include "vercuentasform.h"
#include "ui_vercuentasform.h"
#include "ducuenta.h"
#include <QFile>
#include <QDataStream>
#include "DuDefines.h"
#include <QMessageBox>

VerCuentasForm::VerCuentasForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerCuentasForm)
{
    ui->setupUi(this);
    layout()->setMargin(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"ID","Id Cliente","Saldo"});
    setWindowTitle("Ver Cuentas");
    on_ActualizarpushButton_clicked();

}

VerCuentasForm::~VerCuentasForm()
{
    delete ui;
}

void VerCuentasForm::on_ActualizarpushButton_clicked()
{
    ui->tableWidget->setRowCount(0);
    QFile F(CUENTAS_FILENAME);
    if(!F.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error2", F.errorString());
    }
    QDataStream in(&F);
    in.setVersion(QDataStream::Qt_5_9);
    DuCuenta cuenta;
    while(!F.atEnd()){
        in >> cuenta;
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0, new QTableWidgetItem(QString::number(cuenta.id())));
        ui->tableWidget->setItem(row,1, new QTableWidgetItem(QString::number(cuenta.idCliente())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(cuenta.saldo())));
    }
    F.close();
}
