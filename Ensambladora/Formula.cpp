#include "Formula.h"
#include <iostream>
using namespace std;
Formula::Formula(Motor* motor,int Plazas,float VMax,string FechaSalida,float PesoCarroceria)
:Vehiculo(motor,Plazas,VMax,FechaSalida)
{
    this->PesoCarroceria=PesoCarroceria;
    this->setPrecioVenta();
}

Formula::~Formula()
{
    //dtor
}

/****** METODOS GETERS ******/
float Formula::getPesoCarroceria(){
    return this->PesoCarroceria;
}


/*********  METODOS OVERRIDE ****/
string Formula::FichaTecnica(){
    string Data=Vehiculo::FichaTecnica();
    Data+="[#] Peso de la Carroceria: "+to_string(this->PesoCarroceria);
    Data+="\n";
    return Data;
}
void Formula::setPrecioVenta(){
    this->PrecioVenta=(this->getVMax()*5)+(1/this->PesoCarroceria)+this->getMotor()->getPrecioCosto();
    return;
}

