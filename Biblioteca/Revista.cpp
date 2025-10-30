#include "Revista.h"
#include <iostream>
using namespace std;
Revista::Revista(string Titulo,string Codigo,int AnioIngreso,int MesesPublicacion,string Pais)
:Material(Titulo,Codigo,AnioIngreso)
{
    this->MesesPublicacion=MesesPublicacion;
    this->Pais=Pais;
    this->setFactorEstancia();
}

Revista::~Revista()
{
    //dtor
}



/****************************************************/
/********   METODOS GETER ***********************/
/*********************************************/
int Revista::getMesesPublicacion(){
    return this->MesesPublicacion;
}
string Revista::getPais(){
    return this->Pais;
}




/****************************************************/
/********   METODOS DATA ***********************/
/*********************************************/
void Revista::DataMaterial(){
    Material::DataMaterial();
    cout<<"[#] Meses de Publicado: "<<this->MesesPublicacion<<endl;
    cout<<"[#] Pais: "<<this->Pais<<endl;
    return;
}




void Revista::setFactorEstancia(){
    this->FactorEstancia=(this->MesesPublicacion+1)/(this->getAnioIngreso()*10+1);
    return;
}
