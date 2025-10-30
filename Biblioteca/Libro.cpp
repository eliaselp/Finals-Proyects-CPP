#include "Libro.h"
#include <iostream>
using namespace std;
Libro::Libro(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion)
:Material(Titulo,Codigo,AnioIngreso)
{
    this->Autor=Autor;
    this->Genero=Genero;
    this->AnioPublicacion=AnioPublicacion;
    this->setFactorEstancia();
}

Libro::~Libro()
{
    //dtor
}



/****************************************************/
/********   METODOS GETER ***********************/
/*********************************************/
string Libro::getAutor(){
    return this->Autor;
}
string Libro::getGenero(){
    return this->Genero;
}
int Libro::getAnioPublicacion(){
    return this->AnioPublicacion;
}


/****************************************************/
/********   METODOS OVERRIDE ***********************/
/*********************************************/
void Libro::DataMaterial(){
    Material::DataMaterial();
    cout<<"[#] Autor: "<<this->Autor<<endl;
    cout<<"[#] Genero: "<<this->Genero<<endl;
    cout<<"[#] Anios de Publicado: "<<this->AnioPublicacion<<endl;
    return;
}



void Libro::setFactorEstancia(){
    this->FactorEstancia=(this->AnioPublicacion+1)/(this->getAnioIngreso()+1);
    return;
}
