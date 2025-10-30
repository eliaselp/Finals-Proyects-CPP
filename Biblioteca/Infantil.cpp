#include "Infantil.h"
#include <iostream>
using namespace std;
Infantil::Infantil(string Titulo,string Codigo,int AnioIngreso,string Autor,string Genero,int AnioPublicacion,bool Fotos,int Mayor,int Menor)
:Libro(Titulo,Codigo,AnioIngreso,Autor,Genero,AnioPublicacion)
{
    this->Fotos=Fotos;
    this->Mayor=Mayor;
    this->Menor=Menor;
}

Infantil::~Infantil()
{
    //dtor
}



/****************************************************/
/********   METODOS GETER ***********************/
/*********************************************/
bool Infantil::getFotos(){
    return this->Fotos;
}
int Infantil::getMayor(){
    return this->Mayor;
}
int Infantil::getMenor(){
    return this->Menor;
}



void Infantil::DataMaterial(){
    Libro::DataMaterial();
    cout<<"[#] Fotos: ";
    if(this->Fotos==true){
        cout<<"Si."<<endl;
    }else{
        cout<<"No."<<endl;
    }
    cout<<"[#] Rango de Edad: "<<this->Menor<<"---"<<this->Mayor<<endl;
    return;
}
