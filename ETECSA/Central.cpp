#include "Central.h"
#include <iostream>
using namespace std;
Central::Central(int CantPaises, int TeleseleccionInternacional,int TeleseleccionProvincial)
{
    this->ListaClientes=NULL;
    this->CantClientes=0;
    this->CantPaises=CantPaises;
    this->TeleseleccionInternacional=TeleseleccionInternacional;
    this->TeleseleccionProvincial=TeleseleccionProvincial;
    this->CantLlamadas=0;
    this->Registro=NULL;
    this->CodigoPaises=new int[this->CantPaises];
    this->Tarifas=new float[this->CantPaises];
    for(int i=0;i<this->CantPaises;i++){
        cout<<"[+] Codigo del Pais "<<i+1<<": ";
        cin>>this->CodigoPaises[i];
        cout<<"[+] Tarifa: ";
        cin>>this->Tarifas[i];
        system("cls");
    }
}

Central::~Central()
{
    //dtor
}





/*************************************************************/
/***********  METODOS GETERS    ***************************/
/*********************************************************/
Cliente* Central::getCliente(int n){
    Cliente*aux=this->ListaClientes;
    for(int i=1;i<n;i++){
        aux=aux->siguiente;
    }
    return aux;
}
int Central::getCantClientes(){
    return this->CantClientes;
}

int Central::getCantPaises(){
    return this->CantPaises;
}
int Central::getCantLlamadas(){
    return this->CantLlamadas;
}
int Central::getTeleseleccionInternacional(){
    return this->TeleseleccionInternacional;
}
int Central::getTeleseleccionProvincial(){
    return this->TeleseleccionInternacional;
}






/*************************************************************/
/***********  METODOS BUSCADORES    ***************************/
/*********************************************************/
bool Central::BuscarPais(int Code){
    for(int i=0;i<this->CantPaises;i++){
        if(this->CodigoPaises[i]==Code)return true;
    }
    return false;
}
int Central::getPosPais(int Code){
    for(int i=0;i<this->CantPaises;i++){
        if(this->CodigoPaises[i]==Code)return i;
    }
    return -1;
}
float Central::getTarifa(int n){
    return this->Tarifas[n];
}








/*************************************************************/
/***********  METODOS APILADORES    ***************************/
/*********************************************************/
void Central::AggCliente(Cliente* nuevo){
    if(this->ListaClientes==NULL){
        nuevo->siguiente=NULL;
    }else{
        nuevo->siguiente=this->ListaClientes;
    }
    this->ListaClientes=nuevo;
    this->CantClientes++;
    return;
}

void Central::BanearCliente(int n){
    this->getCliente(n)->Estado="BANEADO";
    return;
}

void Central::ActivarCliente(int n){
    this->getCliente(n)->Estado="ACTIVO";
    return;
}

void Central::AggLlamada(Llamada* nueva){
    if(this->Registro==NULL){
        nueva->siguiente=NULL;
    }else{
        nueva->siguiente=this->Registro;
    }
    this->Registro=nueva;
}




/*************************************************************/
/***********  METODOS CANT    ***************************/
/*********************************************************/
int Central::CantActivos(){
    int Cant=0;
    Cliente* aux=this->ListaClientes;
    while(aux!=NULL){
        if(aux->Estado=="ACTIVO")Cant++;
        aux=aux->siguiente;
    }
    return Cant;
}
int Central::CantBaneados(){
    int Cant=0;
    Cliente* aux=this->ListaClientes;
    while(aux!=NULL){
        if(aux->Estado=="BANEADO")Cant++;
        aux=aux->siguiente;
    }
    return Cant;
}

int Central::CantEstatalAct(){
    Cliente* aux=this->ListaClientes;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Estatal*>(aux)){
            if(aux->Estado=="ACTIVO")cant++;
        }
        aux=aux->siguiente;
    }
    return cant;
}
int Central::CantResidencialAct(){
    Cliente* aux=this->ListaClientes;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Residencial*>(aux)){
            if(aux->Estado=="ACTIVO")cant++;
        }
        aux=aux->siguiente;
    }
    return cant;
}
int Central::CantEstatalIN(){
    Cliente* aux=this->ListaClientes;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Estatal*>(aux)){
            if(aux->Estado=="BANEADO")cant++;
        }
        aux=aux->siguiente;
    }
    return cant;
}
int Central::CantResidencialIN(){
    Cliente* aux=this->ListaClientes;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Residencial*>(aux)){
            if(aux->Estado=="BANEADO")cant++;
        }
        aux=aux->siguiente;
    }
    return cant;
}

int Central::CantInternacional(){
    Llamada* aux=this->Registro;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Internacional*>(aux))cant++;
        aux=aux->siguiente;
    }
    return cant;
}
int Central::CantNacional(){
    Llamada* aux=this->Registro;
    int cant=0;
    while(aux!=NULL){
        if(dynamic_cast<Nacional*>(aux))cant++;
        aux=aux->siguiente;
    }
    return cant;
}




/*************************************************************/
/***********  METODOS DATA    ***************************/
/*********************************************************/
void Central::DataClientes(){
    this->DataActivo();
    this->DataInactivo();
    return;
}
void Central::DataActivo(){
    if(this->CantEstatalAct()>0){
        cout<<"--------------------------------------"<<endl;
        cout<<"--------- Clientes Estatales ---------"<<endl;
        cout<<"--------------------------------------"<<endl;
        this->DataEstatalACT();
    }
    if(this->CantResidencialAct()>0){
        cout<<"------------------------------------------"<<endl;
        cout<<"--------- Clientes Residenciales ---------"<<endl;
        cout<<"------------------------------------------"<<endl;
        this->DataResidencialACT();
    }
    return;
}
void Central::DataInactivo(){
    if(this->CantEstatalIN()>0){
        cout<<"--------------------------------------"<<endl;
        cout<<"--------- Clientes Estatales ---------"<<endl;
        cout<<"--------------------------------------"<<endl;
        this->DataEstatalIN();
    }
    if(this->CantResidencialIN()>0){
        cout<<"------------------------------------------"<<endl;
        cout<<"--------- Clientes Residenciales ---------"<<endl;
        cout<<"------------------------------------------"<<endl;
        this->DataResidencialIN();
    }
    return;
}

void Central::DataEstatalACT(){
    if(this->CantEstatalAct()>0){
        int i=1;
        Cliente*aux=this->ListaClientes;
        while(aux!=NULL){
            if(dynamic_cast<Estatal*>(aux)){
                if(aux->Estado=="ACTIVO"){
                    cout<<"[#] <<<< INDEXADO >>>> "<<i<<endl;
                    aux->DataCliente();
                    cout<<"-------------------------------------------------------------"<<endl<<endl;
                }
            }
            i++;
            aux=aux->siguiente;
        }
    }
    return;
}

void Central::DataResidencialACT(){
    if(this->CantResidencialAct()>0){
        int i=1;
        Cliente*aux=this->ListaClientes;
        while(aux!=NULL){
            if(dynamic_cast<Residencial*>(aux)){
                if(aux->Estado=="ACTIVO"){
                    cout<<"[#] <<<< INDEXADO >>>> "<<i<<endl;
                    aux->DataCliente();
                    cout<<"-------------------------------------------------------------"<<endl<<endl;
                }
            }
            i++;
            aux=aux->siguiente;
        }
    }
    return;
}
void Central::DataEstatalIN(){
    if(this->CantEstatalIN()>0){
        int i=1;
        Cliente*aux=this->ListaClientes;
        while(aux!=NULL){
            if(dynamic_cast<Estatal*>(aux)){
                if(aux->Estado=="BANEADO"){
                    cout<<"[#] <<<< INDEXADO >>>> "<<i<<endl;
                    aux->DataCliente();
                    cout<<"-------------------------------------------------------------"<<endl<<endl;
                }
            }
            i++;
            aux=aux->siguiente;
        }
    }
    return;
}
void Central::DataResidencialIN(){
    if(this->CantResidencialIN()>0){
        int i=1;
        Cliente*aux=this->ListaClientes;
        while(aux!=NULL){
            if(dynamic_cast<Residencial*>(aux)){
                if(aux->Estado=="BANEADO"){
                    cout<<"[#] <<<< INDEXADO >>>> "<<i<<endl;
                    aux->DataCliente();
                    cout<<"-------------------------------------------------------------"<<endl<<endl;
                }
            }
            i++;
            aux=aux->siguiente;
        }
    }
    return;
}


////////////////////////////////////////////////////////////

void Central::DataRegistro(){
    Llamada* aux=this->Registro;
    while(aux!=NULL){
        aux->DataLlamada();
        cout<<"---------------------------------------"<<endl;
        aux=aux->siguiente;
    }
    return;
}
void Central::DataInternacional(){
    Llamada* aux=this->Registro;
    while(aux!=NULL){
        if(dynamic_cast<Internacional*>(aux)){
            aux->DataLlamada();
            cout<<"---------------------------------------"<<endl;
        }
        aux=aux->siguiente;
    }
    return;
}
void Central::DataNacional(){
    Llamada* aux=this->Registro;
    while(aux!=NULL){
        if(dynamic_cast<Nacional*>(aux)){
            aux->DataLlamada();
            cout<<"---------------------------------------"<<endl;
        }
        aux=aux->siguiente;
    }
    return;
}

/*************************************************************/
/***********  METODOS PEDIDOS    ***************************/
/*********************************************************/
float Central::Deuda(int n){
    Llamada* aux=this->Registro;
    Cliente* aux2=this->getCliente(n);
    int suma=0;
    while(aux!=NULL){
        if(aux->getEmisor()==aux2){
            if(dynamic_cast<Nacional*>(aux)){
                Nacional* aux3=dynamic_cast<Nacional*>(aux);
                if(aux3->getCodigoProvinciaReceptor()==aux3->getEmisor()->getCodigoProvincia()){
                    suma+=aux3->getDuracion();
                }
            }
        }
        aux=aux->siguiente;
    }
    suma-=300;
    float D=aux->getEmisor()->getGasto();
    if(suma>0){
        D-=suma*0.05/3;
        D+=suma*0.05;
    }
    return D;
}


void Central::RunRastreo(int n){
    Llamada* aux=this->Registro;
    Cliente* aux2=this->getCliente(n);
    while(aux!=NULL){
        if(aux->getEmisor()==aux2){
            aux->DataLlamada();
            cout<<"------------------------------------------"<<endl;
        }
        aux=aux->siguiente;
    }
    return;
}


void Central::ClienteEspecial(){
    Cliente*aux=this->ListaClientes;
    float Mayor=0;
    while(aux!=NULL){
        if(aux->getGasto()>Mayor){
            Mayor=aux->getGasto();
        }
        aux=aux->siguiente;
    }
    aux=this->ListaClientes;
    while(aux!=NULL){
        if(aux->getGasto()==Mayor){
            aux->DataCliente();
            cout<<"---------------------------------"<<endl;
        }
        aux=aux->siguiente;
    }
    return;
}
void Central::ListadoClientesTeleseleccion(){
    Cliente**Lista=new Cliente*[this->CantClientes];
    Llamada* aux=this->Registro;
    float Cobro[this->CantClientes];
    int CantReal=0;
    bool Tele=false;
    while(aux!=NULL){
        if(dynamic_cast <Internacional*>(aux)){
            Tele=true;
        }else if(dynamic_cast<Nacional*>(aux)){
            Nacional* aux2=dynamic_cast<Nacional*>(aux);
            if(aux2->getCodigoProvinciaReceptor()!=aux2->getEmisor()->getCodigoProvincia()){
                Tele=true;
            }
        }
        if(Tele==true){
            int pos=-1;
            for(int j=0;j<CantReal;j++){
                if(Lista[j]==aux->getEmisor())pos=j;
            }
            if(pos!=-1){
                Cobro[pos]+=aux->getPrecio();
            }else{
                Lista[CantReal]=aux->getEmisor();
                Cobro[CantReal]=aux->getPrecio();
            }
            Tele=false;
        }
        aux=aux->siguiente;
    }
    for(int i=0;i<CantReal;i++){
        Lista[i]->DataCliente();
        cout<<"[#] Cobro: "<<Cobro[i];
    }
}
