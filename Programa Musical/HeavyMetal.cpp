#include "HeavyMetal.h"

HeavyMetal::HeavyMetal(int Duracion,string Autor,int Anio,int Votos,int CantDiscos):Rock(Duracion,Autor,Anio,Votos,CantDiscos)
{
    //////////////////////////
    setCostoProduccion();
}

HeavyMetal::~HeavyMetal()
{
    //dtor
}

/**********************************************************************/
/********* METODO OVERRIDE   *******************************************/
/**********************************************************************/
void HeavyMetal::setCostoProduccion(){
    this->CostoProduccion=this->getCantDiscos();
    this->CostoProduccion+=((30*this->CostoProduccion)/100);
    return;
}
