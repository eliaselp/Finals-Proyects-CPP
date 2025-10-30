#include "BluesRock.h"
#include <iostream>
using namespace std;
BluesRock::BluesRock(float Duracion, string Autor, int Anio, int Votos, int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->setCostoProduccion();
}

BluesRock::~BluesRock()
{

}






/********************************************************************/
/***********METODOS OVERRIDE**********************/
/*******************************************************/
void BluesRock::setCostoProduccion(){
    this->Costo=this->getCantDiscos();
    this->Costo+=((25*this->Costo)/100);
    return;
}
