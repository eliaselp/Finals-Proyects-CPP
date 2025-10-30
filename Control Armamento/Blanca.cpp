#include "Blanca.h"
#include <iostream>
using namespace std;
Blanca::Blanca(int NoInventario,string Estado,string Tipo,float ValorArma,
               string Material,float ValorMaterial,int Peligrosidad)
:Arma(NoInventario,Estado,Tipo,ValorArma)
{
    this->Material=Material;
    this->ValorMaterial=ValorMaterial;
    this->Peligrosidad=Peligrosidad;
    this->setPesoPerdida();
    this->setUtilidad();
}

Blanca::~Blanca()
{
    //dtor
}




/**************************************************************************/
/*******************  METODOS GETERS   *************************************/
/*************************************************************************/
string Blanca::getMaterial(){
    return this->Material;
}
float Blanca::getValorMaterial(){
    return this->ValorMaterial;
}
int Blanca::getPeligrosidad(){
    return this->Peligrosidad;
}






/**************************************************************************/
/*******************  METODOS OVERRIDE   *************************************/
/*************************************************************************/
void Blanca::setPesoPerdida(){
    this->PesoPerdida=this->getValorArma()+(this->ValorMaterial*this->Peligrosidad);
    return;
}
void Blanca::setUtilidad(){
    this->Utilidad=this->Peligrosidad*1.7;
    return;
}

void Blanca::DataArma(){
    Arma::DataArma();
    cout<<"[#] Material: "<<this->Material<<endl;
    cout<<"[#] Valor Material: "<<this->ValorMaterial<<endl;
    cout<<"[#] Peligrosidad: "<<this->Peligrosidad<<endl;
    return;
}
