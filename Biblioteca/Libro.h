#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
#include <iostream>
using namespace std;
class Libro:public Material
{
    public:
        Libro(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion);
        virtual ~Libro();
        //-------------------------------------------------------------------------------------------------
        string getAutor();
        string getGenero();
        int getAnioPublicacion();
        //--------------------------------------------------------------------------------------------
        virtual void DataMaterial()override;
        //-----------------------------------------------------------------------------------------------
        void setFactorEstancia()override;
    protected:

    private:
        string Autor;
        string Genero;
        int AnioPublicacion;
};

#endif // LIBRO_H
