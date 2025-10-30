#ifndef FORMULA_H
#define FORMULA_H
#include "Carro.h"
#include "Alta.h"
#include<iostream>
using namespace std;

class Formula:public Carro
{
    public:
        Formula(float VelocidadMax,Alta* motor,float PesoCarroceria);
        virtual ~Formula();
        Alta* motor;
        //------------------------------------------------
        float getPesoCarroceria();
        //-----------------------------------------------
        void setPesoCarroceria(float PesoCarroceria);
        void setMotor(Alta* motor);
        //------------------------------------------------
        void setPrecioVenta()override;
        void FichaTecnica()override;
    protected:

    private:
        float PesoCarroceria;
};

#endif // FORMULA_H
