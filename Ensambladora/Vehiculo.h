#ifndef VEHICULO_H
#define VEHICULO_H
#include "Motor.h"
#include <iostream>
using namespace std;
class Vehiculo
{
    public:
        Vehiculo(Motor* motor,int Plazas,float VMax,string FechaSalida);
        virtual ~Vehiculo();
        //-----------------------------------------
        Motor* getMotor();
        int getPlazas();
        float getVMax();
        string getFechaSalida();
        float getPrecioVenta();
        //---------------------------------------------
        virtual string FichaTecnica();
        virtual void setPrecioVenta()=0;
    protected:
        float PrecioVenta;
    private:
        Motor* motor;
        int Plazas;
        float VMax;
        string FechaSalida;

};

#endif // VEHICULO_H
