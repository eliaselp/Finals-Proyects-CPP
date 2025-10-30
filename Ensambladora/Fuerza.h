#ifndef FUERZA_H
#define FUERZA_H
#include <iostream>
#include "Motor.h"
using namespace std;

class Fuerza:public Motor
{
    public:
        Fuerza(string Codigo,string FechaSalida,string Especialista,float CaballosFuerza);
        virtual ~Fuerza();
        //------------------------------
        float getCaballosFuerza();
        //-----------------------------------
        string FichaTecnica()override;
        void setPrecioCosto()override;
    protected:

    private:
        float CaballosFuerza;
};

#endif // FUERZA_H
