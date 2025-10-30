#ifndef TRABAJO_H
#define TRABAJO_H
#include "Motor.h"
#include <iostream>
using namespace std;

class Trabajo:public Motor
{
    public:
        Trabajo(string Codigo,string FechaSalida,string Especialista,bool Artesanal);
        virtual ~Trabajo();
        //----------------------------
        bool getArtesanal();
        void setArtesanal();
        //-------------------------
        void setPrecioCosto()override;
        string FichaTecnica()override;
    protected:

    private:
        bool Artesanal;
};

#endif // TRABAJO_H
