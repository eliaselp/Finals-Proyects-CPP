#ifndef SALSA_H
#define SALSA_H
#include "Genero.h"
#include <iostream>
using namespace std;

class Salsa:public Genero
{
    public:
        Salsa(int Duracion,string Autor,int Anio,int Votos,int CantDiscos,string Estilo);
        virtual ~Salsa();
        //---------------------------------------------------------
        string getEstilo();
        //-----------------------------------------------------------
        void setEstilo(string Estilo);
        //---------------------------------------------------------
        void setLevel_Accepted()override;
        void setCostoProduccion()override;
    protected:

    private:
        string Estilo;
};

#endif // SALSA_H
