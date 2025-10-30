#include "Fuego.h"
#include <iostream>
using namespace std;
Fuego::Fuego(int NoInventario,string Estado,string Tipo,float ValorArma,float Calibre,
              bool Cargador,int CantBalas,int AlcanceMax,float LongitudCannon)
:Arma(NoInventario,Estado,Tipo,ValorArma)
{
    this->Calibre=Calibre;
    this->Cargador=Cargador;
    this->CantBalas=CantBalas;
    this->AlcanceMax=AlcanceMax;
    this->LongitudCannon=LongitudCannon;
    this->setPesoPerdida();
    this->setUtilidad();
}

Fuego::~Fuego()
{
    //dtor
}




/**************************************************************************/
/*******************  METODOS GETERS   *************************************/
/*************************************************************************/
float Fuego::getCalibre(){
    return this->Calibre;
}
bool Fuego::getCargador(){
    return this->Cargador;
}
int Fuego::getCantBalas(){
    return this->CantBalas;
}
int Fuego::getAlcanceMax(){
    return this->AlcanceMax;
}
float Fuego::getLongitudCannon(){
    return this->LongitudCannon;
}






/**************************************************************************/
/*******************  METODOS OVERRIDE   *************************************/
/*************************************************************************/
void Fuego::setPesoPerdida(){
    this->PesoPerdida=this->getValorArma();
    if(this->Cargador==true){
        this->PesoPerdida+=this->CantBalas*this->Calibre;
    }
    return;
}
void Fuego::setUtilidad(){
    this->Utilidad=this->LongitudCannon*this->AlcanceMax*1.5;
    return;
}



void Fuego::DataArma(){
    Arma::DataArma();
    cout<<"[#] Calibre: "<<this->Calibre<<endl;
    if(this->Cargador==true){
        cout<<"[#] Cantidad de Balas del Cargador: "<<this->CantBalas<<endl;
    }
    cout<<"[#] Alcance Maximo: "<<this->AlcanceMax<<endl;
    cout<<"[#] Longitud del Cannon: "<<this->LongitudCannon<<endl;
    return;
}
