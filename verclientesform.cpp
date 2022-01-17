#include "verclientesform.h"
#include "ui_verclientesform.h"
#include "DuDefines.h"
#include "ducliente.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

VerClientesForm::VerClientesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerClientesForm)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"ID","Nombre","Direccion","Telefono"});
    setWindowTitle("Ver Clientes");
    layout()->setMargin(0);
    on_ActualizarpushButton_clicked();
}

VerClientesForm::~VerClientesForm()
{
    delete ui;
}

void VerClientesForm::on_ActualizarpushButton_clicked()
{
    ui->tableWidget->setRowCount(0);
    QFile F(CLIENTES_FILENAME);
    if(!F.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"Error4", F.errorString());
        return;
    }

    QDataStream in(&F);
    in.setVersion(QDataStream::Qt_5_9);
    DuCliente cliente;
    while(!in.atEnd()){
        in >> cliente;
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0,new QTableWidgetItem(QString::number(cliente.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(cliente.getNombre()));
        ui->tableWidget->setItem(row,2, new QTableWidgetItem(cliente.getDireccion()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(cliente.getTelefono()));

    }
    F.close();
}
