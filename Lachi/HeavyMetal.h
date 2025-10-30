#ifndef HEAVYMETAL_H
#define HEAVYMETAL_H
#include "Rock.h"
#include <iostream>
using namespace std;
class HeavyMetal:public Rock
{
    public:
        HeavyMetal(float Duracion, string Autor, int Anio, int Votos, int CantDiscos);
        virtual ~HeavyMetal();
        //----------------------------------------------------------
        void setCostoProduccion()override;
    protected:

    private:
};

#endif // HEAVYMETAL_H
