#ifndef VICEDECANATO_H
#define VICEDECANATO_H
#include <iostream>
#include "Estudiante.h"
#include "Comun.h"
#include "Especial.h"
#include "Ayudante.h"
#include "Asignatura.h"

using namespace std;


class Vicedecanato
{
    public:
        Vicedecanato(int MaxEstudiantes);
        virtual ~Vicedecanato();
        //-----------------------------------------------------
        Estudiante* getListaEstudiantes(int n);
        int getCantEstudiantes();
        int getMaxEstudiantes();
        //----------------------------------------------------
        int CantComun();
        int CantEspecial();
        int CantAyudante();
        //-------------------------------------------------------
        void DataEstudiantes();
        void DataComun();
        void DataAyudante();
        void DataEspecial();
        //--------------------------------------------------------
        void AggEstudiante(Estudiante* nuevo);
        string GrupoEstudiante(string CI);
        float Promedio(string Nombre);
        void DiplomaOro();//4.75
        void Escalafon();

    protected:

    private:
        Estudiante** ListaEstudiantes;
        int CantEstudiantes;
        int MaxEstudiantes;
};

#endif // VICEDECANATO_H
