#ifndef BUS_H
#define BUS_H
#include "Carro.h"
#include "Fuerza.h"
#include <iostream>
using namespace std;
class Bus:public Carro
{
    public:
        Bus(float VelocidadMax, int CantPuertas,Fuerza* motor);
        virtual ~Bus();
        Fuerza* motor;
        //------------------------------------------------
        int getCantPuertas()override;
        //------------------------------------------------
        void setMotor(Fuerza* motor);
        //------------------------------------------------
        void FichaTecnica()override;
        void setPrecioVenta()override;
    protected:

    private:
        int CantPuertas;
};

#endif // BUS_H
