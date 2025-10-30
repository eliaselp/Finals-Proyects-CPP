#include "Nacional.h"
#include <iostream>
using namespace std;
Nacional::Nacional(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha,int CodigoTeleseleccionProvincial,int CodigoProvinciaReceptor)
:Llamada(Duracion,Emisor,NumeroReceptor,Hora,Minuto,Fecha)
{
    this->CodigoTeleseleccionProvincial=CodigoTeleseleccionProvincial;
    this->CodigoProvinciaReceptor=CodigoProvinciaReceptor;
    this->setPrecio();
}

Nacional::~Nacional()
{
    //dtor
}



/*****************************************************************************************/
/******* METODOS GETERS *********************************/
/***************************************************/
int Nacional::getCodigoTeleseleccionProvincial(){
    return this->CodigoTeleseleccionProvincial;
}
int Nacional::getCodigoProvinciaReceptor(){
    return this->CodigoProvinciaReceptor;
}




/*****************************************************************************************/
/******* METODOS Override *********************************/
/***************************************************/
float Nacional::ValorLlamada(){
    float C=0;
    if(this->getEmisor()->getCodigoProvincia()==this->CodigoProvinciaReceptor){
        if(this->getNumeroReceptor()!=777777)C=0.5/3;
        if(dynamic_cast<Estatal*>(this->getEmisor())){
            Estatal* ptr=dynamic_cast<Estatal*>(this->getEmisor());
            if(ptr->getArrendada()==true)C=1;
            ptr=NULL;
        }
    }else{
        C=this->getEmisor()->getCodigoProvincia()-this->CodigoProvinciaReceptor;
        if(this->getHora()<22&&this->getHora()>05)C+=0.50;
    }
    return C;
}




/*****************************************************************************************/
/******* METODOS DATA Override *********************************/
/***************************************************/
void Nacional::DataLlamada(){
    Llamada::DataLlamada();
    cout<<"[#] Numero Receptor: "<<this->CodigoTeleseleccionProvincial<<"-"<<this->getNumeroReceptor()<<endl;
    cout<<"[#] Costo: "<<this->getPrecio();
    return;
}
