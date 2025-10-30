#ifndef DESPACHO_H
#define DESPACHO_H
#include <iostream>
#include "Planta.h"
using namespace std;

class Despacho
{
    public:
        Despacho(int CantMaxPlantas,int MesActual);
        virtual ~Despacho();
        //---------------------------------------------
        Planta* getPlantas(int n);
        int getCantPlantas();
        int getCantMaxPlantas();
        int getMesActual();
        //-----------------------------------------------
        void setMesActual();
        //-----------------------------------------------
        void AggPlanta(Planta* nueva);
        void EliminarPlanta(int n);
        void DataBaneados();
        void DataPlantas();
        void MayorPromedio();
    protected:

    private:
        Planta** Plantas;
        int CantPlantas;
        int CantMaxPlantas;
        int MesActual;
};

#endif // DESPACHO_H
