#include "Acueducto.h"
#include <iostream>
using namespace std;
Acueducto::Acueducto(int CantMaxDepositos, int CantMaxEquipos)
{
    this->CantMaxDepositos=CantMaxDepositos;
    this->CantMaxEquipos=CantMaxEquipos;
    this->CantDepositos=0;
    this->CantEquipos=0;
    this->ListaDepositos=new Deposito*[this->CantMaxDepositos];
    this->ListaEquipos=new Equipo*[this->CantMaxEquipos];
}

Acueducto::~Acueducto()
{
    //dtor
}



int Acueducto::getCantMaxDepositos(){
    return this->CantMaxDepositos;
}
int Acueducto::getCantDepositos(){
    return this->CantDepositos;
}
Deposito* Acueducto::getListaDepositos(int n){
    return this->ListaDepositos[n-1];
}
Equipo* Acueducto::getListaEquipos(int n){
    return this->ListaEquipos[n-1];
}
int Acueducto::getCantMaxEquipos(){
    return this->CantMaxDepositos;
}
int Acueducto::getCantEquipos(){
     return this->CantEquipos;
}
//----------------------------------Hidraulic
void Acueducto::AggDeposito(Deposito* nuevo){
    this->ListaDepositos[this->CantDepositos]=nuevo;
    this->CantDepositos++;
    return;
}
void Acueducto::EliminarDeposito(int n){
    delete this->ListaDepositos[n-1];
    this->CantDepositos--;
    for(int i=n-1;i<this->CantDepositos;i++){
        this->ListaDepositos[i]=this->ListaDepositos[i+1];
    }
    this->ListaDepositos[this->CantDepositos]=NULL;
    return;
}
void Acueducto::AggEquipo(Equipo* nuevo){
    this->ListaEquipos[this->CantEquipos]=nuevo;
    this->CantEquipos++;
    return;
}
void Acueducto::EliminarEquipo(int n){
    delete this->ListaEquipos[n-1];
    this->CantEquipos--;
    for(int i=n-1;i<this->CantEquipos;i++){
        this->ListaEquipos[i]=this->ListaEquipos[i+1];
    }
    this->ListaEquipos[this->CantEquipos]=NULL;
}
//-------------------------------------
int Acueducto::CantTanque(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Tanque*>(this->ListaDepositos[i]))Cant++;
    }
    return Cant;
}
//los de fibrocemento, 2do los de metal, 3ro los de plástico
int Acueducto::CantTFibro(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
            Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
            if(aux->getMaterial()=="Fibrocemento")Cant++;
        }
    }
    return Cant;
}
int Acueducto::CantTMetal(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
            Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
            if(aux->getMaterial()=="Metal")Cant++;
        }
    }
    return Cant;
}
int Acueducto::CantTPlastico(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
            Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
            if(aux->getMaterial()=="Plastico")Cant++;
        }
    }
    return Cant;
}
int Acueducto::CantCisterna(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Cisterna*>(this->ListaDepositos[i]))Cant++;
    }
    return Cant;
}
int Acueducto::CantCisSimple(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Simple*>(this->ListaDepositos[i]))Cant++;
    }
    return Cant;
}
int Acueducto::CantCisCompuesta(){
    int Cant=0;
    for(int i=0;i<this->CantDepositos;i++){
        if(dynamic_cast<Compuesta*>(this->ListaDepositos[i]))Cant++;
    }
    return Cant;
}
int Acueducto::CantBomba(){
    int Cant=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Bomba*>(this->ListaEquipos[i]))Cant++;
    }
    return Cant;
}
int Acueducto::CantTurbina(){
    int Cant=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Turbina*>(this->ListaEquipos[i]))Cant++;
    }
    return Cant;
}
//----------------------------------------
string Acueducto::DataDeposito(){
    string Data="";
    if(this->CantTanque()>0)Data+=this->DataTanque();
    Data+="\n\n";
    if(this->CantCisterna()>0)Data+=this->DataCisterna();
    return Data;
}
string Acueducto::DataTanque(){
    string Data="";
    if(this->CantTanque()>0){
        Data+="*****  TANQUES  *****\n\n";
        for(int i=0;i<this->CantDepositos;i++){
            if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaDepositos[i]->DataDeposito();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
string Acueducto::DataCisterna(){
    string Data="";
    if(this->CantCisterna()>0){
        Data+="*****  CISTERNAS  *****\n\n";
        for(int i=0;i<this->CantDepositos;i++){
            if(dynamic_cast<Cisterna*>(this->ListaDepositos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaDepositos[i]->DataDeposito();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
string Acueducto::DataCisSimple(){
    string Data="";
    if(this->CantCisSimple()>0){
        Data+="*****  CISTERNAS SIMLES  *****\n\n";
        for(int i=0;i<this->CantDepositos;i++){
            if(dynamic_cast<Simple*>(this->ListaDepositos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaDepositos[i]->DataDeposito();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
string Acueducto::DataCisCompuesta(){
    string Data="";
    if(this->CantCisCompuesta()>0){
        Data+="*****  CISTERNAS COMPUESTAS  *****\n\n";
        for(int i=0;i<this->CantDepositos;i++){
            if(dynamic_cast<Compuesta*>(this->ListaDepositos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaDepositos[i]->DataDeposito();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
string Acueducto::DataEquipo(){
    string Data="";
    if(this->CantBomba()>0)Data+=this->DataBomba();
    Data+="\n\n";
    if(this->CantTurbina()>0)Data+=this->DataTurbina();
    return Data;
}
string Acueducto::DataBomba(){
    string Data="";
    if(this->CantBomba()>0){
        Data+="*****  BOMBAS  *****\n\n";
        for(int i=0;i<this->CantEquipos;i++){
            if(dynamic_cast<Bomba*>(this->ListaEquipos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaEquipos[i]->DataEquipo();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
string Acueducto::DataTurbina(){
    string Data="";
    if(this->CantTurbina()>0){
        Data+="*****  TURBINAS  *****\n\n";
        for(int i=0;i<this->CantEquipos;i++){
            if(dynamic_cast<Turbina*>(this->ListaEquipos[i])){
                Data+="<<<INDEXADO>>>"+to_string(i+1)+"\n";
                Data+=this->ListaEquipos[i]->DataEquipo();
                Data+="-----------------------------\n";
            }
        }
    }
    return Data;
}
//----------------------------------------
void Acueducto::InfoDeposito(int Estado,string Abasto){
    string cond;
    if(Estado>0&&Estado<4){
        if(Estado==1)cond="Bien";
        else if(Estado==2)cond="Regular";
        else if(Estado==3)cond="Mal";
        for(int i=0;i<this->CantDepositos;i++){
            if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
                if(this->ListaDepositos[i]->getEstado()==cond&&this->ListaDepositos[i]->getTipoAbasto()==Abasto){
                    cout<<this->ListaDepositos[i]->DataDeposito();
                    cout<<"----------------------------------------"<<endl;
                }
            }
        }
    }else{
        cout<<"[#] Estado no Valido."<<endl;
    }
}
void Acueducto::InfoOrdenMaterial(){
    if(CantTanque()>0){
        cout<<"***** TANQUES *****\n\n";
        if(this->CantTFibro()>0){
            cout<<"\n*** FIBROCEMENTO ***\n";
            for(int i=0;i<this->CantDepositos;i++){
                if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
                    Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
                    if(aux->getMaterial()=="Fibrocemento"){
                        cout<<"TANQUE "<<i+1<<"==>> "<<aux->getCapacidad()<<endl;
                        cout<<"-----------------------------"<<endl;
                    }
                }
            }
        }
        if(this->CantTMetal()>0){
            cout<<"\n*** METAL ***\n";
            for(int i=0;i<this->CantDepositos;i++){
                if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
                    Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
                    if(aux->getMaterial()=="Metal"){
                        cout<<"TANQUE "<<i+1<<"==>> "<<aux->getCapacidad()<<endl;
                        cout<<"-----------------------------"<<endl;
                    }
                }
            }
        }
        if(this->CantTPlastico()>0){
            cout<<"\n*** PLASTICO ***\n";
            for(int i=0;i<this->CantDepositos;i++){
                if(dynamic_cast<Tanque*>(this->ListaDepositos[i])){
                    Tanque* aux=dynamic_cast<Tanque*>(this->ListaDepositos[i]);
                    if(aux->getMaterial()=="Plastico"){
                        cout<<"TANQUE "<<i+1<<"==>> "<<aux->getCapacidad()<<endl;
                        cout<<"-----------------------------"<<endl;
                    }
                }
            }
        }
    }
    if(this->CantCisterna()>0){
        if(this->CantCisSimple()>0){
            cout<<"\n\n***** CISTERNAS *****\n\n";
            cout<<"*** SIMPLES ***\n";
            for(int i=0;i<this->CantDepositos;i++){
                if(dynamic_cast<Simple*>(this->ListaDepositos[i])){
                    cout<<"CISTERNA: "<<i+1<<"==>> "<<this->ListaDepositos[i]->getCapacidad()<<endl;
                    cout<<"-----------------------------"<<endl;
                }
            }
        }
        if(this->CantCisCompuesta()>0){
            cout<<"\n*** COMPUESTAS ***\n";
            for(int i=0;i<this->CantDepositos;i++){
                if(dynamic_cast<Compuesta*>(this->ListaDepositos[i])){
                    cout<<"CISTERNA: "<<i+1<<"==>> "<<this->ListaDepositos[i]->getCapacidad()<<endl;
                    cout<<"-----------------------------"<<endl;
                }
            }
        }
    }
}
void Acueducto::EquipoMaxRegimen(){
    float MaxBomba=0;float MaxTurbina=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Bomba*>(this->ListaEquipos[i])){
            if(this->ListaEquipos[i]->getRegimen()>MaxBomba)MaxBomba=this->ListaEquipos[i]->getRegimen();
        }else if(dynamic_cast<Turbina*>(this->ListaEquipos[i])){
            if(this->ListaEquipos[i]->getRegimen()>MaxTurbina)MaxBomba=this->ListaEquipos[i]->getRegimen();
        }
    }
    cout<<"[#] Maximo Regimen de Bombas: "<<MaxBomba<<endl;
    if(this-CantBomba()>0){
        for(int i=0;i<this->CantEquipos;i++){
            if(dynamic_cast<Bomba*>(this->ListaEquipos[i])){
                if(this->ListaEquipos[i]->getRegimen()==MaxBomba){
                    cout<<this->ListaEquipos[i]->DataEquipo();
                    cout<<"------------------------------\n";
                }
            }
        }
    }
    cout<<"[#] Maximo Regimen de Turbinas: "<<MaxTurbina<<endl;
    if(this->CantTurbina()>0){
        for(int i=0;i<this->CantEquipos;i++){
            if(dynamic_cast<Turbina*>(this->ListaEquipos[i])){
                if(this->ListaEquipos[i]->getRegimen()==MaxTurbina){
                    cout<<this->ListaEquipos[i]->DataEquipo();
                    cout<<"------------------------------\n";
                }
            }
        }
    }
}
float Acueducto::TiempoPromedioBombaBuenas(){
    float Promedio=0;
    int c=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Bomba*>(this->ListaEquipos[i])){
            Bomba* aux=dynamic_cast<Bomba*>(this->ListaEquipos[i]);
            Promedio+=aux->getTiempo();
            c++;
        }
    }
    Promedio=Promedio/c;
    return Promedio;
}
void Acueducto::EstadoTurbinaMaxFuerza(){
    float MaxFuerza=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Turbina*>(this->ListaEquipos[i])){
            Turbina* aux=dynamic_cast<Turbina*>(this->ListaEquipos[i]);
            if(aux->getFuerza()>MaxFuerza)MaxFuerza=aux->getFuerza();
        }
    }
    cout<<"[#] Maxima Fuerza: "<<MaxFuerza<<endl;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Turbina*>(this->ListaEquipos[i])){
            Turbina* aux=dynamic_cast<Turbina*>(this->ListaEquipos[i]);
            if(aux->getFuerza()==MaxFuerza){
                cout<<"TURBINA: "<<i+1<<" ===>> "<<aux->getEstado()<<endl;
                cout<<"-------------------------------"<<endl;
            }
        }
    }
}
float Acueducto::CapacidadTotalCisternas(string Forma){
    float Total=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Simple*>(this->ListaEquipos[i])){
            Simple* aux=dynamic_cast<Simple*>(this->ListaEquipos[i]);
            if(aux->getForma()==Forma){
                Total+=aux->getCapacidad();
            }
        }
    }
    ofstream out;
    out.open("cisternas.dat");
    out<<"Capacidad Total: "<<Total;
    out.close();
    return Total;
}
float Acueducto::CapacidadTotalCisternas(int Compartimientos){
    float Total=0;
    for(int i=0;i<this->CantEquipos;i++){
        if(dynamic_cast<Compuesta*>(this->ListaEquipos[i])){
            Compuesta* aux=dynamic_cast<Compuesta*>(this->ListaEquipos[i]);
            if(aux->getCantCompartimientos()==Compartimientos){
                Total+=aux->getCapacidad();
            }
        }
    }
    ofstream out;
    out.open("cisternas.dat");
    out<<"Capacidad Total: "<<Total;
    out.close();
    return Total;
}
