#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
using namespace std;

class Cliente
{
    public:
        string Estado;
        Cliente* siguiente;
        Cliente(string Nombre, string Direccion, int CodigoProvincia,int Numero);
        virtual ~Cliente();
        //----------------------------------------------------------------------------
        string getNombre();
        string getDireccion();
        int getCodigoProvincia();
        int getNumero();
        float getGasto();
        //---------------------------------------------------------------------------
        void setGasto(float Gasto);
        virtual void DataCliente();
    protected:
        float Gasto;
    private:
        string Nombre;
        string Direccion;
        int CodigoProvincia;
        int Numero;
};

#endif // CLIENTE_H
