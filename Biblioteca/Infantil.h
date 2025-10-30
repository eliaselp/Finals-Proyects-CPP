#ifndef INFANTIL_H
#define INFANTIL_H
#include "Libro.h"
#include <iostream>
using namespace std;

class Infantil:public Libro
{
    public:
        Infantil(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion,bool Fotos,int Mayor,int Menor);
        virtual ~Infantil();
        bool getFotos();
        int getMayor();
        int getMenor();
        //-----------------------------------------------------------------------------------------------------
        void DataMaterial()override;
    protected:

    private:
        bool Fotos;
        int Mayor;
        int Menor;
};

#endif // INFANTIL_H
