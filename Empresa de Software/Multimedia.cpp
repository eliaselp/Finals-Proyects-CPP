#include "Multimedia.h"
#include <iostream>
using namespace std;
Multimedia::Multimedia(string Nombre,string Descripcion,int Tiempo,long Precio,string Desarrollo)
:Proyecto(Nombre,Descripcion,Tiempo,Precio)
{
    this->Desarrollo=Desarrollo;
}

Multimedia::~Multimedia()
{
    //dtor
}
string Multimedia::getDesarrollo(){
    return this->Desarrollo;
}


void Multimedia::DataProyecto(){
    Proyecto::DataProyecto();
    cout<<"[#] Desarrollo: "<<this->Desarrollo<<endl;
}
