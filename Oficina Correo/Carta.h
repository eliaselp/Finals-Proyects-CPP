#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include "Correspondencia.h"
using namespace std;

class Carta:public Correspondencia
{
    public:
        int CantDias;
        Carta(string Nombre,string Direccion,string Remitente,string Fecha,bool Ext);
        virtual ~Carta();
        //----------------------------------------------------------------
        string getFecha();
        bool getExt();
        //---------------------------------------------------------------
        void DataCorrespondencia()override;
        void setCosto()override;
    protected:

    private:
        string Fecha;
        bool Ext;
};

#endif // CARTA_H
