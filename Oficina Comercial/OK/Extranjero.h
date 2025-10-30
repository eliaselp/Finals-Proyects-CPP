#ifndef EXTRANJERO_H
#define EXTRANJERO_H
#include<iostream>
#include "Usuario.h"
using namespace std;

class Extranjero:public Usuario
{
    public:
        Extranjero(string Nombre, string Direccion, string Telefono);
        virtual ~Extranjero();
        //-----------------------------------------------------------------
        void DataUsuario()override;
        void setConsumo(int Mes)override;
    protected:

    private:
};

#endif // EXTRANJERO_H
