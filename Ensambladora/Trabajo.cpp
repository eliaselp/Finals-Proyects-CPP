#include "Trabajo.h"
#include <iostream>
using namespace std;
Trabajo::Trabajo(string Codigo,string FechaSalida,string Especialista,bool Artesanal)
:Motor(Codigo,FechaSalida,Especialista)
{
    this->Artesanal=Artesanal;
    this->setPrecioCosto();
}

Trabajo::~Trabajo()
{
    //dtor
}


/***** METODOS GETERS  ******/
bool Trabajo::getArtesanal(){
    return this->Artesanal;
}
void Trabajo::setArtesanal(){
    this->Artesanal=false;
}



/********  METODOS OVERRIDE *****/
void Trabajo::setPrecioCosto(){
    this->PrecioCosto=1000-(100*this->getRegreso());
    if(this->Artesanal==true)this->PrecioCosto*=10;
    return;
}
string Trabajo::FichaTecnica(){
    string Ficha="";
    Ficha+="[#] Tipo: Trabajo\n";
    Ficha+=Motor::FichaTecnica();
    Ficha+="[#] Artesanal: ";
    if(this->Artesanal==true)Ficha+="Si\n";
    else Ficha+="No\n";
    return Ficha;
}
