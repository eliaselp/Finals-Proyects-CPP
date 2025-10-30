#ifndef MOBILIARIO_H
#define MOBILIARIO_H
#include "Medio.h"

class Mobiliario:public Medio
{
    public:
        Mobiliario(string Inventario,float CostoUnitario,string Estado,string Tipo,string Proveedor,int Explotacion,string Local);
        virtual ~Mobiliario();
        /******/
        string getProveedor();
        int getExplotacion();
        string getLocal();
        /******/
        void setCostoReal()override;
        void INFO()override;
    protected:

    private:
        string Proveedor;
        int Explotacion;
        string Local;
};

#endif // MOBILIARIO_H
