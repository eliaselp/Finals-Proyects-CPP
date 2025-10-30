#ifndef ELECTRONICO_H
#define ELECTRONICO_H
#include <iostream>
#include "Medio.h"
using namespace std;

class Electronico:public Medio
{
    public:
        Electronico(string Inventario,float CostoUnitario,string Estado,string Tipo,string Marca,string Proveedor,int Garantia);
        virtual ~Electronico();
        /*******/
        string getMarca();
        string getProveedor();
        int getGarantia();
        /*******/
        void setCostoReal()override;
        void INFO()override;
    protected:

    private:
        string Marca;
        string Proveedor;
        int Garantia;
};

#endif // ELECTRONICO_H
