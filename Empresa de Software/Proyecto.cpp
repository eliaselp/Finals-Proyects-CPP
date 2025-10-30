#include "Proyecto.h"
#include <iostream>
using namespace std;
Proyecto::Proyecto(string Nombre,string Descripcion,int Tiempo,long Precio)
{
    this->Nombre=Nombre;
    this->Descripcion=Descripcion;
    this->Tiempo=Tiempo;
    this->Precio=Precio;
    this->Asignado=false;
}

Proyecto::~Proyecto()
{
    //dtor
}



/****** METODOS GETER  *******/
string Proyecto::getNombre(){
    return this->Nombre;
}
string Proyecto::getDescripcion(){
    return this->Descripcion;
}
int Proyecto::getTiempo(){
    return this->Tiempo;
}
long Proyecto::getPrecio(){
    return this->Precio;
}


void Proyecto::DataProyecto(){
    cout<<"[#] Nombre: "<<this->Nombre<<endl;
    cout<<"[#] Descripcion: "<<this->Descripcion<<endl;
    cout<<"[#] Tiempo: "<<this->Tiempo<<endl;
    cout<<"[#] Precio: "<<this->Precio<<endl;
    cout<<"[#] Estado: ";
    if(this->Asignado==true){
        cout<<"Asignado."<<endl;
    }else{
        cout<<"Pendiente."<<endl;
    }
    return;
}
