#include "altaclienteform.h"
#include "ui_altaclienteform.h"
#include "dulineedit.h"
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QFile>
#include <QDataStream>
#include <ducliente.h>
#include "DuDefines.h"
#include <QMessageBox>

AltaClienteForm::AltaClienteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AltaClienteForm)
{
    ui->setupUi(this);
    mIdSpinBox = new QSpinBox(this);
    mNombreLineEdit = new DuLineEdit(QIcon(":/clear"),this);
    mDireccionLineEdit = new DuLineEdit(QIcon(":/clear"),this);
    mTelefonoLineEdit = new DuLineEdit(QIcon(":/clear"),this);
    mLayout = new QVBoxLayout;

    auto formLayout = new QFormLayout;
    auto hbox1 = new QHBoxLayout;
    auto hbox2 = new QHBoxLayout;
    auto hbox3 = new QHBoxLayout;

    formLayout->addRow("ID",mIdSpinBox);

    hbox1->addWidget(new QLabel("Nombre",this));
    hbox1->addWidget(mNombreLineEdit);

    hbox2->addWidget(new QLabel("Direccion",this));
    hbox2->addWidget(mDireccionLineEdit);

    hbox3->addWidget(new QLabel("Telefono",this));
    hbox3->addWidget(mTelefonoLineEdit);

    mLayout->addLayout(formLayout);
    mLayout->addLayout(hbox1);
    mLayout->addLayout(hbox2);
    mLayout->addLayout(hbox3);

    ui->widget->setLayout(mLayout);
    mIdSpinBox->setMaximum(INT_MAX);
    setWindowTitle("Alta Cliente");
}

AltaClienteForm::~AltaClienteForm()
{
    delete ui;
}

void AltaClienteForm::on_AltapushButton_clicked(){//da de alta
    QFile F(CLIENTES_FILENAME);

    if(!F.open(QIODevice::WriteOnly | QIODevice::Append)){
        QMessageBox::critical(this,"Error3",F.errorString());
        return;
    }
    QDataStream out(&F);
    out.setVersion(QDataStream::Qt_5_9);
    const int id = mIdSpinBox->value();

    DuCliente cliente(id, mNombreLineEdit->text(),
                      mDireccionLineEdit->text(),
                      mTelefonoLineEdit->text());

    if(cliente.isInside(id)){
        QMessageBox::warning(this, "Aviso", "ID REPETIDO");
        return;
    }

    out << cliente;
    F.flush();
    F.close();

    QMessageBox::information(this,"OK","Correcto");
    mIdSpinBox->clear();
    mNombreLineEdit->clear();
    mDireccionLineEdit->clear();
    mTelefonoLineEdit->clear();

    mIdSpinBox->setFocus();

}

bool AltaClienteForm::isInside(int id) const
{
    QFile F(CLIENTES_FILENAME);
    if(!F.open(QIODevice::ReadOnly)){
       return false;
    }
    QDataStream in(&F);
    in.setVersion(QDataStream::Qt_5_9);

    while(!in.atEnd()){
        DuCliente cliente;
        in >> cliente;
        if(cliente.getId() == id){
            return true;
        }
    }
    F.close();

    return false;
}

