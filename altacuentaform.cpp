#include "altacuentaform.h"
#include "ui_altacuentaform.h"
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include "DuDefines.h"
#include "ducuenta.h"
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include "ducliente.h"


AltaCuentaForm::AltaCuentaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AltaCuentaForm)
{
    ui->setupUi(this);
    mIdSpinBox = new QSpinBox(this);
    mIdClienteSpinBox = new QSpinBox(this);
    mSaldoSpinBox = new QDoubleSpinBox(this);
    mLayout = new QVBoxLayout;


    auto formLayout1 = new QFormLayout;
    auto formLayout2 = new QFormLayout;
    auto formLayout3 = new QFormLayout;

    formLayout1->addRow("ID", mIdSpinBox);
    formLayout2->addRow("ID CLIENTE", mIdClienteSpinBox);
    formLayout3->addRow("SALDO",mSaldoSpinBox);

    mLayout->addLayout(formLayout1);
    mLayout->addLayout(formLayout2);
    mLayout->addLayout(formLayout3);
    ui->widget->setLayout(mLayout);
    mIdSpinBox->setMaximum(INT_MAX);
    mIdClienteSpinBox->setMaximum(INT_MAX);
    mSaldoSpinBox->setMaximum(999999999999.9);
    mSaldoSpinBox->setMinimum(0.0);
    setWindowTitle("Alta Cuenta");
}

AltaCuentaForm::~AltaCuentaForm()
{
    delete ui;
}

void AltaCuentaForm::on_AltapushButton_clicked(){
    QFile F(CUENTAS_FILENAME);
    if(!F.open(QIODevice::WriteOnly | QIODevice::Append)){
        QMessageBox::critical(this,"Error1",F.errorString());
        return;
    }
    QDataStream out(&F);
    out.setVersion(QDataStream::Qt_5_9);
    const int id = mIdSpinBox->value();
    if(isInside(id)){
        QMessageBox::warning(this, "Aviso", "ID REPETIDO");
        return;
    }
    const int idCliente = mIdClienteSpinBox->value();
    DuCliente cliente(idCliente);
    if(!cliente.isInside(idCliente)){
        QMessageBox::warning(this, "Aviso", "No existe el id del cliente");
        return;
    }
    DuCuenta cuenta(id, mIdClienteSpinBox->value(), mSaldoSpinBox->value());
    out << cuenta;
    F.flush();
    F.close();
    QMessageBox::information(this,"OK","Correcto");
    mIdSpinBox->clear();
    mIdClienteSpinBox->clear();
    mSaldoSpinBox->clear();
    mIdSpinBox->setFocus();
}

bool AltaCuentaForm::isInside(int id) const{
    QFile F(CUENTAS_FILENAME);
    if(!F.open(QIODevice::ReadOnly)){
       return false;
    }
    QDataStream in(&F);
    in.setVersion(QDataStream::Qt_5_9);

    while(!in.atEnd()){
        DuCuenta cuenta;
        in >> cuenta;
        if(cuenta.id() == id){
            return true;
        }
    }
    F.close();

    return false;

}
