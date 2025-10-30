#ifndef ROCKPROGRESIVO_H
#define ROCKPROGRESIVO_H
#include "Rock.h"
#include <iostream>
using namespace std;
class RockProgresivo:public Rock
{
    public:
        RockProgresivo(int Duracion,string Autor,int Anio,int Votos,int CantDiscos);
        virtual ~RockProgresivo();
        //---------------------------------------------------
        void setCostoProduccion()override;
    protected:

    private:
};

#endif // ROCKPROGRESIVO_H
