#ifndef CARRO_H
#define CARRO_H
#include <iostream>
#include "Vehiculo.h"
using namespace std;

class Carro:public Vehiculo
{
    public:
        Carro(string Matricula, int CantAsientos, string Chofer);
        virtual ~Carro();
        /**************/
        void Imprimir()override;
    protected:

    private:
};

#endif // CARRO_H
