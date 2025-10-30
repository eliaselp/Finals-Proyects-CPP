#ifndef REVISTA_H
#define REVISTA_H
#include "Material.h"
#include <iostream>
using namespace std;

class Revista:public Material
{
    public:
        Revista(string Titulo,string Codigo,int AnioIngreso,int MesesPublicacion,string Pais);
        virtual ~Revista();
        //----------------------------------------------------------------------------------------
        int getMesesPublicacion();
        string getPais();
        //----------------------------------------------------------
        void DataMaterial()override;
        void setFactorEstancia()override;
    protected:

    private:
        int MesesPublicacion;
        string Pais;
};

#endif // REVISTA_H
