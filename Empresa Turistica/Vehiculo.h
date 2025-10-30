#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
using namespace std;
class Vehiculo
{
    public:
        Vehiculo(string Matricula, int CantAsientos, string Chofer);
        virtual ~Vehiculo();
        //-------------------------------------------------------
        string getMatricula();
        int getCantAsientos();
        string getChofer();
        //-------------------------------------------------------
        virtual void Imprimir();

    protected:

    private:
        string Matricula;
        int CantAsientos;
        string Chofer;
};

#endif // VEHICULO_H
