#include "BluesRock.h"
#include <iostream>
using namespace std;
BluesRock::BluesRock(int Duracion,string Autor,int Anio,int Votos,int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
        //////////////////////////////////////////
        setCostoProduccion();
}

BluesRock::~BluesRock()
{
    //dtor
}


/**********************************************************************/
/********* METODO OVERRIDE   *******************************************/
/**********************************************************************/
void BluesRock::setCostoProduccion(){
    this->CostoProduccion=this->getCantDiscos();
    this->CostoProduccion+=((25*this->CostoProduccion)/100);
    return;
}
