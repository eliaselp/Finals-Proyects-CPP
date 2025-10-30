#include "Almacen.h"
#include <iostream>
using namespace std;
Almacen::Almacen(int MaxProductos)
{
    this->MaxProductos=MaxProductos;
    this->ListaProductos=new Producto*[MaxProductos];
    this->CantProductos=0;
}

Almacen::~Almacen()
{
    //dtor
}
//*********************************************************
//*********************************************************
int Almacen::getCantProductos(){
    return this->CantProductos;
}
int Almacen::getMaxProductos(){
    return this->MaxProductos;
}
float Almacen::getGanancia(){
    return this->Ganancia;
}


//*********************************************************
//*********************************************************
int Almacen::CantNacional(){
    int Cant=0;
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Nacional*>(this->ListaProductos[i]))Cant++;
    }
    return Cant;
}

int Almacen::CantImportado(){
    int Cant=0;
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Importado*>(this->ListaProductos[i]))Cant++;
    }
    return Cant;
}


//*********************************************************
//*********************************************************
void Almacen::AggProducto(Producto* nuevo){
    if(this->CantProductos<this->MaxProductos){
        this->ListaProductos[this->CantProductos]=nuevo;
        this->CantProductos++;
    }else{
        cout<<"[#] El Almacen esta Lleno."<<endl;
    }
    return;
}
void Almacen::DataNacional(){
    cout<<"[+] Productos Nacionales: "<<endl;
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Nacional*>(this->ListaProductos[i])){
            this->ListaProductos[i]->DataProducto();
            cout<<"----------------------------------------------------------\n";
        }
    }
    return;
}

void Almacen::DataInternacional(){
    cout<<"[+] Productos Internacionales: "<<endl;
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Importado*>(this->ListaProductos[i])){
            this->ListaProductos[i]->DataProducto();
            cout<<"----------------------------------------------------------\n";
        }
    }
    return;
}

void Almacen::PedidoCadena(int n){
    if(this->CantProductos>0){
       if(this->CantNacional()>0){
            cout<<"[+] Nacionales: "<<endl;
            for(int i=0;i<this->CantProductos;i++){
                if(dynamic_cast<Nacional*>(this->ListaProductos[i])){
                    if(this->ListaProductos[i]->getCant()<n){
                        cout<<"[+] "<<this->ListaProductos[i]->getNombre()<<endl;
                    }
                }
            }
            cout<<"-----------------------------------------------------\n";
       }
        if(this->CantImportado()>0){
            cout<<"Internacionales: "<<endl;
            for(int i=0;i<this->CantProductos;i++){
                if(dynamic_cast<Importado*>(this->ListaProductos[i])){
                    if(this->ListaProductos[i]->getCant()<n){
                        cout<<"[+] "<<this->ListaProductos[i]->getNombre()<<endl;
                    }
                }
            }
        }
    }
    return;
}

void Almacen::Vender(string Codigo, int cant){
    int pos=-1;
    for(int i=0;i<this->CantProductos;i++){
        if(this->ListaProductos[i]->getCodigo()==Codigo){
            pos=i;
            break;
        }
    }
    if(pos!=-1){
        if(cant<=this->ListaProductos[pos]->getCant()){
            int V=this->ListaProductos[pos]->getVenta()+cant;
            this->ListaProductos[pos]->setVenta(V);
            V=this->ListaProductos[pos]->getCant()-cant;
            ListaProductos[pos]->setCant(V);
            this->Ganancia+=(this->ListaProductos[pos]->getPrecioVenta())*cant;
        }else{
            cout<<"[#] Catidad Insuficiente."<<endl;
        }
    }else{
        cout<<"[#] El producto no Existe."<<endl;
    }
    return;
}
//*********************************************************************************
//*********************************************************************************
void Almacen::ProductoMaxVendido(){
    if(this->Ganancia>0){
        int mayor=0;
        for(int i=0;i<this->CantProductos;i++){
            if(this->ListaProductos[i]->getVenta()>mayor){
                mayor=this->ListaProductos[i]->getVenta();
            }
        }
        cout<<"[+] Productos de Mayor Venta: \n";
        for(int i=0;i<this->CantProductos;i++){
            if(this->ListaProductos[i]->getVenta()==mayor){
                cout<<"[+] Producto: "<<this->ListaProductos[i]->getNombre()<<endl;
            }
        }
    }else{
        cout<<"El Almacen no ha tenido Venta.";
    }
    return;
}

void Almacen::ProductoMinVendido(){
    int menor=999999999;
    for(int i=0;i<this->CantProductos;i++){
        if(this->ListaProductos[i]->getVenta()<menor){
            menor=this->ListaProductos[i]->getVenta();
        }
    }
    cout<<"[+] Productos de Menor Venta: \n";
    for(int i=0;i<this->CantProductos;i++){
        if(this->ListaProductos[i]->getVenta()==menor){
            cout<<"[+] Producto: "<<this->ListaProductos[i]->getNombre()<<endl;
        }
    }
    return;
}

void Almacen::NacionaPrecioPlus(float Precio){
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Nacional*>(this->ListaProductos[i])){
            if(this->ListaProductos[i]->getPrecioVenta()>=Precio){
                cout<<"[+] Producto: "<<this->ListaProductos[i]->getNombre()<<endl;
                cout<<"[+] Precio: "<<this->ListaProductos[i]->getPrecioVenta()<<endl;
                cout<<"-----------------------------------------------------------\n";
            }
        }
    }
    return;
}
void Almacen::BuscarProductoPorPais(string Pais){
    for(int i=0;i<this->CantProductos;i++){
        if(dynamic_cast<Importado*>(this->ListaProductos[i])&&this->ListaProductos[i]->getPais()==Pais){
            cout<<"[+] Producto: "<<this->ListaProductos[i]->getNombre()<<endl;
            cout<<"[+] Precio Inversion: "<<this->ListaProductos[i]->getUSD()<<endl;
            cout<<"------------------------------------------------------\n";
        }
    }
    return;
}
