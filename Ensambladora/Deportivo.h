#ifndef DEPORTIVO_H
#define DEPORTIVO_H
#include "Vehiculo.h"
#include <iostream>
using namespace std;

class Deportivo:public Vehiculo
{
    public:
        Deportivo(Motor* motor,int Plazas,float VMax,string FechaSalida,int CantVelocidades,bool CambioUniversal);
        virtual ~Deportivo();
        //--------------------------------------
        int getCantVelocidades();
        bool getCambioUniversal();
        //-------------------------------------
        string FichaTecnica()override;
        void setPrecioVenta()override;
    protected:

    private:
        int CantVelocidades;
        bool CambioUniversal;
};

#endif // DEPORTIVO_H
