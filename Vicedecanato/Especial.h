#ifndef ESPECIAL_H
#define ESPECIAL_H
#include <iostream>
#include "Estudiante.h"
#include "Asignatura.h"
using namespace std;



class Especial:public Estudiante
{
    public:
        Especial(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera,int AnioRepetido,Asignatura* Desaprobada);
        virtual ~Especial();
        //-------------------------------------------------------
        int getAnioRepetido();
        Asignatura* getDesaprobada();
        //--------------------------------------------------
        void DataEstudiante()override;
        void setEstipendio()override;

    protected:

    private:
        int AnioRepetido;
        Asignatura* Desaprobada;
};

#endif // ESPECIAL_H
