#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include "Equipo.h"
#include "Empleado.h"
#include "Programador.h"
#include "Lider.h"
#include "Proyecto.h"
#include "Empresarial.h"
#include "Multimedia.h"
using namespace std;

class Empresa
{
    public:
        Empresa(int MaxProyectos,int MaxEquipos,int MaxEmpleados);
        virtual ~Empresa();
        //----------------------------------------------
        Proyecto* getListaProyectos(int n);
        int getMaxProyectos();
        int getCantProyectos();
        Empleado* getListaEmpleados(int n);
        int getMaxEmpleados();
        int getCantEmpleados();
        Equipo* getListaEquipos(int n);
        int getMaxEquipos();
        int getCantEquipos();
        //---------------------------------------------------
        int CantProgramadores();
        int CantLideres();
        int CantMultimedia();
        int CantEmpresarial();
        int CantTotalEmpresarial();
        int CantTotalMultimedia();
        //----------------------------------------------------
        void DataEmpleado();
        void DataProgramadores();
        void DataLideres();
        void DataProyectos();
        void DataAllProyecto();
        void DataMultimedia();
        void DataEmpresarial();
        //-----------------------------------------------------
        void AggEquipo(Equipo* nuevo);
        void AggEmpleado(Empleado* nuevo);
        void AggProyecto(Proyecto* nuevo);
        void CambiarProgramador(int n1,int p,int n2);
        void ProyectoMinTime();
        float TotalSueldo();
        void EmpleadoMaxSueldo();
        void ProyectoProgramador(string CI);
        void DataProgramadoresProyecto(int n);
    protected:

    private:
        Proyecto** ListaProyectos;
        int MaxProyectos;
        int CantProyectos;

        Empleado**ListaEmpleados;
        int MaxEmpleados;
        int CantEmpleados;

        Equipo**ListaEquipos;
        int MaxEquipos;
        int CantEquipos;
};

#endif // EMPRESA_H
