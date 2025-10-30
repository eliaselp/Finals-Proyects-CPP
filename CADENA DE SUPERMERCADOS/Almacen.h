#ifndef ALMACEN_H
#define ALMACEN_H
#include "Producto.h"
#include "Nacional.h"
#include "Importado.h"
#include <iostream>
using namespace std;
class Almacen
{
    public:
        Almacen(int MaxProductos);
        Producto** ListaProductos;
        virtual ~Almacen();
        //*****************************************
        int getCantProductos();
        int getMaxProductos();
        float getGanancia();
        //****************************************
        int CantNacional();
        int CantImportado();
        //*****************************************
        void AggProducto(Producto* nuevo);
        void DataNacional();
        void DataInternacional();
        void PedidoCadena(int n);
        void Vender(string Codigo, int cant);
        //*****************************************
        void ProductoMaxVendido();
        void ProductoMinVendido();
        void NacionaPrecioPlus(float Precio);
        void BuscarProductoPorPais(string Pais);
    protected:

    private:
        int CantProductos;
        float Ganancia;
        int MaxProductos;
};

#endif // ALMACEN_H
