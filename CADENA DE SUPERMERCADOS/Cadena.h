#ifndef CADENA_H
#define CADENA_H
#include "Almacen.h"
#include <iostream>
using namespace std;
class Cadena
{
    public:
        Cadena(int CantMaxAlmacenes);
        virtual ~Cadena();
        //-------------------------
        int getCantAlmacenes();
        int getCantMaxAlmacenes();
        Almacen* getListadoAlmacenes(int n);
        //---------------------------
        void ProductoMaxVendido();
        void ProductoMinVendido();
        void AggAlmacen(Almacen* nuevo);
        void DataAlmacenes();
        void ProductosAlmacenes();
        void AlmacenMaxGanancia();
        float GananciaNeta();
    protected:

    private:
        Almacen**ListadoAlmacenes;
        int CantAlmacenes;
        int CantMaxAlmacenes;
};

#endif // CADENA_H
