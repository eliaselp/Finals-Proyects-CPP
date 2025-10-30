#ifndef COMUN_H
#define COMUN_H
#include <iostream>
#include "Estudiante.h"
using namespace std;

class Comun:public Estudiante
{
    public:
        Comun(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                       string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera);
        virtual ~Comun();
        //-----------------------------------
        void DataEstudiante()override;
        void setEstipendio()override;
    protected:

    private:
};

#endif // COMUN_H
