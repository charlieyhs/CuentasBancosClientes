#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAlta_de_Clientes_triggered();
    void on_actionAlta_de_Cuentas_triggered();
    void on_actionVer_Clientes_triggered();
    void on_actionVer_Cuentas_triggered();
    void on_actionSalir_triggered();

private:
    Ui::MainWindow *ui;
    void loadSubWindow(QWidget *widget);
};
#endif // MAINWINDOW_H
