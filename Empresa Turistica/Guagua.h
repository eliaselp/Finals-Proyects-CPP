#ifndef GUAGUA_H
#define GUAGUA_H
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class Guagua:public Vehiculo
{
    public:
        Guagua(string Matricula, int CantAsientos, string Chofer,int CantPisos);
        virtual ~Guagua();
        /**********************/
        int getCantPisos();
        /*************************/
        void Imprimir()override;
    protected:

    private:
        int CantPisos;
};

#endif // GUAGUA_H
