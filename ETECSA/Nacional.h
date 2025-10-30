#ifndef NACIONAL_H
#define NACIONAL_H
#include <iostream>
#include "Llamada.h"
#include "Cliente.h"
#include "Estatal.h"
using namespace std;
class Nacional:public Llamada
{
    public:
        Nacional(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha,int CodigoTeleseleccionProvincial,int CodigoProvinciaReceptor);
        virtual ~Nacional();
        //---------------------------------------------------------
        int getCodigoTeleseleccionProvincial();
        int getCodigoProvinciaReceptor();
        //----------------------------------------------------------
        float ValorLlamada()override;
        //----------------------------------------------------------
        void DataLlamada()override;
    protected:

    private:
        int CodigoTeleseleccionProvincial;
        int CodigoProvinciaReceptor;
};

#endif // NACIONAL_H
