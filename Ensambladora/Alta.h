#ifndef ALTA_H
#define ALTA_H
#include <iostream>
#include "Motor.h"
using namespace std;

class Alta:public Motor
{
    public:
        Alta(string Codigo,string FechaSalida,string Especialista,float MaxRPM,float Consumo);
        virtual ~Alta();
        //-------------------------------
        float getMaxRPM();
        float getConsumo();
        //------------------------------------------
        void setPrecioCosto()override;
        string FichaTecnica()override;
    protected:

    private:
        float MaxRPM;
        float Consumo;
};

#endif // ALTA_H
