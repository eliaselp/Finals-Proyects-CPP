#ifndef COMUN_H
#define COMUN_H
#include "Libro.h"
#include <iostream>
using namespace std;

class Comun:public Libro
{
    public:
        Comun(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion);
        virtual ~Comun();
        void DataMaterial()override;
    protected:

    private:
};

#endif // COMUN_H
