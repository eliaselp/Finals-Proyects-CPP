#include "Arma.h"
#include <iostream>
using namespace std;
Arma::Arma(int NoInventario,string Estado,string Tipo,float ValorArma)
{
    this->NoInventario=NoInventario;
    this->Estado=Estado;
    this->Tipo=Tipo;
    this->ValorArma=ValorArma;
}

Arma::~Arma()
{
    //dtor
}



/**************************************************************************/
/*******************  METODOS GETERS   *************************************/
/*************************************************************************/
float Arma::getUtilidad(){
    return this->Utilidad;
}
float Arma::getPesoPerdida(){
    return this->PesoPerdida;
}
int Arma::getNoInventario(){
    return this->NoInventario;
}
string Arma::getEstado(){
    return this->Estado;
}
string Arma::getTipo(){
    return this->Tipo;
}
float Arma::getValorArma(){
    return this->ValorArma;
}


/**************************************************************************/
/*******************  METODOS DATA   *************************************/
/*************************************************************************/
void Arma::DataArma(){
    cout<<"[#] No. Inventario: "<<this->NoInventario<<endl;
    cout<<"[#] Estado: "<<this->Estado<<endl;
    cout<<"[#] Tipo: "<<this->Tipo<<endl;
    cout<<"[#] Precio de Perdida: "<<this->PesoPerdida<<endl;
    cout<<"[#] Utilidad: "<<this->Utilidad<<endl;
    return;
}
