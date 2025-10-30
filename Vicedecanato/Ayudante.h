#ifndef AYUDANTE_H
#define AYUDANTE_H
#include <iostream>
#include "Estudiante.h"
#include "Asignatura.h"

class Ayudante:public Estudiante
{
    public:
        Ayudante(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,
                       string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera,int AniosImpartidos,int CantAsignaturasImpartidas);
        virtual ~Ayudante();
        //--------------------------------------------
        int getAniosImpartidos();
        Asignatura* getAsignaturasImpartidas(int n);
        int getCantAsignaturasImpartidas();
        //----------------------------------------------
        void DataEstudiante()override;
        void setEstipendio()override;
    protected:

    private:
        int AniosImpartidos;
        Asignatura** AsignaturasImpartidas;
        int CantAsignaturasImpartidas;
};

#endif // AYUDANTE_H
