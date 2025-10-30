#ifndef LUJO_H
#define LUJO_H
#include <iostream>
#include "Vehiculo.h"

class Lujo:public Vehiculo
{
    public:
        Lujo(Motor* motor,int Plazas,float VMax,string FechaSalida,float CostoTapiceria);
        virtual ~Lujo();
        //--------------------------------------
        float getCostoTapiceria();
        //-------------------------------------
        string FichaTecnica()override;
        void setPrecioVenta()override;
    protected:

    private:
        float CostoTapiceria;
};

#endif // LUJO_H
