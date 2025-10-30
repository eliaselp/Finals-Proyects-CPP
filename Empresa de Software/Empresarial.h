#ifndef EMPRESARIAL_H
#define EMPRESARIAL_H
#include <iostream>
#include "Proyecto.h"
using namespace std;

class Empresarial:public Proyecto
{
    public:
        Empresarial(string Nombre,string Descripcion,int Tiempo,long Precio,string Arquitectura,string BD);
        virtual ~Empresarial();
        //------------------------------------------------------
        string getArquitectura();
        string getBD();
        //----------------------------------------------------
        void DataProyecto()override;
    protected:

    private:
        string Arquitectura;
        string BD;
};

#endif // EMPRESARIAL_H
