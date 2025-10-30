#include "Material.h"
#include <iostream>
using namespace std;
Material::Material(string Titulo,string Codigo,int AnioIngreso)
{
    this->Titulo=Titulo;
    this->Codigo=Codigo;
    this->AnioIngreso=AnioIngreso;
    this->Prestado=false;
    this->Prestamos=0;
    this->PesoAsociado=0;
}

Material::~Material()
{
    //dtor
}


/****************************************************/
/********   METODOS GETER ***********************/
/*********************************************/
string Material::getTitulo(){
    return this->Titulo;
}
string Material::getCodigo(){
    return this->Codigo;
}
int Material::getAnioIngreso(){
    return this->AnioIngreso;
}
int Material::getPrestamos(){
    return this->Prestado;
}
bool Material::getPrestado(){
    return this->Prestado;
}
float Material::getFactorEstancia(){
    return this->FactorEstancia;
}
float Material::getPesoAsociado(){
    return this->PesoAsociado;
}

//------------------------------------------------------
void Material::setPesoAsociado(){
    this->PesoAsociado=this->Prestamos*this->FactorEstancia;
    return;
}

void Material::setPrestado(bool Prestado){
    this->Prestado=Prestado;
    return;
}



/****************************************************/
/********   METODOS DATA ***********************/
/*********************************************/
void Material::DataMaterial(){
    cout<<"[#] Titulo: "<<this->Titulo<<endl;
    cout<<"[#] Codigo: "<<this->Codigo<<endl;
    cout<<"[#] Anio de Ingreso: "<<this->AnioIngreso<<endl;
    cout<<"[#] Estado: ";
    if(this->Prestado==true){
        cout<<"Prestado"<<endl;
    }else{
        cout<<"Disponible."<<endl;
    }
    cout<<"[#] Cantidad de Prestamos Realizados: "<<this->Prestamos<<endl;
    return;
}
