#ifndef POP_H
#define POP_H
#include <iostream>
#include "Genero.h"

class POP:public Genero
{
    public:
        POP(int Duracion,string Autor,int Anio,int Votos,int CantDiscos,bool ACM);
        virtual ~POP();
        //----------------------------------------------------------------------------
        bool getACM();
        //----------------------------------------------------------------------------
        void setACM(bool ACM);
        //----------------------------------------------------------------------------
        void setLevel_Accepted()override;
        void setCostoProduccion()override;
    protected:

    private:
        bool ACM;
};

#endif // POP_H
