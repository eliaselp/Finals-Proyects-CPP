#ifndef LUJO_H
#define LUJO_H
#include "Carro.h"
#include "Trabajo.h"
#include <iostream>
using namespace std;
class Lujo:public Carro
{
    public:
        Lujo(int Plazas, float VelocidadMax, float CostoTapiceria, Trabajo* motor);
        virtual ~Lujo();
        Trabajo* motor;
        //--------------------------------------------------------------------------
        float getCostoTapiceria();
        //--------------------------------------------------------------------------
        void setCostoTapiceria(float CostoTapiceria);
        void setMotor(Trabajo* motor);
        //--------------------------------------------------------------------------
        void setPrecioVenta()override;
        void FichaTecnica()override;
    protected:

    private:
        float CostoTapiceria;
};

#endif // LUJO_H
