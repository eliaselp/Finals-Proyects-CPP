#ifndef ALTA_H
#define ALTA_H
#include <iostream>
#include "Motor.h"
using namespace std;

class Alta:public Motor
{
    public:
        Alta(string Codigo, string FechaSalida, string Especialista,float MaxRevMin, float Consumo);
        virtual ~Alta();
        float getMaxRevMin();
        float getConsumo();
        float Costo() override;
        void FichaTecnica()override;

    protected:

    private:
        float MaxRevMin;
        float Consumo;
};

#endif // ALTA_H
