#include "Rock.h"
#include <iostream>
using namespace std;
Rock::Rock(int Duracion,string Autor,int Anio,int Votos,int CantDiscos):Genero(Duracion,Autor,Anio,Votos,CantDiscos)
{
    ///////////////////
    setLevel_Accepted();
}

Rock::~Rock()
{
    //dtor
}





/*****************************************************************************************************/
/******************  METODOS OVERRIDE   ***********************************************************/
/********************************************************************************************************/
void Rock::setLevel_Accepted(){
    this->Level_Accepted=((15*this->getVotos())/100);
    return;
}

