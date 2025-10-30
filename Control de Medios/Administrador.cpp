#include "Administrador.h"
#include <iostream>
using namespace std;
Administrador::Administrador(int MaxMedios)
{
    this->MaxMedios=MaxMedios;
    this->CantReal=0;
    this->ListaMedios=new Medio*[this->MaxMedios];
}

Administrador::~Administrador()
{
    //dtor
}


Medio* Administrador::getListaMedios(int n){
    return this->ListaMedios[n-1];
}
int Administrador::getCantReal(){
    return this->CantReal;
}
int Administrador::getMaxMedios(){
    return this->MaxMedios;
}


void Administrador::AggMedio(Medio* nuevo){
    this->ListaMedios[this->CantReal]=nuevo;
    this->CantReal++;
    return;
}
void Administrador::EliminarMedio(int n){
    delete this->ListaMedios[n-1];
    this->CantReal--;
    for(int i=n-1;i<this->CantReal;i++){
        this->ListaMedios[i]=this->ListaMedios[i+1];
    }
    this->ListaMedios[this->CantReal]=NULL;
    return;
}

void Administrador::CantMarcaxTipo(string Tipo){
    bool existe=false;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()==Tipo)existe=true;
        }
    }
    if(existe==true){
        int pos[this->CantReal];
        int v=0;
        for(int i=0;i<this->CantReal;i++){
            if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
                if(this->ListaMedios[i]->getTipo()==Tipo){
                    pos[v]=i;
                    v++;
                }
            }
        }
        string Marcas[v];
        int p=0;
        int Cant[v];
        for(int i=0;i<v;i++){//recorriendo arreglo de posiciones.
            existe=false;
            int k;
            Electronico* aux=dynamic_cast<Electronico*>(this->ListaMedios[pos[i]]);
            for(int j=0;j<p;j++){//recoriendo arreglod e marca a ver si existe.
                if(aux->getMarca()==Marcas[j]){
                    existe=true;
                    k=j;
                }
            }
            if(existe==true){
                Cant[k]++;
            }else{
                Marcas[p]=aux->getMarca();
                Cant[p]=1;
                p++;
            }
        }
        cout<<"[#] Equipo de Tipo: "<<Tipo<<endl;
        for(int i=0;i<v;i++){
            cout<<"[#] Marca: "<<Marcas[i]<<"  ====>>  "<<Cant[i]<<endl;
        }
    }else  cout<<"[#] No hay Equipo de ese tipo."<<endl;
    return;
}

void Administrador::CantMalEstadoxTipo(){
    int MM=0,ME=0;
    for(int i=0;i<this->CantReal;i++){
        if(this->ListaMedios[i]->getEstado()=="Mal"){
            if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))MM++;
            else if(dynamic_cast<Electronico*>(this->ListaMedios[i]))ME++;
        }
    }
    cout<<"[#] Medios en Mal Estado: "<<endl;
    cout<<"[#] Mobiliario: "<<MM<<endl;
    cout<<"[#] Electronico: "<<ME<<endl;
    cout<<"[#] Total: "<<ME+MM<<endl;
}


void Administrador::MaxMinGarantia(){
    int mayor=0,menor=99999999;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            Electronico* aux=dynamic_cast<Electronico*>(this->ListaMedios[i]);
            if(aux->getGarantia()>mayor){
                mayor=aux->getGarantia();
            }
            if(aux->getGarantia()<menor){
                menor=aux->getGarantia();
            }
        }
    }
    cout<<"[#] Mayor Garantia: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            Electronico* aux=dynamic_cast<Electronico*>(this->ListaMedios[i]);
            if(aux->getGarantia()==mayor){
                aux->INFO();
                cout<<"----------------------"<<endl;
            }
        }
    }
    cout<<"\n\n";
    cout<<"[#] Menor Garantia: "<<endl;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            Electronico* aux=dynamic_cast<Electronico*>(this->ListaMedios[i]);
            if(aux->getGarantia()==menor){
                aux->INFO();
                cout<<"----------------------"<<endl;
            }
        }
    }
    return;
}


void Administrador::Principales_Proveedores(){
    string PE[this->CantReal];
    string PM[this->CantReal];
    int CE[this->CantReal];
    int CM[this->CantReal];
    int M=0,E=0;

    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            bool Existe=false;
            int pe;
            Electronico*aux=dynamic_cast<Electronico*>(this->ListaMedios[i]);
            for(int j=0;j<E;j++){
                if(PE[j]==aux->getProveedor()){
                    Existe=true;pe=j;
                }
            }
            if(Existe==true){
                CE[pe]++;
            }else{
                PE[E]=aux->getProveedor();
                CE[E]=1;
                E++;
            }
        }else{
            Mobiliario* aux=dynamic_cast<Mobiliario*>(this->ListaMedios[i]);
            bool Existe=false;
            int pm;
            for(int j=0;j<M;j++){
                if(PM[j]==aux->getProveedor()){
                    Existe=true;pm=j;
                }
            }
            if(Existe==true){
                CM[pm]++;
            }else{
                PM[M]=aux->getProveedor();
                CM[M]=1;
                M++;
            }
        }
    }

    int MayMob=0,MayElec=0;
    for(int i=0;i<E;i++){
        if(CE[i]>MayElec)MayElec=CE[i];
    }
    for(int i=0;i<M;i++){
        if(CM[i]>MayMob)MayMob=CM[i];
    }
    //////////////////////////////////////
    cout<<"[#] Principales Proveedores:\n\n[#] MEDIOS ELECTRONICOS: \n";
    for(int i=0;i<E;i++){
        if(CE[i]==MayElec){
            cout<<"===>> "<<PE[i]<<endl;
        }
    }
    cout<<"\n\n[#] MEDIOS MOBILIARIO: \n";
    for(int i=0;i<M;i++){
        if(CM[i]==MayMob){
            cout<<"===>> "<<PM[i]<<endl;
        }
    }
    return;
}


string Administrador::CantMueblesxTipo(){
    //silla, mesa, buró, cama, mueble PC
    int silla=0,mesa=0,buro=0,cama=0,mueblepc=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            Mobiliario* aux=dynamic_cast<Mobiliario*>(this->ListaMedios[i]);
            if(aux->getTipo()=="Silla")silla++;
            if(aux->getTipo()=="Mesa")mesa++;
            if(aux->getTipo()=="Buro")buro++;
            if(aux->getTipo()=="Cama")cama++;
            if(aux->getTipo()=="Mueble PC")mueblepc++;
        }
    }
    string Salida="Medios Mobiliarios por Tipo.\n";
    Salida+="[#] Sillas"+to_string(silla)+"\n";
    Salida+="[#] Mesas: "+to_string(mesa)+"\n";
    Salida+="[#] Buro: "+to_string(buro)+"\n";
    Salida+="[#] Cama: "+to_string(cama)+"\n";
    Salida+="[#] Mueble de PC: "+to_string(mueblepc)+"\n";
    cout<<Salida;
    ofstream out;
    out.open("datos.dat");
    out<<Salida;
    out.close();
    return Salida;
}


void Administrador::CostoxTipo(){
    float CM=0,CE=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))CE+=this->ListaMedios[i]->getCostoReal();
        else if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))CM=this->ListaMedios[i]->getCostoReal();
    }
    cout<<"[#] Costo de Medios por tipo.\n";
    cout<<"[#] Mobiliario: "<<CM<<" $"<<endl;
    cout<<"[#] Electronico: "<<CE<<" $"<<endl;
    cout<<"[#] Total: "<<CM+CE<<endl;
    return;
}


void Administrador::CostoPromedioxTipo(){
    float PEquipos[6]={0,0,0,0,0,0};
    int CEquipos[6]={0,0,0,0,0,0};
    float PMuebles[5]={0,0,0,0,0};
    int CMuebles[5]={0,0,0,0,0};
    int TM=0,TE=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            TE++;
            if(this->ListaMedios[i]->getTipo()=="Refrigerador"){
                PEquipos[0]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[0]++;
            }else if(this->ListaMedios[i]->getTipo()=="TV"){
                PEquipos[1]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[1]++;
            }else if(this->ListaMedios[i]->getTipo()=="Video"){
                PEquipos[2]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[2]++;
            }else if(this->ListaMedios[i]->getTipo()=="Ventilador"){
                PEquipos[3]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[3]++;
            }else if(this->ListaMedios[i]->getTipo()=="Aire Acondicionado"){
                PEquipos[4]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[4]++;
            }else if(this->ListaMedios[i]->getTipo()=="Computadora"){
                PEquipos[5]+=this->ListaMedios[i]->getCostoReal();
                CEquipos[5]++;
            }
        }else if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            TM++;
            if(this->ListaMedios[i]->getTipo()=="Silla"){
                PMuebles[0]+=this->ListaMedios[i]->getCostoReal();
                CMuebles[0]++;
            }else if(this->ListaMedios[i]->getTipo()=="Mesa"){
                PMuebles[1]+=this->ListaMedios[i]->getCostoReal();
                CMuebles[1]++;
            }else if(this->ListaMedios[i]->getTipo()=="Buro"){
                PMuebles[2]+=this->ListaMedios[i]->getCostoReal();
                CMuebles[2]++;
            }else if(this->ListaMedios[i]->getTipo()=="Cama"){
                PMuebles[3]+=this->ListaMedios[i]->getCostoReal();
                CMuebles[3]++;
            }else if(this->ListaMedios[i]->getTipo()=="Mueble PC"){
                PMuebles[4]+=this->ListaMedios[i]->getCostoReal();
                CMuebles[4]++;
            }
            //silla, mesa, buró, cama, mueble PC
        }
    }
    if(TE>0){
        cout<<"[#] Medios Electronicos: "<<endl;
        float f;
        if(CEquipos[0]>0){
            f=PEquipos[0]/CEquipos[0];
            cout<<"===>> Refrigeradores  # "<<f<<" $"<<endl;
        }if(CEquipos[1]>0){
            f=PEquipos[1]/CEquipos[1];
            cout<<"===>> TV  # "<<f<<" $"<<endl;
        }if(CEquipos[2]>0){
            f=PEquipos[2]/CEquipos[2];
            cout<<"===>> Video  # "<<f<<" $"<<endl;
        }if(CEquipos[3]>0){
            f=PEquipos[3]/CEquipos[3];
            cout<<"===>> Ventilador  # "<<f<<" $"<<endl;
        }if(CEquipos[4]>0){
            f=PEquipos[4]/CEquipos[4];
            cout<<"===>> Aire Acondicionado  # "<<f<<" $"<<endl;
        }if(CEquipos[5]>0){
            f=PEquipos[5]/CEquipos[5];
            cout<<"===>> Computadora  # "<<f<<" $"<<endl;
        }
        //refrigerador, TV, video, ventilador, aire acondicionado, computadora
    }
    if(TM>0){
        cout<<"\n\n[#] Medios Mobiliarios: "<<endl;
        float f;
        if(CMuebles[0]>0){
            f=PMuebles[0]/PMuebles[0];
            cout<<"===>> Sillas  # "<<f<<" $"<<endl;
        }else if(CMuebles[1]>0){
            f=PMuebles[1]/PMuebles[1];
            cout<<"===>> Mesas  # "<<f<<" $"<<endl;
        }else if(CMuebles[2]>0){
            f=PMuebles[2]/PMuebles[2];
            cout<<"===>> Buro  # "<<f<<" $"<<endl;
        }else if(CMuebles[3]>0){
            f=PMuebles[3]/PMuebles[3];
            cout<<"===>> Cama  # "<<f<<" $"<<endl;
        }else if(CMuebles[4]>0){
            f=PMuebles[4]/PMuebles[4];
            cout<<"===>> Muebles PC  # "<<f<<" $"<<endl;
        }
        //silla, mesa, buró, cama, mueble PC
    }
    return;
}


int Administrador::CantMobiliario(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))Cant++;
    }
    return Cant;
}
int Administrador::CantSilla(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Silla")Cant++;
    }
    return Cant;
}
int Administrador::CantMesa(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Mesa")Cant++;
    }
    return Cant;
}
int Administrador::CantBuro(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Buro")Cant++;
    }
    return Cant;
}
int Administrador::CantCama(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Cama")Cant++;
    }
    return Cant;
}
int Administrador::CantMueblePC(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Mueble PC")Cant++;
    }
    return Cant;
}

int Administrador::CantElectronico(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            Cant++;
    }
    return Cant;
}
int Administrador::CantRefrigerador(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Refrigerador")Cant++;
    }
    return Cant;
}
int Administrador::CantTV(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="TV")Cant++;
    }
    return Cant;
}
int Administrador::CantVideo(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Video")Cant++;
    }
    return Cant;
}
int Administrador::CantVentilador(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Ventilador")Cant++;
    }
    return Cant;
}
int Administrador::CantAireAcondicionado(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Aire Acondicionado")Cant++;
    }
    return Cant;
}
int Administrador::CantComputadora(){
    int Cant=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Computadora")Cant++;
    }
    return Cant;
}

void Administrador::DataElectronico(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i])){
            cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
            this->ListaMedios[i]->INFO();
        }
    }
}
void Administrador::DataRefrigerador(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Refrigerador"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}
void Administrador::DataTV(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="TV"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}
void Administrador::DataVideo(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Video"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}
void Administrador::DataVentilador(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Ventilador"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}
void Administrador::DataAireAcondicionado(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Aire Acondicionado"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}
void Administrador::DataComputadora(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Electronico*>(this->ListaMedios[i]))
            if(this->ListaMedios[i]->getTipo()=="Computadora"){
                cout<<"<<<<INDEXADO>>>> ==>> "<<i+1<<endl;
                this->ListaMedios[i]->INFO();
            }
    }
}



void Administrador::DataMobiliario(){
    //silla, mesa, buró, cama, mueble PC
    if(this->CantSilla()>0){
        cout<<"####  SILLAS  ####"<<endl;
        this->DataSilla();
        cout<<"\n\n\n"<<endl;
    }
    if(this->CantMesa()>0){
        cout<<"####  MESAS  ####"<<endl;
        this->DataMesa();
        cout<<"\n\n\n"<<endl;
    }
    if(this->CantBuro()>0){
        cout<<"####  BURO  ####"<<endl;
        this->DataBuro();
        cout<<"\n\n\n"<<endl;
    }
    if(this->CantCama()>0){
        cout<<"####  CAMAS  ####"<<endl;
        this->DataCama();
        cout<<"\n\n\n"<<endl;
    }
    if(this->CantMueblePC()>0){
        cout<<"####  MUEBLES DE PC  ####"<<endl;
        this->DataMueblePC();
        cout<<"\n\n\n"<<endl;
    }
    //silla, mesa, buró, cama, mueble PC
}
void Administrador::DataSilla(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()=="Silla"){
                this->ListaMedios[i]->INFO();
                cout<<"---------------------------------"<<endl;
            }
        }
    }
}
void Administrador::DataMesa(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()=="Mesa"){
                this->ListaMedios[i]->INFO();
                cout<<"---------------------------------"<<endl;
            }
        }
    }
}
void Administrador::DataBuro(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()=="Buro"){
                this->ListaMedios[i]->INFO();
                cout<<"---------------------------------"<<endl;
            }
        }
    }
}
void Administrador::DataCama(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()=="Cama"){
                this->ListaMedios[i]->INFO();
                cout<<"---------------------------------"<<endl;
            }
        }
    }
}
void Administrador::DataMueblePC(){
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Mobiliario*>(this->ListaMedios[i])){
            if(this->ListaMedios[i]->getTipo()=="Mueble PC"){
                this->ListaMedios[i]->INFO();
                cout<<"---------------------------------"<<endl;
            }
        }
    }
}
