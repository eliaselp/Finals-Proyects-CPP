#ifndef ROCK_H
#define ROCK_H
#include "Genero.h"
#include <iostream>
using namespace std;
class Rock:public Genero
{
    public:
        Rock(int Duracion,string Autor,int Anio,int Votos,int CantDiscos);
        virtual ~Rock();
        //--------------------------------------------------------------------------
        string getTipo();
        //--------------------------------------------------------------------------
        void setTipo(string Tipo);
        //-----------------------------------------------------------------------------
        void setLevel_Accepted()override;
        virtual void setCostoProduccion()=0;
    protected:

    private:
        /***tipo (Blues Rock, Heavy Metal y Rock progresivo),
        */
};

#endif // ROCK_H
