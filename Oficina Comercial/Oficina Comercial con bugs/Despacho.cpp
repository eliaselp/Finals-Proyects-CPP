#include "Despacho.h"
#include <iostream>
using namespace std;
Despacho::Despacho(int CantMaxPlantas,int MesActual)
{
    this->CantMaxPlantas=CantMaxPlantas;
    this->Plantas=new Planta*[CantMaxPlantas];
    this->CantPlantas=0;
    this->MesActual=MesActual;
}

Despacho::~Despacho()
{
    //dtor
}





/***************************************************************************/
/******************  METODOS GETERS   ******************************/
/***************************************************************************/
Planta* Despacho::getPlantas(int n){
    return this->Plantas[n-1];
}
int Despacho::getCantPlantas(){
    return this->CantPlantas;
}
int Despacho::getCantMaxPlantas(){
    return this->CantMaxPlantas;
}
int Despacho::getMesActual(){
    return this->MesActual;
}




/***************************************************************************/
/******************  METODOS SETERS   ******************************/
/***************************************************************************/
void Despacho::setMesActual(){
    for(int i=0;i<this->CantPlantas;i++){
        this->Plantas[i]->PoliticaCambio(this->MesActual);
    }
    this->MesActual++;
    if(this->MesActual>12)this->MesActual=1;
    for(int i=0;i<this->CantPlantas;i++){
        for(int j=0;j<this->Plantas[i]->getCantReal();j++){
            this->Plantas[i]->getTotalUsuarios(j+1)->setMinutos(0);
            this->Plantas[i]->getTotalUsuarios(j+1)->setConsumo(this->MesActual);
        }
    }
    return;
}


/***************************************************************************/
/******************  METODOS Apiladores   ******************************/
/***************************************************************************/
void Despacho::AggPlanta(Planta* nueva){
    this->Plantas[this->CantPlantas]=nueva;
    this->CantPlantas++;
    return;
}
void Despacho::EliminarPlanta(int n){
    if(n<=this->CantPlantas&&n>0){
        n--;
        delete this->Plantas[n];
        this->CantPlantas--;
        for(int i=n;i<this->CantPlantas;i++){
            this->Plantas[i]=this->Plantas[i+1];
        }
        this->Plantas[this->CantPlantas]=NULL;
    }else{
        cout<<"<<<<<  ERROR  >>>>>"<<endl;
    }
    return;
}

void Despacho::DataBaneados(){
    for(int i=0;i<this->CantPlantas;i++){
        cout<<"*************"<<endl;
        cout<<"*  Planta  "<<i+1<<"*"<<endl;
        cout<<"*************"<<endl<<endl;
        this->Plantas[i]->DataBaneados();
        cout<<"***************************************"<<endl;
    }
    return;
}
void Despacho::DataPlantas(){
    for(int i=0;i<this->CantPlantas;i++){
        cout<<"*************"<<endl;
        cout<<"*  Planta  "<<i+1<<"*"<<endl;
        cout<<"*************"<<endl<<endl;
        this->Plantas[i]->DataPlanta();
        cout<<"***************************************"<<endl<<endl<<endl;
    }
    return;
}
void Despacho::MayorPromedio(){
    for(int i=0;i<this->CantPlantas;i++){
        cout<<"*  Planta "<<i+1<<"*"<<endl;
        cout<<"*************"<<endl;
        this->Plantas[i]->UsuariosMaxPromedio(this->MesActual);
        cout<<"\n\n";
    }
    return;
}
