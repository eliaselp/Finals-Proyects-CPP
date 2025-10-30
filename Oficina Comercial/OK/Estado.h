#ifndef ESTADO_H
#define ESTADO_H
#include <iostream>
#include "Usuario.h"
using namespace std;

class Estado:public Usuario
{
    public:
        Estado(string Nombre, string Direccion, string Telefono,string Empresa);
        virtual ~Estado();
        //---------------------------------------------------------
        string getEmpresa();
        //-----------------------------------------------------------
        void setConsumo(int Mes)override;
        void DataUsuario()override;
    protected:

    private:
        string Empresa;
};

#endif // ESTADO_H
