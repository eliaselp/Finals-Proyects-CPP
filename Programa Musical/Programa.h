#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <iostream>
#include "Genero.h"
//-----------------------------
#include "Rock.h"
#include "RockProgresivo.h"
#include "HeavyMetal.h"
#include "BluesRock.h"
//-------------------------------
#include "POP.h"
//-----------------------------------
#include "Salsa.h"

class Programa
{
    public:
        Programa(int CantMaxCanciones);
        virtual ~Programa();
        //-------------------------------------------------
        int getCantCanciones();
        //-------------------------------------------------
        void DataReproduccion();
        void DataRockProgresivo();
        void DataHeavyMetal();
        void DataBluesRock();
        void DataPOP();
        void DataSalsa();
        //----------------------------------------------------------------
        int CantRockProgresivo();
        int CantHeavyMetal();
        int CantBluesRock();
        int CantPOP();
        int CantSalsa();
        //-----------------------------------------------------------------
        void AggCancion(Genero* nuevo);
        void EliminarCancion(int n);
        void DataMaxDuracion();
        int CantPopACM();
        void DataRockMaxAccepted();
        int TotalTime();
        void DataPlusVotos(int n);
        void DataListMinTime(int time);


    protected:

    private:
        Genero** ListaReproduccion;
        int CantCanciones;
};

#endif // PROGRAMA_H
