#ifndef FUEGO_H
#define FUEGO_H
#include <iostream>
#include "Arma.h"
using namespace std;

class Fuego:public Arma
{
    public:
        Fuego(int NoInventario,string Estado,string Tipo,float ValorArma,float Calibre,
              bool Cargador,int CantBalas,int AlcanceMax,float LongitudCannon);
        virtual ~Fuego();
        //---------------------------------------------------------------------------------
        float getCalibre();
        bool getCargador();
        int getCantBalas();
        int getAlcanceMax();
        float getLongitudCannon();
        void DataArma()override;
    protected:
        void setPesoPerdida()override;
        void setUtilidad()override;
    private:
        float Calibre;
        bool Cargador;
        int CantBalas;
        int AlcanceMax;
        float LongitudCannon;
};

#endif // FUEGO_H
