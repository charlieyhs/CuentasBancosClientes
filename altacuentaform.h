#ifndef ALTACUENTAFORM_H
#define ALTACUENTAFORM_H

#include <QWidget>

namespace Ui {
class AltaCuentaForm;
}
class QVBoxLayout;
class QDoubleSpinBox;
class QSpinBox;

class AltaCuentaForm : public QWidget
{
    Q_OBJECT

public:
    explicit AltaCuentaForm(QWidget *parent = nullptr);
    ~AltaCuentaForm();

private slots:
    void on_AltapushButton_clicked();

private:
    Ui::AltaCuentaForm *ui;
    QSpinBox *mIdSpinBox;
    QSpinBox *mIdClienteSpinBox;
    QDoubleSpinBox *mSaldoSpinBox;
    QVBoxLayout *mLayout;

    bool isInside(int id)const;

};

#endif // ALTACUENTAFORM_H
