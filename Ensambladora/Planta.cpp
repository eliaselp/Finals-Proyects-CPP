#include "Planta.h"
#include <iostream>
Planta::Planta(int MaxMotores,int MaxCarros)
{
    this->MaxMotores=MaxMotores;
    this->MaxCarros=MaxCarros;
    this->CantMotores=0;
    this->CantCarros=0;
    this->ListaCarros=new Vehiculo*[this->MaxCarros];
    this->ListaMotores=new Motor*[this->MaxMotores];
    this->Ganancia=0;
}

Planta::~Planta()
{
    //dtor
}



/********* METODOS GETERS **********/
Motor* Planta::getListaMotores(int n){
    return this->ListaMotores[n-1];
}
int Planta::getMaxMotores(){
    return this->MaxMotores;
}
int Planta::getCantMotores(){
    return this->CantMotores;
}

Vehiculo* Planta::getListaCarros(int n){
    return this->ListaCarros[n-1];
}
int Planta::getMaxCarros(){
    return this->MaxCarros;
}
int Planta::getCantCarros(){
    return this->CantCarros;
}
float Planta::getGanancia(){
    return this->Ganancia;
}


void Planta::setGanancia(float entrada){
    this->Ganancia+=entrada;
    return;
}

/********* METODOS CANT **********/
int Planta::CantFuerza(){
    int Cant=0;
    for(int i=0;i<this->CantMotores;i++){
        if(dynamic_cast<Fuerza*>(this->ListaMotores[i]))Cant++;
    }
    return Cant;
}
int Planta::CantTrabajo(){
    int Cant=0;
    for(int i=0;i<this->CantMotores;i++){
        if(dynamic_cast<Trabajo*>(this->ListaMotores[i]))Cant++;
    }
    return Cant;
}
int Planta::CantArtesanal(){
    int Cant=0;
    for(int i=0;i<this->CantMotores;i++){
        if(dynamic_cast<Trabajo*>(this->ListaMotores[i])){
            Trabajo* aux=dynamic_cast<Trabajo*>(this->ListaMotores[i]);
            if(aux->getArtesanal()==true)Cant++;
        }
    }
    return Cant;
}


int Planta::CantAlta(){
    int Cant=0;
    for(int i=0;i<this->CantMotores;i++){
        if(dynamic_cast<Alta*>(this->ListaMotores[i]))Cant++;
    }
    return Cant;
}

int Planta::CantFormula(){
    int Cant=0;
    for(int i=0;i<this->CantCarros;i++){
        if(dynamic_cast<Formula*>(this->ListaCarros[i]))Cant++;
    }
    return Cant;
}
int Planta::CantBus(){
    int Cant=0;
    for(int i=0;i<this->CantCarros;i++){
        if(dynamic_cast<Bus*>(this->ListaCarros[i]))Cant++;
    }
    return Cant;
}
int Planta::CantDeportivo(){
    int Cant=0;
    for(int i=0;i<this->CantCarros;i++){
        if(dynamic_cast<Deportivo*>(this->ListaCarros[i]))Cant++;
    }
    return Cant;
}
int Planta::CantLujo(){
    int Cant=0;
    for(int i=0;i<this->CantCarros;i++){
        if(dynamic_cast<Lujo*>(this->ListaCarros[i]))Cant++;
    }
    return Cant;
}




/******* METODOS DATA ****/
string Planta::DataMotores(){
    string Data="";
    if(this->CantFuerza()>0)Data+=this->DataFuerza();
    if(this->CantTrabajo()>0)Data+=this->DataTrabajo();
    if(this->CantAlta()>0)Data+=this->DataAlta();
    return Data;
}
string Planta::DataFuerza(){
    string Data="";
    if(this->CantFuerza()>0){
        Data+="******  MOTORES DE FUERZA  ******\n";
        for(int i=0;i<this->CantMotores;i++){
            if(dynamic_cast<Fuerza*>(this->ListaMotores[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaMotores[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}

string Planta::DataTrabajo(){
    string Data="";
    if(this->CantTrabajo()>0){
        Data+="******  MOTORES DE TRABAJO  ******\n";
        for(int i=0;i<this->CantMotores;i++){
            if(dynamic_cast<Trabajo*>(this->ListaMotores[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaMotores[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}
string Planta::DataArtesanal(){
    string Data="";
    if(this->CantArtesanal()>0){
        Data+="******  MOTORES DE TRABAJO ARTESANAL ******\n";
        for(int i=0;i<this->CantMotores;i++){
            if(dynamic_cast<Trabajo*>(this->ListaMotores[i])){
                Trabajo*aux=dynamic_cast<Trabajo*>(this->ListaMotores[i]);
                if(aux->getArtesanal()==true){
                    Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                    Data+="\n";
                    Data+=this->ListaMotores[i]->FichaTecnica();
                    Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
                }
            }
        }
    }
    return Data;
}
string Planta::DataAlta(){
    string Data="";
    if(this->CantAlta()>0){
        Data+="******  MOTORES DE ALTA  ******\n";
        for(int i=0;i<this->CantMotores;i++){
            if(dynamic_cast<Alta*>(this->ListaMotores[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaMotores[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}

string Planta::DataCarros(){
    string Data="";
    if(this->CantFormula()>0)Data+=this->DataFormula()+"\n\n\n";
    if(this->CantBus()>0)Data+=this->DataBus()+"\n\n\n";
    if(this->CantDeportivo()>0)Data+=this->DataDeportivo()+"\n\n\n";
    if(this->CantLujo()>0)Data+=this->DataLujo()+"\n\n\n";
    return Data;
}
string Planta::DataFormula(){
    string Data="";
    if(this->CantFormula()>0){
        Data+="******  VEHICULOS FORMULA 1  ******\n";
        for(int i=0;i<this->CantCarros;i++){
            if(dynamic_cast<Formula*>(this->ListaCarros[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaCarros[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}
string Planta::DataBus(){
    string Data="";
    if(this->CantBus()>0){
        Data+="******  VEHICULOS OMNIBUS  ******\n";
        for(int i=0;i<this->CantCarros;i++){
            if(dynamic_cast<Bus*>(this->ListaCarros[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaCarros[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}
string Planta::DataDeportivo(){
    string Data="";
    if(this->CantDeportivo()>0){
        Data+="******  VEHICULOS DEPORTIVOS  ******\n";
        for(int i=0;i<this->CantCarros;i++){
            if(dynamic_cast<Deportivo*>(this->ListaCarros[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaCarros[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}
string Planta::DataLujo(){
    string Data="";
    if(this->CantLujo()>0){
        Data+="******  VEHICULOS DE LUJO  ******\n";
        for(int i=0;i<this->CantCarros;i++){
            if(dynamic_cast<Lujo*>(this->ListaCarros[i])){
                Data+="<<<<<  INDEXADO  >>>>>  ==>> "+to_string(i+1);
                Data+="\n";
                Data+=this->ListaCarros[i]->FichaTecnica();
                Data+="<><><><><><><><><><><><><><><><><><><><>\n\n";
            }
        }
    }
    return Data;
}


/**** METODOS APILADORES ****/
void Planta::AggVehiculo(Vehiculo* nuevo){
    this->ListaCarros[this->CantCarros]=nuevo;
    this->CantCarros++;
    return;
}
void Planta::ELiminarVehiculo(int n){
    delete this->ListaCarros[n-1];
    this->CantCarros--;
    for(int i=n-1;i<this->CantCarros;i++){
        this->ListaCarros[i]=this->ListaCarros[i+1];
    }
    this->ListaCarros[this->CantCarros]=NULL;
    return;
}
void Planta::AggMotor(Motor* nuevo){
    this->ListaMotores[this->CantMotores]=nuevo;
    this->CantMotores++;
}
void Planta::EliminarMotor(int n){
    delete this->ListaMotores[n-1];
    this->CantMotores--;
    for(int i=n-1;i<this->CantMotores;i++){
        this->ListaMotores[i]=this->ListaMotores[i+1];
    }
    this->ListaMotores[this->CantMotores]=NULL;
    return;
}
void Planta::UtilizarMotor(int m){
    this->ListaMotores[m-1]=NULL;
    this->CantMotores--;
    for(int i=m-1;i<this->CantMotores;i++){
        this->ListaMotores[i]=this->ListaMotores[i+1];
    }
    this->ListaMotores[this->CantMotores]=NULL;
    return;
}
//-----------------------------------------
void Planta::VenderVehiclo(int n){
    this->setGanancia(this->ListaCarros[n-1]->getPrecioVenta());
    ELiminarVehiculo(n);
}
void Planta::DesmantelarVehiculo(int n){
    if(this->CantMotores<this->MaxMotores){
        this->ListaCarros[n-1]->getMotor()->pushRegreso();
        Trabajo* aux=NULL;
        if(dynamic_cast<Trabajo*>(this->ListaCarros[n-1]->getMotor())){
            aux=dynamic_cast<Trabajo*>(this->ListaCarros[n-1]->getMotor());
            aux->setArtesanal();
            if(this->ListaCarros[n-1]->getMotor()->getRegreso()==10)this->EliminarMotor(this->CantMotores);
            else this->AggMotor(this->ListaCarros[n-1]->getMotor());
        }else this->AggMotor(this->ListaCarros[n-1]->getMotor());
        this->ELiminarVehiculo(n);
    }else{
        cout<<"[#] No hay espacio para devolver motor al taller.";
    }
    return;
}


void Planta::CarrosMaxVelocidad(){
    if(this->CantCarros>0){
        for(int i=0;i<this->CantCarros;i++){
            if(this->ListaCarros[i]->getVMax()>=150){
                cout<<ListaCarros[i]->FichaTecnica();
                cout<<"<><><><><><><><><><><><><><><><><>"<<endl;
            }
        }
    }else{
        cout<<"[#] No hay Carros Disponibles."<<endl;
    }
}
void Planta::BusMaxPlazas(){
    if(this->CantCarros>0){
        if(CantBus()>0){
            float Mayor=0;
            for(int i=0;i<this->CantCarros;i++){
                if(dynamic_cast<Bus*>(this->ListaCarros[i])){
                    if(this->ListaCarros[i]->getPlazas()>Mayor)
                        Mayor=this->ListaCarros[i]->getPlazas();
                }
            }
            cout<<"[#] BUS DE MAYOR CAPACIDAD."<<endl;
            for(int i=0;i<this->CantCarros;i++){
                if(dynamic_cast<Bus*>(this->ListaCarros[i])){
                    if(this->ListaCarros[i]->getPlazas()==Mayor){
                        cout<<this->ListaCarros[i]->FichaTecnica();
                        cout<<"<><><><><><><><><><><><><><><><><>"<<endl;
                    }
                }
            }
        }else{
            cout<<"[#] No hay Bus Disponibles."<<endl;
        }
    }else cout<<"[#] No hay Carros Disponibles."<<endl;
    return;
}
void Planta::CarroMotorReensamblado(){
    for(int i=0;i<this->CantCarros;i++){
        if(this->ListaCarros[i]->getMotor()->getRegreso()>0){
            cout<<this->ListaCarros[i]->FichaTecnica();
            cout<<"<><><><><><><><><><><><><><><><><>"<<endl;
        }
    }
    return;
}
