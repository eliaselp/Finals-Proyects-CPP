#ifndef BOMBA_H
#define BOMBA_H
#include <iostream>
#include "Equipo.h"
using namespace std;

class Bomba:public Equipo
{
    public:
        Bomba(string Estado,float Regimen,float Tiempo);
        virtual ~Bomba();
        //--------------------------------
        float getTiempo();
        //-------------------------------
        string DataEquipo()override;
    protected:

    private:
        float Tiempo;
};

#endif // BOMBA_H
