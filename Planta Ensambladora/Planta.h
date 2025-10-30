#ifndef PLANTA_H
#define PLANTA_H
//------------------------
#include "Motor.h"
#include "Fuerza.h"
#include "Alta.h"
#include "Trabajo.h"
//-----------------------
#include "Carro.h"
#include "Bus.h"
#include "Formula.h"
#include "Sport.h"
#include "Lujo.h"
//------------------------
#include <bits/stdc++.h>
using namespace std;

class Planta
{
    public:
        Planta();
        virtual ~Planta();
        //--------------------------------
        int getCantMotores();
        int getCantCarros();
        float getGanancia();
        void getDataTrabajoArtesanal();
        Motor* getMotor(int n);
        //---------------------------------
        int CantFuerza();
        int CantAlta();
        int CantTrabajo();
        int CantTrabajoArtesanal();
        //---------------------------------
        int CantFormula();
        int CantLujo();
        int CantSport();
        int CantBus();
        //---------------------------------
        void DataFormula();
        void DataLujo();
        void DataSport();
        void DataBus();
        //---------------------------------
        void AggMotor(Motor *nuevo);
        void EliminarMotor(int n);
        void AggCarro(Carro* nuevo);
        void VenderCarro(int n);
        void DesmantelarCarro(int n);
        //---------------------------------
        void DataMotores();
        void CarrosMaxVelocidad();
        void BusMayor();
        void DataAlmacenCarros();
        void CarrosMotoresReensablados();
        float CumplimientoMotores(int cant);
        float CumplimientoCarros(int cant);
        //-------------------------------------
        void MotoresFuerza();
        void MotoresAlta();
        void MotoresTrabajo();
    protected:

    private:
        Motor*AlmacenMotores;
        int CantMotores;
        Carro*AlmacenCarros;
        int CantCarros;
        float Ganancia;
};

#endif // PLANTA_H
