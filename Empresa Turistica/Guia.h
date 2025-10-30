#ifndef GUIA_H
#define GUIA_H
#include <iostream>
#include "Persona.h"
using namespace std;

class Guia:public Persona
{
    public:
        Guia(string Nombre);
        virtual ~Guia();
        void InfoPersonal();
        int CantExc;
    protected:

    private:

};

#endif // GUIA_H
