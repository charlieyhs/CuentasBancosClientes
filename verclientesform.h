#ifndef VERCLIENTESFORM_H
#define VERCLIENTESFORM_H

#include <QWidget>

namespace Ui {
class VerClientesForm;
}

class VerClientesForm : public QWidget
{
    Q_OBJECT

public:
    explicit VerClientesForm(QWidget *parent = nullptr);
    ~VerClientesForm();

private slots:
    void on_ActualizarpushButton_clicked();

private:
    Ui::VerClientesForm *ui;
};

#endif // VERCLIENTESFORM_H
