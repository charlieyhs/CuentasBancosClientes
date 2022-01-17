#ifndef DUCLIENTE_H
#define DUCLIENTE_H

#include <QDataStream>


class DuCliente
{
public:
    DuCliente(int id = -1, const QString &nombre="", const QString &direccion="",
              const QString &telefono="");
    void setId(int id);
    void setNombre(const QString &nombre);
    void setDireccion(const QString &direccion);
    void setTelefono(const QString &telefono);

    int getId()const;
    QString getNombre()const;
    QString getDireccion()const;
    QString getTelefono()const;
    bool isInside(int id)const;

    friend QDataStream &operator<<(QDataStream &out, const DuCliente &cliente);
    friend QDataStream &operator>>(QDataStream &in, DuCliente &cliente);

private:
    int mId;
    QString mNombre;
    QString mDireccion;
    QString mTelefono;

};

QDataStream &operator<<(QDataStream &out, const DuCliente &cliente);
QDataStream &operator>>(QDataStream &in, DuCliente &cliente);

#endif // DUCLIENTE_H
