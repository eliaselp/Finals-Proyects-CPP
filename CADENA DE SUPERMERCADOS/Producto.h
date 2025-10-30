#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

class Producto
{
    public:
        Producto(string Codigo,string Nombre, float PrecioCosto, int Cant);
        virtual ~Producto();
        //------------------------------------
        string getNombre();
        string getCodigo();
        float getPrecioCosto();
        float getPrecioVenta();
        int getCant();
        int getVenta();
        //-------------------------------------
        void setNombre(string Nombre);
        void setCodigo(string Codigo);
        void setPrecioCosto(float PrecioCosto);
        void setCant(int Cant);
        void setVenta(int Venta);
        //--------------------------------------
        virtual void DataProducto();
        virtual void setPrecioVenta()=0;
        virtual string getPais()=0;
        virtual float getUSD()=0;
    protected:
        float PrecioVenta;
    private:
        string Codigo;
        string Nombre;
        float PrecioCosto;
        int Venta;
        int Cant;
};

#endif // PRODUCTO_H
