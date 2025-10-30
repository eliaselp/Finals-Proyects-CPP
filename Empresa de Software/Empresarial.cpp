#include "Empresarial.h"
#include <iostream>
using namespace std;
Empresarial::Empresarial(string Nombre,string Descripcion,int Tiempo,long Precio,string Arquitectura,string BD)
:Proyecto(Nombre,Descripcion,Tiempo,Precio)
{
    this->Arquitectura=Arquitectura;
    this->BD=BD;
}

Empresarial::~Empresarial()
{
    //dtor
}


string Empresarial::getArquitectura(){
    return this->Arquitectura;
}
string Empresarial::getBD(){
    return this->BD;
}


void Empresarial::DataProyecto(){
    Proyecto::DataProyecto();
    cout<<"[#] Arquitectura: "<<this->Arquitectura<<endl;
    cout<<"[#] Base de Datos: "<<this->BD<<endl;
    return;
}
