#ifndef LLAMADA_H
#define LLAMADA_H
#include <iostream>
#include "Cliente.h"
#include "Estatal.h"
using namespace std;
class Llamada
{
    public:
        Llamada* siguiente;
        Llamada(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha);
        virtual ~Llamada();
        //----------------------------------------------------------------------------------
        float getPrecio();
        int getDuracion();
        Cliente* getEmisor();
        int getNumeroReceptor();
        int getHora();
        int getMinuto();
        //------------------------------------------------------------------------------------
        virtual void DataLlamada();
    protected:
        float Precio;
        void setPrecio();
        virtual float ValorLlamada()=0;
    private:
        string Fecha;
        int Duracion;
        Cliente* Emisor;
        int NumeroReceptor;
        int Hora;
        int Minuto;
};

#endif // LLAMADA_H
