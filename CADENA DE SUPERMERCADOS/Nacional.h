#ifndef NACIONAL_H
#define NACIONAL_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Nacional:public Producto
{
    public:
        Nacional(string Codigo,string Nombre, float PrecioCosto, int Cant, string Empresa);
        virtual ~Nacional();
        //-----------------------------------------
        string getEmpresa();
        //----------------------------------------
        void setPrecioVenta()override;
        void DataProducto()override;
        float getUSD()override;
        string getPais();

    protected:

    private:
        string Empresa;

};

#endif // NACIONAL_H
