#ifndef ALTACLIENTEFORM_H
#define ALTACLIENTEFORM_H

#include <QWidget>

namespace Ui {
class AltaClienteForm;
}

class DuLineEdit;
class QVBoxLayout;
class QSpinBox;

class AltaClienteForm : public QWidget
{
    Q_OBJECT

public:
    explicit AltaClienteForm(QWidget *parent = nullptr);
    ~AltaClienteForm();

private slots:
    void on_AltapushButton_clicked();

private:
    Ui::AltaClienteForm *ui;
    QSpinBox *mIdSpinBox;
    DuLineEdit *mNombreLineEdit;
    DuLineEdit *mDireccionLineEdit;
    DuLineEdit *mTelefonoLineEdit;
    QVBoxLayout *mLayout;

    bool isInside(int id)const;

};

#endif // ALTACLIENTEFORM_H
