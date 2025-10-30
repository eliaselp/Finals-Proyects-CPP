#include "Planta.h"
#include <iostream>
using namespace std;
Planta::Planta(int UsuariosMax)
{
    this->UsuariosMax=UsuariosMax;
    this->CantActivos=0;
    this->CantCola=0;
    this->CantBaneados=0;
    this->TotalUsuarios=new Usuario*[UsuariosMax];
    this->CantReal=0;
    this->DepositoMN=new float[UsuariosMax];
    this->DepositoUSD=new float[UsuariosMax];
}

Planta::~Planta()
{
    //dtor
}



void Planta::PoliticaCambio(int MesActual){
    if(this->CantActivos>0){
        for(int i=0;i<this->CantReal;i++){
            if(this->TotalUsuarios[i]->getCategoria()==1){
                if(this->TotalUsuarios[i]->getPay()==false){
                    int n=this->TotalUsuarios[i]->getNotPay();n++;
                    this->TotalUsuarios[i]->setNotPay(n);
                    if(this->TotalUsuarios[i]->getNotPay()>=3){
                        this->TotalUsuarios[i]->setCategoria(3);
                        this->CantActivos--;
                        this->CantBaneados++;
                    }
                }else{
                    this->TotalUsuarios[i]->setPay(false);
                }
            }
        }
    }
    if(this->CantCola>0){
        for(int i=0;i<this->CantReal;i++){
            if(this->TotalUsuarios[i]->getCategoria()==2){
                this->TotalUsuarios[i]->setCategoria(1);
                this->TotalUsuarios[i]->setPay(false);
                this->CantCola--;
                this->CantActivos++;
            }
        }
    }
    if(this->CantBaneados>0){
        for(int i=0;i<this->CantReal;i++){
            if(this->TotalUsuarios[i]->getCategoria()==3){
                if(this->TotalUsuarios[i]->getPay()==true){
                    TotalUsuarios[i]->setCategoria(2);
                    this->CantBaneados--;
                    this->CantCola++;
                }
            }
        }
    }
    return;
}



void Planta::Pagar(int MesActual,int n,float Monto){
    if(this->TotalUsuarios[n-1]->getPay()==false){
        if(Monto>=this->TotalUsuarios[n-1]->getDeuda(MesActual)){
            Monto-=this->TotalUsuarios[n-1]->getDeuda(MesActual);
            if(dynamic_cast<Estado*>(this->TotalUsuarios[n-1])||dynamic_cast<Home*>(this->TotalUsuarios[n-1])){
                this->DepositoMN[n-1]=Monto;
            }else{
                this->DepositoUSD[n-1]=Monto;
            }
            this->TotalUsuarios[n-1]->setNotPay(0);
            this->TotalUsuarios[n-1]->setPay(true);
            this->TotalUsuarios[n-1]->setMinutos(0);
        }else{
            cout<<"[#] Cantidad Insuficiente."<<endl;
        }
    }else{
        cout<<"[#] El Usuario ya realizo el pago mensual."<<endl;
    }
}
/***************************************************************************/
/******************  METODOS GETERS   ******************************/
/***************************************************************************/
int Planta::getCantActivos(){
    return this->CantActivos;
}
int Planta::getCantCola(){
    return this->CantCola;
}
int Planta::getCantBaneados(){
    return this->CantBaneados;
}
Usuario* Planta::getTotalUsuarios(int n){
    return this->TotalUsuarios[n-1];
}
int Planta::getCantReal(){
    return this->CantReal;
}
float Planta::getDepositoMN(int n){
    return this->DepositoMN[n-1];
}
float Planta::getDepositoUSD(int n){
    return this->DepositoUSD[n-1];
}
int Planta::getUsuariosMax(){
    return this->UsuariosMax;
}




/***************************************************************************/
/******************  METODOS APILADORES   ******************************/
/***************************************************************************/
void Planta::AggUsuario(Usuario* nuevo){
    this->TotalUsuarios[this->CantReal]=nuevo;
    this->DepositoMN[this->CantReal]=0;
    this->DepositoUSD[this->CantReal]=0;
    this->CantReal++;
    this->CantActivos++;
    return;
}











/***************************************************************************/
/******************  METODOS Eliminadores   ******************************/
/***************************************************************************/
void Planta::EliminarUsuario(int n){
    if(this->TotalUsuarios[n-1]->getCategoria()==1)this->CantActivos--;
    else if(this->TotalUsuarios[n-1]->getCategoria()==2)this->CantCola--;
    else if(this->TotalUsuarios[n-1]->getCategoria()==3)this->CantBaneados--;
    delete this->TotalUsuarios[n-1];
    this->CantReal--;
    for(int i=n-1;i<this->CantReal;i++){
        this->TotalUsuarios[i]=this->TotalUsuarios[i+1];
    }
    this->TotalUsuarios[this->CantReal]=NULL;

    return;
}
//-----------------------------------------------------------------------------------------------

/***************************************************************************/
/******************  METODOS SETERS   ******************************/
/***************************************************************************/
void Planta::setDepositoMN(int Usser,float Liquidez){
    this->DepositoMN[Usser]+=Liquidez;
    return;
}
void Planta::setDepositoUSD(int Usser,float Liquidez){
    this->DepositoUSD[Usser]+=Liquidez;
}
void Planta::fActivo(int n){
    this->CantActivos=n;
}
void Planta::fCola(int n){
    this->CantCola=n;
}
void Planta::fBaneado(int n){
    this->CantBaneados=n;
}







/***************************************************************************/
/******************  METODOS CANTS   ******************************/
/***************************************************************************/
int Planta::CantEstado(int Categoria){
    int cont=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Estado*>(this->TotalUsuarios[i]))
            if(this->TotalUsuarios[i]->getCategoria()==Categoria)cont++;
    }
    return cont;
}
int Planta::CantHome(int Categoria){
    int cont=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Home*>(this->TotalUsuarios[i]))
            if(this->TotalUsuarios[i]->getCategoria()==Categoria)cont++;
    }
    return cont;
}
int Planta::CantExtranjero(int Categoria){
    int cont=0;
    for(int i=0;i<this->CantReal;i++){
        if(dynamic_cast<Extranjero*>(this->TotalUsuarios[i]))
            if(this->TotalUsuarios[i]->getCategoria()==Categoria)cont++;
    }
    return cont;
}











/***************************************************************************/
/******************  METODOS DATA   ******************************/
/***************************************************************************/

void Planta::DataEstado(int Categoria){
    if(this->CantEstado(Categoria)>0){
        for(int i=0;i<this->CantReal;i++){
            if(dynamic_cast<Estado*>(this->TotalUsuarios[i])){
                if(this->TotalUsuarios[i]->getCategoria()==Categoria){
                    cout<<"<<< INDEXADO >>> "<<i+1<<endl;
                    this->TotalUsuarios[i]->DataUsuario();
                    cout<<"-------------------------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Planta::DataHome(int Categoria){
    if(this->CantHome(Categoria)>0){
        for(int i=0;i<this->CantReal;i++){
            if(dynamic_cast<Home*>(this->TotalUsuarios[i])){
                if(this->TotalUsuarios[i]->getCategoria()==Categoria){
                    cout<<"<<< INDEXADO >>> "<<i+1<<endl;
                    this->TotalUsuarios[i]->DataUsuario();
                    cout<<"-------------------------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Planta::DataExtranjero(int Categoria){
    if(this->CantExtranjero(Categoria)>0){
        for(int i=0;i<this->CantReal;i++){
            if(dynamic_cast<Extranjero*>(this->TotalUsuarios[i])){
                if(this->TotalUsuarios[i]->getCategoria()==Categoria){
                    cout<<"<<< INDEXADO >>> "<<i+1<<endl;
                    this->TotalUsuarios[i]->DataUsuario();
                    cout<<"-------------------------------------------------------------"<<endl;
                }
            }
        }
    }
    return;
}
void Planta::DataUsuario(){
    for(int i=0;i<this->CantReal;i++){
        cout<<"<<< INDEXADO >>> "<<i+1<<endl;
        this->TotalUsuarios[i]->DataUsuario();
        cout<<"-------------------------------------------------------------"<<endl;
    }
    return;
}
void Planta::DataPlanta(){
    cout<<"Cantidad Maxima de Usuarios: "<<this->UsuariosMax<<endl;
    cout<<"Cantidad de Usuarios: "<<this->CantReal<<endl;
    cout<<"Cantidad de Usuarios Activos: "<<this->CantActivos<<endl;
    cout<<"Cantidad de Usuarios en Cola: "<<this->CantCola<<endl;
    cout<<"Cantidad de Usuarios Baneados: "<<this->CantBaneados<<endl;
}



//-----------------------
void Planta::DataBaneados(){
    if(this->CantEstado(3)>0){
        cout<<"*****  ESTATALES  *****"<<endl<<endl;
        this->DataEstado(3);
    }
    if(this->CantExtranjero(3)>0){
        cout<<"*****  EXTRANJEROS  *****"<<endl<<endl;
        this->DataExtranjero(3);
    }
    if(this->CantHome(3)>0){
        cout<<"*****  Home  *****"<<endl<<endl;
        this->DataHome(3);
    }
    return;
}
void Planta::DataActivos(){
    if(this->CantEstado(1)>0){
        cout<<"*****  ESTATALES  *****"<<endl<<endl;
        this->DataEstado(1);
    }
    if(this->CantExtranjero(1)>0){
        cout<<"*****  EXTRANJEROS  *****"<<endl<<endl;
        this->DataExtranjero(1);
    }
    if(this->CantHome(1)>0){
        cout<<"*****  Home  *****"<<endl<<endl;
        this->DataHome(1);
    }
    return;
}
void Planta::DataCola(){
    if(this->CantEstado(2)>0){
        cout<<"*****  ESTATALES  *****"<<endl<<endl;
        this->DataEstado(2);
    }
    if(this->CantExtranjero(2)>0){
        cout<<"*****  EXTRANJEROS  *****"<<endl<<endl;
        this->DataExtranjero(2);
    }
    if(this->CantHome(2)>0){
        cout<<"*****  Home  *****"<<endl<<endl;
        this->DataHome(2);
    }
    return;
}



/***************************************************************************/
/******************  METODOS PEDIDOS   ******************************/
/***************************************************************************/
void Planta::Comprobante(string Nombre,string Telefono,int mes){
    bool existe=false;
    int pos;
    for(int i=0;i<this->CantReal;i++){
        if(this->TotalUsuarios[i]->getNombre()==Nombre&&this->TotalUsuarios[i]->getTelefono()==Telefono){
            existe=true;
            pos=i;
        }
    }
    if(existe==true){
        this->TotalUsuarios[pos]->DataUsuario();
        cout<<"[#] Importe: "<<this->TotalUsuarios[pos]->getConsumo(mes)<<endl;
    }else{
        cout<<"[#] El Usuario no esta registrado."<<endl;
    }
}
void Planta::ComprobantePlus(string Nombre,string Telefono,int Cants,int MesActual){
    if(Cants<=MesActual&&Cants>=1){
        bool existe=false;
        int pos;
        for(int i=0;i<this->CantReal;i++){
            if(this->TotalUsuarios[i]->getNombre()==Nombre&&this->TotalUsuarios[i]->getTelefono()==Telefono){
                existe=true;
                pos=i;
            }
        }

        if(existe==true){
            int* Meses=new int[Cants];
            for(int i=0;i<Cants;i++){
                Meses[i]=MesActual;
                do{
                    system("cls");
                    if(Meses[i]>MesActual||Meses[i]<1)cout<<"<<<<<  ERROR  >>>>>"<<endl;
                    cout<<"["<<i+1<<"] Inserte el numero de mes: ";
                    cin>>Meses[i];
                }while(Meses[i]>MesActual||Meses[i]<1);
            }

            this->TotalUsuarios[pos]->DataUsuario();
            cout<<endl;
            for(int i=0;i<Cants;i++){
                cout<<"[#] Mes "<<Meses[i]<<"----------->  "<<this->TotalUsuarios[pos]->getConsumo(Meses[i])<<endl;
            }
            float suma=0;
            for(int i=0;i<Cants;i++){
                suma+=this->TotalUsuarios[pos]->getConsumo(Meses[i]);
            }
            cout<<"[#] Importe Acumulado ----------->  "<<suma<<endl;
        }else{
            cout<<"[#] El Usuario no esta registrado."<<endl;
        }
    }else{
        cout<<"[#] Solicitud Rechazada."<<endl;
    }
}
void Planta::UsuariosMaxPromedio(int MesActual){
    if(this->CantReal>0){
        float Prom=this->setPromedio(MesActual);
        int Usuarios[this->CantReal];
        int Cant=0;
        for(int i=0;i<this->CantReal;i++){
            if(this->Promedio[i]>Prom){
                Usuarios[Cant]=i;
                Cant++;
            }
        }
        float MaxPromedio[Cant];
        for(int i=0;i<Cant;i++){
            MaxPromedio[i]=Promedio[Usuarios[i]];
        }
        for(int i=0;i<Cant;i++){
            for(int j=0;j<Cant-1;j++){
                if(MaxPromedio[i]>MaxPromedio[i+1]){
                    float aux=MaxPromedio[i];
                    MaxPromedio[i]=MaxPromedio[i+1];
                    MaxPromedio[i+1]=aux;
                    int aux2=Usuarios[i];
                    Usuarios[i]=Usuarios[i+1];
                    Usuarios[i+1]=aux2;
                }
            }
        }

        for(int i=0;i<Cant;i++){
            this->TotalUsuarios[Usuarios[i]]->DataUsuario();
            cout<<"[#] Promedio de Consumo: "<<MaxPromedio[i]<<endl;
            cout<<"--------------------------------------------"<<endl;
        }
    }
    return;
}

float Planta::setPromedio(int MesActual){
    this->Promedio=new float[this->CantReal];
    for(int i=0;i<this->CantReal;i++){
        Promedio[i]=0;
        int cont=0;
        for(int j=0;j<MesActual;j++){
            if(this->TotalUsuarios[i]->getConsumo(j+1)>0){
                Promedio[i]+=this->TotalUsuarios[i]->getConsumo(j+1);
                cont++;
            }
        }
        Promedio[i]=Promedio[i]/cont;
    }
    int ProGen=0;
    for(int i=0;i<CantReal;i++){
        ProGen+=Promedio[i];
    }
    ProGen=ProGen/this->CantReal;
    return ProGen;
}
