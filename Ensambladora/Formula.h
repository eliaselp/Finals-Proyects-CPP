#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class Formula:public Vehiculo
{
    public:
        Formula(Motor* motor,int Plazas,float VMax,string FechaSalida,float PesoCarroceria);
        virtual ~Formula();
        //------------------------------------------
        float getPesoCarroceria();
        //------------------------------------------
        string FichaTecnica()override;
        void setPrecioVenta()override;
    protected:

    private:
        float PesoCarroceria;
};

#endif // FORMULA_H
