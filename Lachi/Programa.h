#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Cancion.h"
#include "Salsa.h"
#include "Rock.h"
#include "Pop.h"
#include <iostream>
using namespace std;

class Programa
{
    public:
        Programa(int CantMaxCanciones);
        virtual ~Programa();
        //------------------------------------------
        void AggCancion(Cancion* nueva);
        void EliminarCancion(int n);
        //------------------------------------------
        void DataListaReproduccion();
        void DataTipo();
        void DataSalsa();
        void DataRock();
        void DataPop();
        //---------------------------------------------
        int CantSalsa();
        int CantRock();
        int CantPop();
        //---------------------------------------------
        void CancionMaxLarga();
        int CantPopACM();
        void RockMaxAccepted();
        float TiempoTotal();
        void CancionMaxVotos(int Votos);
        void CancionMinDuracion(float Duracion);
    protected:

    private:
        int CantReal;
        int CantMaxCanciones;
        Cancion** ListaReproduccion;
};

#endif // PROGRAMA_H
