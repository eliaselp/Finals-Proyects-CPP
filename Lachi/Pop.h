#ifndef POP_H
#define POP_H
#include "Cancion.h"
#include <iostream>
using namespace std;

class Pop:public Cancion
{
    public:
        Pop(float Duracion, string Autor, int Anio, int Votos, int CantDiscos,bool AcompMus);
        virtual ~Pop();
        //--------------------------------------------------------------------
        bool getAcompMus();
    protected:
        void setNivelAceptacion()override;
        void setCostoProduccion()override;
    private:
        bool AcompMus;
};

#endif // POP_H
