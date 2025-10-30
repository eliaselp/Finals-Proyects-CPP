#ifndef TELEGRAMA_H
#define TELEGRAMA_H
#include <iostream>
#include "Correspondencia.h"
using namespace std;

class Telegrama:public Correspondencia
{
    public:
        Telegrama(string Nombre,string Direccion,string Remitente,int CantPalabras,float Impuesto);
        virtual ~Telegrama();
        //------------------------------------------------------------------
        int getCantPalabras();
        float getImpuesto();
        //----------------------------------------------------------------------
        void DataCorrespondencia()override;
        void setCosto()override;
    protected:

    private:
        int CantPalabras;
        float Impuesto;
};

#endif // TELEGRAMA_H
