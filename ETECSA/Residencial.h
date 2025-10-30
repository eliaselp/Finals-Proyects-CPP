#ifndef RESIDENCIAL_H
#define RESIDENCIAL_H
#include <iostream>
#include "Cliente.h"
using namespace std;
class Residencial:public Cliente
{
    public:
        Residencial(string Nombre, string Direccion, int CodigoProvincia,int Numero,int CI);
        virtual ~Residencial();
        //----------------------------------------------------------------------------------------------
        bool getMatutino();
        bool getRastreo();
        string getHoraMatutino();
        int getCI();
        //--------------------------------------------------------------------------------------------------
        void setMatutino(bool Matutino);
        void setRastreo(bool Rastreo);
        void setHoraMatutino(string HoraMatutino);

        void DataCliente()override;
    protected:

    private:
        int CI;
        bool Matutino;
        bool Rastreo;
        string HoraMatutino;
};

#endif // RESIDENCIAL_H
