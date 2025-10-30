#ifndef BULTO_H
#define BULTO_H
#include <iostream>
#include "Correspondencia.h"
using namespace std;

class Bulto:public Correspondencia
{
    public:
        Bulto(string Nombre,string Direccion,string Remitente,float Peso,int Urgencia);
        virtual ~Bulto();
        //-------------------------------------------------------------------------------
        float getPeso();
        int getUrgencia();
        //--------------------------------------------------------------------------
        void DataCorrespondencia()override;
        void setCosto()override;
    protected:

    private:
        float Peso;
        int Urgencia;
};

#endif // BULTO_H
