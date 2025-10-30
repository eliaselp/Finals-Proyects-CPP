#ifndef SALSA_H
#define SALSA_H
#include "Cancion.h"
#include <iostream>
using namespace std;

class Salsa:public Cancion
{
    public:
        Salsa(float Duracion, string Autor, int Anio, int Votos, int CantDiscos,string Estilo);
        virtual ~Salsa();
        //--------------------------------------------------------------------------------
        string getEstilo();
        //---------------------------------------------------------------------------------
        void setNivelAceptacion()override;
        void setCostoProduccion()override;
    protected:

    private:
        string Estilo;
};

#endif // SALSA_H
