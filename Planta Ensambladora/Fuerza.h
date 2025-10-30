#ifndef FUERZA_H
#define FUERZA_H
#include "Motor.h"
#include <iostream>
using namespace std;

class Fuerza:public Motor
{
    public:
        Fuerza(string Codigo, string FechaSalida, string Especialista, int CaballosFuerza);
        virtual ~Fuerza();
        int getCaballosFuerza();
        void FichaTecnica()override;
        float Costo()override;
    protected:

    private:
        int CaballosFuerza;
};

#endif // FUERZA_H
