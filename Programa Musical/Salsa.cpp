#include "Salsa.h"
#include <iostream>
using namespace std;
Salsa::Salsa(int Duracion,string Autor,int Anio,int Votos,int CantDiscos,string Estilo):Genero(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->Estilo=Estilo;
    setLevel_Accepted();
    setCostoProduccion();
}

Salsa::~Salsa()
{
    //dtor
}

/*****************************************************************************************************/
/******************  METODOS GETERS    ***********************************************************/
/********************************************************************************************************/
string Salsa::getEstilo(){
    return this->Estilo;
}




/*****************************************************************************************************/
/******************  METODOS SETERS    ***********************************************************/
/********************************************************************************************************/
void Salsa::setEstilo(string Estilo){
    this->Estilo=Estilo;
}





/*****************************************************************************************************/
/******************  METODOS OVERRIDE   ***********************************************************/
/********************************************************************************************************/
void Salsa::setLevel_Accepted(){
    this->Level_Accepted=((30*this->getVotos())/100);
    return;
}
void Salsa::setCostoProduccion(){
    this->CostoProduccion=this->getCantDiscos();
    this->CostoProduccion+=((25*this->CostoProduccion)/100);
    return;
}
