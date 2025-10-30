#ifndef BLANCA_H
#define BLANCA_H
#include "Arma.h"
#include <iostream>
using namespace std;

class Blanca:public Arma
{
    public:
        Blanca(int NoInventario,string Estado,string Tipo,float ValorArma,
               string Material,float ValorMaterial,int Peligrosidad);
        virtual ~Blanca();
        //-------------------------------------------------------------------
        string getMaterial();
        float getValorMaterial();
        int getPeligrosidad();
        //---------------------------------------------------------
        void DataArma()override;
    protected:
        void setPesoPerdida()override;
        void setUtilidad()override;

    private:
        string Material;
        float ValorMaterial;
        int Peligrosidad;
};

#endif // BLANCA_H
