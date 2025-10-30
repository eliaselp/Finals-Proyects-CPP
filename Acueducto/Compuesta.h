#ifndef COMPUESTA_H
#define COMPUESTA_H
#include <iostream>
#include "Cisterna.h"
using namespace std;

class Compuesta:public Cisterna
{
    public:
        Compuesta(float Capacidad,string Estado,string TipoAbasto,int CantCompartimientos);
        virtual ~Compuesta();
        //--------------------------------
        int getCantCompartimientos();
        //---------------------------------
        string DataDeposito()override;
    protected:

    private:
        int CantCompartimientos;
};

#endif // COMPUESTA_H
