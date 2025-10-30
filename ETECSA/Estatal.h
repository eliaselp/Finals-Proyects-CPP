#ifndef ESTATAL_H
#define ESTATAL_H
#include <iostream>
#include "Cliente.h"
using namespace std;
class Estatal:public Cliente
{
    public:
        Estatal(string Nombre, string Direccion, int CodigoProvincia,int Numero, bool Arrendada);
        virtual ~Estatal();
        //-------------------------------------------------------------------
        bool getArrendada();
        //--------------------------------------------------------------
        void setArrendada(bool Arrendada);

        void DataCliente()override;
    protected:

    private:
        bool Arrendada;
};

#endif // ESTATAL_H
