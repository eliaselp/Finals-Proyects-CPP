#ifndef CISTERNA_H
#define CISTERNA_H
#include <iostream>
#include "Deposito.h"
using namespace std;

class Cisterna:public Deposito
{
    public:
        Cisterna(float Capacidad,string Estado,string TipoAbasto);
        virtual ~Cisterna();

    protected:

    private:
};

#endif // CISTERNA_H
