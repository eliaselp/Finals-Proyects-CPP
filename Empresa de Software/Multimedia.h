#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include "Proyecto.h"
#include <iostream>
using namespace std;

class Multimedia:public Proyecto
{
    public:
        Multimedia(string Nombre,string Descripcion,int Tiempo,long Precio,string Desarrollo);
        virtual ~Multimedia();
        //-----------------------------------------
        string getDesarrollo();
        void DataProyecto()override;
    protected:

    private:
        string Desarrollo;
};

#endif // MULTIMEDIA_H
