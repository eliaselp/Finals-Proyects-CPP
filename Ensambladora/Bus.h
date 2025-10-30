#ifndef BUS_H
#define BUS_H
#include <iostream>
#include "Vehiculo.h"
using namespace std;


class Bus:public Vehiculo
{
    public:
        Bus(Motor* motor,int Plazas,float VMax,string FechaSalida,int CantPuertas);
        virtual ~Bus();
        //------------------------------
        int getCantPuertas();
        //----------------------------
        string FichaTecnica()override;
        void setPrecioVenta()override;
    protected:

    private:
        int CantPuertas;
};

#endif // BUS_H
