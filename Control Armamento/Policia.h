#ifndef POLICIA_H
#define POLICIA_H
#include <iostream>
#include "Arma.h"
#include "Fuego.h"
#include "Blanca.h"
using namespace std;

class Policia
{
    public:
        Policia(int PlantillaFuego,int PlantillaBlanca);
        virtual ~Policia();
        //--------------------------------------------------------
        int getPlantillaFuego();
        int getPlantillaBlanca();
        int getCantFuego();
        int getCantBlanca();
        int getCantReal();
        Arma* getListaArmas(int n);
        //--------------------------------------------------------
        void AggArma(Arma* nueva);
        void EliminarArma(int n);
        void DataFuego();
        void DataBlanca();
        void DataArmas();
        //--------------------------------------------------------------
        void Completamiento();
        void PerdidaTipo();
        void ReservaTipo();
        void TipoMayorPerdida();
        void TipoMayorReserva();
        void MinCompletamiento();
        bool BuscarTipoArma(string Type);
        string GestionEstado(int Inventario);
        float GestionPerdida(int n);
        float GestionUtilidad(int n);
        void ArmaUSO();
    protected:

    private:
        int PlantillaFuego;
        int PlantillaBlanca;
        int CantFuego;
        int CantBlanca;
        int CantReal;
        int CantMax;
        Arma** ListaArmas;
};

#endif // POLICIA_H
