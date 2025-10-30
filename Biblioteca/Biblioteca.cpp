#include "Biblioteca.h"
#include <iostream>
using namespace std;
Biblioteca::Biblioteca(int MaxClientes,int MaxMateriales,int MaxPedidos,float MaxPeso)
{
    this->MaxClientes=MaxClientes;
    this->MaxMateriales=MaxMateriales;
    this->MaxPedidos=MaxPedidos;
    this->MaxPeso=MaxPeso;
    this->CantClientes=0;
    this->CantMateriales=0;
    this->CantPedidos=0;
    this->ListaClientes=new Usuario*[MaxClientes];
    this->ListaMateriales=new Material*[MaxMateriales];
    this->ListaPedidos=new Pedido*[MaxPedidos];
    this->ArchivoHistorico="";
    this->CantHistorico=0;
}

Biblioteca::~Biblioteca()
{
    //dtor
}





/************************************************************/
/************ METODOS GETERS ******************************/
/**********************************************************/
float Biblioteca::getMaxPeso(){
    return this->MaxPeso;
}

int Biblioteca::getMaxClientes(){
    return this->MaxClientes;
}
int Biblioteca::getCantClientes(){
    return this->CantClientes;
}
Usuario* Biblioteca::getListaClientes(int n){
    return this->ListaClientes[n-1];
}

int Biblioteca::getMaxMateriales(){
    return this->MaxMateriales;
}
int Biblioteca::getCantMateriales(){
    return this->CantMateriales;
}
Material* Biblioteca::getListaMateriales(int n){
    return this->ListaMateriales[n-1];
}

int Biblioteca::getMaxPedidos(){
    return this->MaxPedidos;
}
int Biblioteca::getCantPedidos(){
    return this->CantPedidos;
}
Pedido* Biblioteca::getListaPedidos(int n){
    return this->ListaPedidos[n-1];
}
int Biblioteca::getCantHistorico(){
    return this->CantHistorico;
}
string Biblioteca::getArchivoHistorico(){
    return this->ArchivoHistorico;
}

void Biblioteca::setArchivoHistorico(string Data){
    this->ArchivoHistorico=Data;
    return;
}
void Biblioteca::setCantHistorico(int CantHistorico){
    this->CantClientes=CantHistorico;
    return;
}
/************************************************************/
/************ METODOS CANTS ******************************/
/**********************************************************/
int Biblioteca::CantMaterialesDisponibles(){
    int Cant=0;
    for(int i=0;i<this->CantMateriales;i++){
        if(this->ListaMateriales[i]->getPrestado()==false)Cant++;
    }
    return Cant;
}
int Biblioteca::CantLibros(){
    int Cant=0;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Libro*>(this->ListaMateriales[i]))Cant++;
    }
    return Cant;
}
int Biblioteca::CantComun(){
    int Cant=0;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Comun*>(this->ListaMateriales[i]))Cant++;
    }
    return Cant;
}
int Biblioteca::CantInfantil(){
    int Cant=0;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Infantil*>(this->ListaMateriales[i]))Cant++;
    }
    return Cant;
}
int Biblioteca::CantRevista(){
    int Cant=0;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Revista*>(this->ListaMateriales[i]))Cant++;
    }
    return Cant;
}
int Biblioteca::CantPrestamoUsuario(string CI){
    int Cant=0;
    for(int i=0;i<this->CantPedidos;i++){
        if(this->ListaPedidos[i]->getCliente()->getCI()==CI)Cant++;
    }
    return Cant++;
}
int Biblioteca::CantEventuales(){
    int Cant=0;
    for(int i=0;i<this->CantClientes;i++){
        if(this->ListaClientes[i]->getTipo()=="EVENTUAL")Cant++;
    }
    return Cant;
}





/************************************************************/
/************ METODOS DATA ******************************/
/**********************************************************/
void Biblioteca::DataLibros(){
    cout<<"*****  LIBROS  *****"<<endl<<endl;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Libro*>(this->ListaMateriales[i])){
            if(this->ListaMateriales[i]->getPrestado()==false){
                cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
                this->ListaMateriales[i]->DataMaterial();
                cout<<"--------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Biblioteca::DataComun(){
    cout<<"*****  LIBROS PARA ADULTOS  *****"<<endl<<endl;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Comun*>(this->ListaMateriales[i])){
            if(this->ListaMateriales[i]->getPrestado()==false){
                cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
                this->ListaMateriales[i]->DataMaterial();
                cout<<"--------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Biblioteca::DataInfantil(){
    cout<<"*****  LIBROS INFANTILES  *****"<<endl<<endl;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Infantil*>(this->ListaMateriales[i])){
            if(this->ListaMateriales[i]->getPrestado()==false){
                cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
                this->ListaMateriales[i]->DataMaterial();
                cout<<"--------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Biblioteca::DataRevista(){
    cout<<"*****  REVISTAS  *****"<<endl<<endl;
    for(int i=0;i<this->CantMateriales;i++){
        if(dynamic_cast<Revista*>(this->ListaMateriales[i])){
            if(this->ListaMateriales[i]->getPrestado()==false){
                cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
                this->ListaMateriales[i]->DataMaterial();
                cout<<"--------------------------------------------"<<endl;
            }
        }
    }
    return;
}
void Biblioteca::DataMateriales(){
    for(int i=0;i<this->CantMateriales;i++){
        if(this->ListaMateriales[i]->getPrestado()==false){
            cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
            if(dynamic_cast<Revista*>(this->ListaMateriales[i]))cout<<"[#] TIPO: Revista"<<endl;
            else if(dynamic_cast<Comun*>(this->ListaMateriales[i]))cout<<"[#] TIPO: Libro para Adultos."<<endl;
            else if(dynamic_cast<Infantil*>(this->ListaMateriales[i]))cout<<"[#] TIPO: Libro Infantil."<<endl;
            this->ListaMateriales[i]->DataMaterial();
            cout<<"--------------------------------------------"<<endl;
        }
    }
    return;
}

void Biblioteca::DataMateriales(string Codigo){
    bool Existe=false;
    int pos;
    for(int i=0;i<this->CantMateriales;i++){
        if(this->ListaMateriales[i]->getCodigo()==Codigo){
            Existe=true;
            pos=i;
        }
    }
    if(Existe==true){
        cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<pos<<endl;
        if(dynamic_cast<Revista*>(this->ListaMateriales[pos]))cout<<"[#] TIPO: Revista"<<endl;
        else if(dynamic_cast<Comun*>(this->ListaMateriales[pos]))cout<<"[#] TIPO: Libro para Adultos."<<endl;
        else if(dynamic_cast<Infantil*>(this->ListaMateriales[pos]))cout<<"[#] TIPO: Libro Infantil."<<endl;
        this->ListaMateriales[pos]->DataMaterial();
    }else{
        cout<<"[#] El Material no esta Registrado."<<endl;
    }
}
void Biblioteca::DataPrestamo(string CI){
    bool Existe=false;
    for(int i=0;i<this->CantClientes;i++){
        if(this->ListaClientes[i]->getCI()==CI)Existe=true;
    }
    if(Existe==true){
        if(this->CantPrestamoUsuario(CI)>0){
            for(int i=0;i<this->CantPedidos;i++){
                if(this->ListaPedidos[i]->getCliente()->getCI()==CI){
                    cout<<"<<<<  INDEXADO  >>>>  --->>>> "<<i+1<<endl;
                    if(dynamic_cast<Revista*>(this->ListaPedidos[i]->getDoc()))cout<<"[#] TIPO: Revista"<<endl;
                    else if(dynamic_cast<Comun*>(this->ListaPedidos[i]->getDoc()))cout<<"[#] TIPO: Libro para Adultos."<<endl;
                    else if(dynamic_cast<Infantil*>(this->ListaPedidos[i]->getDoc()))cout<<"[#] TIPO: Libro Infantil."<<endl;
                    this->ListaPedidos[i]->getDoc()->DataMaterial();
                    cout<<"---------------------------------------"<<endl;
                }
            }
        }else{
            cout<<"[#] El cliente no ha realizado Pedidos."<<endl;
        }
    }else{
        cout<<"[#] El Cliente no esta Registrado."<<endl;
    }
    return;
}
void Biblioteca::DataEventual(){
    for(int i=0;i<this->CantClientes;i++){
        if(this->ListaClientes[i]->getTipo()=="EVENTUAL"){
            cout<<"<<<<  INDEXADO  >>>>  ---->>> "<<i+1<<endl;
            cout<<this->ListaClientes[i]->DataUsuario();
            cout<<"----------------------------------------"<<endl;
        }
    }
    return;
}
void Biblioteca::DataClientes(){
    for(int i=0;i<this->CantClientes;i++){
        cout<<"<<<<  INDEXADO  >>>>  ---->>> "<<i+1<<endl;
        cout<<this->ListaClientes[i]->DataUsuario();
        cout<<"----------------------------------------"<<endl;
    }
    return;
}





//---------------------------------------------------------
void Biblioteca::AggCliente(Usuario* nuevo){
    this->ListaClientes[this->CantClientes]=nuevo;
    this->CantClientes++;
    return;
}
void Biblioteca::EliminarCliente(int n){
    bool del=false;
    for(int i=0;i<this->CantPedidos;i++){
        if(del==true){
            i--;
            del=false;
        }
        if(this->ListaPedidos[i]->getCliente()==this->getListaClientes(n)){
            del=true;
            this->HacerEntrega(i);
        }
    }

    delete this->getListaClientes(n);
    this->CantClientes--;
    for(int i=n-1;i<this->CantClientes;i++){
        this->ListaClientes[i]=this->ListaClientes[i+1];
    }
    this->ListaClientes[this->CantClientes]=NULL;
    return;
}
void Biblioteca::AggHistorial(int n){
    if(this->getListaClientes(n)->getTipo()=="EVENTUAL"){
        this->ArchivoHistorico+=this->ListaClientes[n-1]->DataUsuario();
        this->CantHistorico++;
        this->EliminarCliente(n);
    }else{
        cout<<"[#] El Cliente no es EVENTUAL."<<endl;
    }
    return;
}

void Biblioteca::AggMaterial(Material* nuevo){
    this->ListaMateriales[this->CantMateriales]=nuevo;
    this->CantMateriales++;
    return;
}
void Biblioteca::EliminarMaterial(int n){
    if(this->getListaMateriales(n)->getPrestado()==false){
        delete this->ListaMateriales[n-1];
        this->CantMateriales--;
        for(int i=n-1;i<this->CantMateriales;i++){
            this->ListaMateriales[i]=this->ListaMateriales[i+1];
        }
        this->ListaMateriales[this->CantMateriales]=NULL;
        return;
    }else{
        cout<<"[#] El Material esta Prestado."<<endl;
    }
}

void Biblioteca::setMaxPeso(float MaxPeso){
    this->MaxPeso=MaxPeso;
    return;
}

void Biblioteca::RealizarPedido(int n, int m){
    Usuario* Cliente=this->getListaClientes(n);
    Material* Doc=this->getListaMateriales(m);
    float p=Cliente->PesoAcumulado+Doc->getPesoAsociado();
    if(p<this->MaxPeso){
        Cliente->PesoAcumulado=p;
        Doc->setPrestado(true);
        Doc->Prestamos++;
        Doc->setFactorEstancia();
        Pedido* salida= new Pedido(Cliente,Doc);
        this->ListaPedidos[this->CantPedidos]=salida;
        this->CantPedidos++;
    }else{
        cout<<"[#] Peso Excedido."<<endl;
    }
    return;
}

void Biblioteca::HacerEntrega(int m){
    m--;
    this->ListaPedidos[m]->getDoc()->setPrestado(false);
    this->ListaPedidos[m]->getCliente()->PesoAcumulado-=this->ListaPedidos[m]->getDoc()->getPesoAsociado();
    this->ListaPedidos[m]->getDoc()->setPesoAsociado();
    delete this->ListaPedidos[m];
    this->CantPedidos--;
    for(int i=m;i<this->CantPedidos;i++){
        this->ListaPedidos[i]=this->ListaPedidos[i+1];
    }
    this->ListaPedidos[this->CantPedidos]=NULL;
    return;
}
