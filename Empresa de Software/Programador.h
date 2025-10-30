#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H
#include <iostream>
#include "Empleado.h"
using namespace std;

class Programador:public Empleado
{
    public:
        Programador(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI,int Lenguajes,char Categoria);
        virtual ~Programador();
        //----------------------------------------------------
        int getLenguajes();
        char getCategoria();
        //------------------------------------------------------
        void setSueldo(long PrecioProyecto)override;
        void DataEmpleado()override;

    protected:

    private:
        int Lenguajes;
        char Categoria;
};

#endif // PROGRAMADOR_H
