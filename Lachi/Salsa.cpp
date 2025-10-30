#include "Salsa.h"
#include <iostream>
using namespace std;
Salsa::Salsa(float Duracion, string Autor, int Anio, int Votos, int CantDiscos,string Estilo):Cancion(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->Estilo=Estilo;
    this->setNivelAceptacion();
    this->setCostoProduccion();
}

Salsa::~Salsa()
{
    //dtor
}


/********************************************************************/
/***********METODOS GETERS**********************/
/*******************************************************/
string Salsa::getEstilo(){
    return this->Estilo;
}



/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void Salsa::setNivelAceptacion(){
    this->NivelAceptacion=((30*this->getVotos())/100);
    return;
}
void Salsa::setCostoProduccion(){
    this->Costo=this->getCantDiscos();
    this->Costo+=((45*this->getCantDiscos())/100);
    return;
}
