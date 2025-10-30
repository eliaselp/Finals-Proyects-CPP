#include "POP.h"
#include <iostream>
using namespace std;
POP::POP(int Duracion,string Autor,int Anio,int Votos,int CantDiscos,bool ACM):Genero(Duracion,Autor,Anio,Votos,CantDiscos)
{
    this->ACM=ACM;
    setLevel_Accepted();
    setCostoProduccion();
}

POP::~POP()
{
    //dtor
}



/*****************************************************************************************************/
/******************  METODOS GETERS    ***********************************************************/
/********************************************************************************************************/
bool POP::getACM(){
    return this->ACM;
}





/*****************************************************************************************************/
/******************  METODOS SETERS    ***********************************************************/
/********************************************************************************************************/
void POP::setACM(bool ACM){
    this->ACM=ACM;
    return;
}





/*****************************************************************************************************/
/******************  METODOS OVERRIDE    ***********************************************************/
/********************************************************************************************************/
void POP::setLevel_Accepted(){
    this->Level_Accepted=((25*this->getVotos())/100);
    return;
}

void POP::setCostoProduccion(){
    this->CostoProduccion=this->getCantDiscos();
    if(this->ACM==true){
        this->CostoProduccion+=((25*this->CostoProduccion)/100);
    }
    return;
}
