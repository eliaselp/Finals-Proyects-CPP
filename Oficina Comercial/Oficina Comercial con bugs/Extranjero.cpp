#include "Extranjero.h"
#include <iostream>
using namespace std;
Extranjero::Extranjero(string Nombre, string Direccion, string Telefono):Usuario(Nombre,Direccion,Telefono)
{

}

Extranjero::~Extranjero()
{
    //dtor
}





/***************************************************************************/
/******************  METODOS VIRTUAL   ******************************/
/***************************************************************************/
void Extranjero::DataUsuario(){
     cout<<"[#] Tipo: Extranjero."<<endl;
    Usuario::DataUsuario();
    cout<<"[#] Estado: ";
    if(this->getCategoria()==1)cout<<"Activo."<<endl;
    if(this->getCategoria()==2)cout<<"En Cola."<<endl;
    if(this->getCategoria()==3)cout<<"Baneado."<<endl;
    return;
}
void Extranjero::setConsumo(int Mes){
    if(this->Pay==false){
        if(this->Minutos>300){
            int d=this->Minutos-300;
            this->Consumo[Mes-1]=6.00+(0.03*d);
        }else if(this->Minutos<=300){
            this->Consumo[Mes-1]=6.00;
        }else{
            this->Consumo[Mes-1]=0;
        }
    }else{
        if(Mes==12)Mes=1;
        if(this->Minutos>300){
            int d=this->Minutos-300;
            this->Consumo[Mes]=6.00+(0.03*d);
        }else if(this->Minutos<=300){
            this->Consumo[Mes]=6.00;
        }else{
            this->Consumo[Mes]=0;
        }
    }
    return;
}
