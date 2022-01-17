#ifndef DUCUENTA_H
#define DUCUENTA_H
#include <QDataStream>

class DuCuenta
{
public:
    DuCuenta(int id=-1,int idCliente = -1, double saldo=0.0);
    void setId(int id);
    void setIdCliente(int id);
    void setSaldo(double saldo);

    int id()const;
    int idCliente()const;
    int saldo()const;

    friend QDataStream &operator<<(QDataStream &out, const DuCuenta &cuenta);
    friend QDataStream &operator>>(QDataStream &in, DuCuenta &cuenta);

private:
    int mId;
    int mIdCliente;
    double mSaldo;
};

QDataStream &operator<<(QDataStream &out, const DuCuenta &cuenta);
QDataStream &operator>>(QDataStream &in, DuCuenta &cuenta);

#endif // DUCUENTA_H
