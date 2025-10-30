#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include "Asignatura.h"
using namespace std;

class Estudiante
{
    public:
        Estudiante(string Nombre,string Apellido,string CI,string Grupo,int Anio,bool Proyecto,string NombreProyecto,int CantAsignaturas,bool AyudaFinanciera);
        virtual ~Estudiante();
        //----------------------------------------
        string getNombre();
        string getApellido();
        string getCI();
        string getGrupo();
        int getAnio();
        bool getProyecto();
        string getNombreProyecto();
        Asignatura* getAsignaturas(int n);
        int getCantAsignaturas();
        bool getAyudaFinanciera();
        float getEstipendio();
        //----------------------------------------
        virtual void setEstipendio()=0;
        virtual void DataEstudiante();
    protected:
        float Estipendio;
    private:
        string Nombre;
        string Apellido;
        string CI;
        string Grupo;
        int Anio;
        bool Proyecto;
        string NombreProyecto;
        Asignatura** Asignaturas;
        int CantAsignaturas;
        bool AyudaFinanciera;
};

#endif // ESTUDIANTE_H
