#ifndef LIDER_H
#define LIDER_H
#include <iostream>
#include "Empleado.h"
using namespace std;

class Lider:public Empleado
{
    public:
        Lider(string Nombre,int Edad,string Sexo,float SalarioBasico,string CI,int Anios,int CantProyectos);
        virtual ~Lider();
        //---------------------------------------------------------
        int getAnios();
        int getCantProyectos();
        //--------------------------------------------------------
        void setSueldo(long PrecioProyecto)override;
        void DataEmpleado()override;
    protected:

    private:
        int Anios;
        int CantProyectos;
};

#endif // LIDER_H
