#ifndef DEPOSITO_H
#define DEPOSITO_H
#include <iostream>
using namespace std;


class Deposito
{
    public:
        Deposito(float Capacidad,string Estado,string TipoAbasto);
        virtual ~Deposito();
        //---------------------------------
        float getCapacidad();
        string getEstado();
        string getTipoAbasto();
        //--------------------------------------
        virtual string DataDeposito();
    protected:

    private:
        float Capacidad;
        string Estado;//Lleno o vacio.
        string TipoAbasto;//Pipa o Tuberia.
};

#endif // DEPOSITO_H
