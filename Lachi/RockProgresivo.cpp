#include "RockProgresivo.h"
#include <iostream>
using namespace std;
RockProgresivo::RockProgresivo(float Duracion, string Autor, int Anio, int Votos, int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->setCostoProduccion();
}

RockProgresivo::~RockProgresivo()
{
    //dtor
}




/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void RockProgresivo::setCostoProduccion(){
    this->Costo=this->getCantDiscos();
    this->Costo+=((15*this->Costo)/100);
    return;
}
