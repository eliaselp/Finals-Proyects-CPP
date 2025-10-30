#ifndef SIMPLE_H
#define SIMPLE_H
#include <iostream>
#include "Cisterna.h"
using namespace std;

class Simple:public Cisterna
{
    public:
        Simple(float Capacidad,string Estado,string TipoAbasto,string Forma);
        virtual ~Simple();
        //--------------------------------------------------------------------------
        string getForma();
        //--------------------------------------
        string DataDeposito()override;
    protected:

    private:
        string Forma;
};

#endif // SIMPLE_H
