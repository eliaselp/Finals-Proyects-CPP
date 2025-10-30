#include "RockProgresivo.h"
#include <iostream>
using namespace std;
RockProgresivo::RockProgresivo(int Duracion,string Autor,int Anio,int Votos,int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
    //ctor
    setCostoProduccion();
}

RockProgresivo::~RockProgresivo()
{
    //dtor
}


/**********************************************************************/
/********* METODO OVERRIDE   *******************************************/
/**********************************************************************/
void RockProgresivo::setCostoProduccion(){
    this->CostoProduccion=this->getCantDiscos();
    this->CostoProduccion+=((15*this->CostoProduccion)/100);
    return;
}
