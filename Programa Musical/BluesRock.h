#ifndef BLUESROCK_H
#define BLUESROCK_H
#include "Rock.h"
#include <iostream>
using namespace std;
class BluesRock:public Rock
{
    public:
        BluesRock(int Duracion,string Autor,int Anio,int Votos,int CantDiscos);
        virtual ~BluesRock();
        //-----------------------------------------------------
        void setCostoProduccion()override;
    protected:

    private:
};

#endif // BLUESROCK_H
