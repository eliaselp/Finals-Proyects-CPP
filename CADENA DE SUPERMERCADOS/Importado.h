#ifndef IMPORTADO_H
#define IMPORTADO_H
#include "Producto.h"
#include <iostream>
using namespace std;
class Importado:public Producto
{
    public:
        Importado(string Codigo,string Nombre, float PrecioCosto, int Cant, string Pais, float USD);
        virtual ~Importado();
        //************************************************
        //***********************************************
        string getPais();
        float getUSD()override;
        //**************************************************
        //**************************************************
        void DataProducto()override;
        void setPrecioVenta()override;

    protected:

    private:
        string Pais;
        float USD;
};

#endif // IMPORTADO_H
