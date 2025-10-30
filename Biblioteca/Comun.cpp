#include "Comun.h"
#include <iostream>
using namespace std;
Comun::Comun(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion)
:Libro(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion)
{

}

Comun::~Comun()
{
    //dtor
}




void Comun::DataMaterial(){
    Libro::DataMaterial();
    return;
}
