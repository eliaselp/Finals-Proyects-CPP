#ifndef CARRO_H
#define CARRO_H
#include <iostream>
#include "Motor.h"
using namespace std;

class Carro
{
    public:
        Carro(int Plazas, float VelocidadMax,Motor *motor);
        virtual ~Carro();
        Motor* motor;
        //-----------------------------------------
        int getPlazas();
        float getVelocidadMax();
        float getPrecioVenta();
        //-------------------------------------------
        void setPlazas(int Plazas);
        void setVelocidadMax(float VelocidadMax);
        //---------------------------------------------
        virtual void FichaTecnica()=0;
        virtual void setPrecioVenta()=0;
        virtual int getCantPuertas(){return 0;};
        //----------------------------------------------
        Carro* siguiente;
    protected:
        float PrecioVenta;
    private:
        int Plazas;
        float VelocidadMax;
};

#endif // CARRO_H
