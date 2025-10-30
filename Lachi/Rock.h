#ifndef ROCK_H
#define ROCK_H
#include "Cancion.h"
#include <iostream>
using namespace std;

class Rock:public Cancion
{
    public:
        Rock(float Duracion, string Autor, int Anio, int Votos, int CantDiscos);
        virtual ~Rock();
        //--------------------------------------------------------------
        void setNivelAceptacion()override;
        virtual void setCostoProduccion()override=0;
    protected:

    private:
};

#endif // ROCK_H
