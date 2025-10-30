#include "Office.h"
#include <iostream>
using namespace std;
Office::Office(int MaxBuzon)
{
    this->MaxBuzon=MaxBuzon;
    this->CantBuzon=0;
    this->Buzon=new Correspondencia*[MaxBuzon];
    this->Ganancia=0;
}

Office::~Office()
{
    //dtor
}






/******************************************************************/
/********** METODOS GETERS  **************************************/
/*********************************************************************/
Correspondencia* Office::getBuzon(int n){
    return this->Buzon[n];
}
int Office::getCantBuzon(){
    return this->CantBuzon;
}
int Office::getMaxBuzon(){
    return this->MaxBuzon;
}
float Office::getGanancia(){
    return Ganancia;
}



/******************************************************************/
/********** METODOS SETERS  **************************************/
/*********************************************************************/
void Office::setGanancia(){
    float Suma=0;
    for(int i=0;i<this->CantBuzon;i++){
        Suma+=this->Buzon[i]->getCosto();
    }
    this->Ganancia+=Suma;
}




/******************************************************************/
/********** METODOS APILADORES **************************************/
/*********************************************************************/
void Office::AggCorrespondencia(Correspondencia* nueva){
    this->Buzon[this->CantBuzon]=nueva;
    this->CantBuzon++;
    this->setGanancia();
    return;
}







/******************************************************************/
/********** METODOS Cants **************************************/
/*********************************************************************/
int Office::CantCarta(){
    int cont=0;
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Carta*>(this->Buzon[i])){
            cont++;
        }
    }
    return cont;
}
int Office::CantTelegrama(){
    int cont=0;
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Telegrama*>(this->Buzon[i])){
            cont++;
        }
    }
    return cont;
}
int Office::CantBulto(){
    int cont=0;
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Bulto*>(this->Buzon[i])){
            cont++;
        }
    }
    return cont;
}


/******************************************************************/
/********** METODOS Pedidos **************************************/
/*********************************************************************/
void Office::DespacharCorrespondencia(){
    if(this->CantBuzon>0){
        if(this->CantTelegrama()>0){
            bool Salto=false;
            for(int i=0;i<this->CantBuzon;i++){
                if(Salto==true){
                        i--;
                        Salto=false;
                }
                if(dynamic_cast<Telegrama*>(this->Buzon[i])){
                        Salto=true;
                        this->Buzon[i]->DataCorrespondencia();
                        delete Buzon[i];
                        this->CantBuzon--;
                        for(int j=i;j<this->CantBuzon;j++){
                            this->Buzon[j]=this->Buzon[j+1];
                        }
                        Buzon[this->CantBuzon]=NULL;
                        cout<<"\n\n[#] >>>>> Entregado."<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                }
            }
        }
        if(this->CantCarta()>0){
            bool Salto=false;
            for(int i=0;i<this->CantBuzon;i++){
                if(Salto==true){
                        i--;
                        Salto=false;
                }
                if(dynamic_cast<Carta*>(this->Buzon[i])){
                        Salto=true;
                        this->Buzon[i]->DataCorrespondencia();
                        delete Buzon[i];
                        this->CantBuzon--;
                        for(int j=i;j<this->CantBuzon;j++){
                            this->Buzon[j]=Buzon[j+1];
                        }
                        Buzon[this->CantBuzon]=NULL;
                        cout<<"\n\n[#] >>>>> Entregado."<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                }
            }
        }
        if(this->CantBulto()>0){
            bool Salto=false;
            for(int i=0;i<this->CantBuzon;i++){
                if(Salto==true){
                        i--;
                        Salto=false;
                }
                if(dynamic_cast<Bulto*>(this->Buzon[i])){
                    Bulto* aux=dynamic_cast<Bulto*>(this->Buzon[i]);
                    if(aux->getUrgencia()==1){
                        Salto=true;
                        this->Buzon[i]->DataCorrespondencia();
                        delete Buzon[i];
                        this->CantBuzon--;
                        for(int j=i;j<this->CantBuzon;j++){
                            this->Buzon[j]=Buzon[j+1];
                        }
                        Buzon[this->CantBuzon]=NULL;
                        cout<<"\n\n[#] >>>>> Entregado."<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                    }
                }
            }
        }
        if(this->CantBulto()>0){
            bool Salto=false;
            for(int i=0;i<this->CantBuzon;i++){
                if(Salto==true){
                        i--;
                        Salto=false;
                }
                if(dynamic_cast<Bulto*>(this->Buzon[i])){
                    Bulto* aux=dynamic_cast<Bulto*>(this->Buzon[i]);
                    if(aux->getUrgencia()==2){
                        Salto=true;
                        this->Buzon[i]->DataCorrespondencia();
                        delete Buzon[i];
                        this->CantBuzon--;
                        for(int j=i;j<this->CantBuzon;j++){
                            this->Buzon[j]=Buzon[j+1];
                        }
                        Buzon[this->CantBuzon]=NULL;
                        cout<<"\n\n[#] >>>>> Entregado."<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                    }
                }
            }
        }
        if(this->CantBulto()>0){
            bool Salto=false;
            for(int i=0;i<this->CantBuzon;i++){
                if(Salto==true){
                        i--;
                        Salto=false;
                }
                if(dynamic_cast<Bulto*>(this->Buzon[i])){
                    Bulto* aux=dynamic_cast<Bulto*>(this->Buzon[i]);
                    if(aux->getUrgencia()==3){
                        Salto=true;
                        this->Buzon[i]->DataCorrespondencia();
                        delete Buzon[i];
                        this->CantBuzon--;
                        for(int j=i;j<this->CantBuzon;j++){
                            this->Buzon[j]=Buzon[j+1];
                        }
                        Buzon[this->CantBuzon]=NULL;
                        cout<<"\n\n[#] >>>>> Entregado."<<endl;
                        cout<<"----------------------------------------------------------"<<endl;
                    }
                }
            }
        }
    }else{
        cout<<"[#] Buzon Vacio."<<endl;
    }
    return;
}








void Office::EntregaPersonal(string Nombre, string Direccion){
    bool Salto=false;
    bool entrega=false;
    for(int i=0;i<this->CantBuzon;i++){
        if(Salto==true){
            i--;
            Salto=false;
        }
        if(this->Buzon[i]->getNombre()==Nombre&&this->Buzon[i]->getDireccion()==Direccion){
            Salto=true;
            this->Buzon[i]->DataCorrespondencia();
            delete Buzon[i];
            cout<<"/n/n[#] >>>>> Entregado."<<endl;
            entrega=true;
            cout<<"----------------------------------------------------------";

            for(int j=i;j<this->CantBuzon-1;j++){
                this->Buzon[j]=this->Buzon[j+1];//Corriendo los elementos a la derecha del vacio, hacia la isquierda;
            }
            this->Buzon[this->CantBuzon]=NULL;
            this->CantBuzon--;
        }
    }
    if(entrega==false){
        cout<<"[#] No hay correspondencia para Usted."<<endl;
    }
    return;
}


int Office::TelegramaMaxPalabra(int n){
    int Cant=0;
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Telegrama*>(this->Buzon[i])){
            Telegrama* aux=dynamic_cast<Telegrama*>(this->Buzon[i]);
            if(aux->getCantPalabras()>n)Cant++;
        }
    }
    return Cant;
}


int Office::CartasRemitente(string Remitente){
    int Cant=0;
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Carta*>(this->Buzon[i])){
            if(Buzon[i]->getRemitente()==Remitente)Cant++;
        }
    }
    return Cant;
}




void Office::MaxCorrespondencia(){
    int a[3];
    a[0]=this->CantTelegrama();
    a[1]=this->CantCarta();
    a[2]=this->CantBulto();
    int Mayor=0;
    if(this->CantBuzon>0){
        for(int i=0;i<3;i++){
            if(a[i]>Mayor) Mayor=a[i];
        }
        cout<<"[#] Correspondencia Maxima: "<<endl;
        for(int i=0;i<3;i++){
            if(a[i]==Mayor){
                if(i==0){
                    cout<<"[#] >>>>> Telegrama."<<endl;
                }else if(i==1){
                    cout<<"[#] >>>>> Carta."<<endl;
                }else if(i==2){
                    cout<<"[#] >>>>> Bulto Postal."<<endl;
                }
            }
        }
    }else{
        cout<<"[#] No hay Correspondencia."<<endl;
    }
}






void Office::TelegramaOrdenRemitente(){
     if(this->CantTelegrama()>0){
        string Remitentes[this->CantTelegrama()];
        int A[this->CantTelegrama()][this->CantTelegrama()+1];
        int ContRemitentes=0;
        for(int i=0;i<this->CantBuzon;i++){
            if(dynamic_cast<Telegrama*>(this->Buzon[i])){
                bool Existe=false;
                int Pos;
                for(int j=0;j<ContRemitentes;j++){
                    if(Remitentes[j]==this->Buzon[i]->getRemitente()){
                        Existe=true;
                        Pos=j;
                    }
                }
                if(Existe==true){
                    A[Pos][0]++;
                    A[Pos][A[Pos][0]]=i;
                }else{
                    Remitentes[ContRemitentes]=this->Buzon[i]->getRemitente();
                    A[ContRemitentes][0]=1;
                    A[ContRemitentes][1]=i;
                    ContRemitentes++;
                }
            }
        }
        for(int i=0;i<ContRemitentes;i++){
            cout<<"[#] Remitente: "<<i+1<<": "<<Remitentes[i]<<endl;
            for(int j=1;j<=A[i][0];j++){
                this->Buzon[A[i][j]]->DataCorrespondencia();
                cout<<"----------------------------------------"<<endl;
            }
        }
    }else{
        cout<<"[#] No hay Telegramas en el Buzon."<<endl;
    }
    return;
}



void Office::FinDia(){
    for(int i=0;i<this->CantBuzon;i++){
        if(dynamic_cast<Carta*>(this->Buzon[i])){
            Carta* aux=dynamic_cast<Carta*>(this->Buzon[i]);
            aux->CantDias++;
            aux->setCosto();
        }
    }
    return;
}
