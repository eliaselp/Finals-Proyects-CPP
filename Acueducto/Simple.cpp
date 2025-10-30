#include "Simple.h"

Simple::Simple(float Capacidad,string Estado,string TipoAbasto,string Forma)
:Cisterna(Capacidad,Estado,TipoAbasto)
{
    this->Forma=Forma;
}

Simple::~Simple()
{
    //dtor
}


string Simple::getForma(){
    return this->Forma;
}

string Simple::DataDeposito(){
    string Data="";
    Data+="[#] Tipo: Cisterna Simple.\n";
    Data+=Deposito::DataDeposito();
    Data+="[#] Forma: "+this->Forma+"\n";
    return Data;
}
