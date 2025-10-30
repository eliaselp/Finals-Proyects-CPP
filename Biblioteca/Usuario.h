#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
using namespace std;

class Usuario
{
    public:
        int PesoAcumulado;
        Usuario(string Nombre,string CI,string Direccion,string Tipo,string FechaVencimiento);
        virtual ~Usuario();
        //------------------------------------------------------------------------------
        string getNombre();
        string getCI();
        string getDireccion();
        string getTipo();
        string getFechaVencimiento();
        //------------------------------------------------------------------------
        string DataUsuario();
    protected:

    private:
        string Nombre;
        string CI;
        string Direccion;
        string Tipo;
        string FechaVencimiento;
};

#endif // USUARIO_H
