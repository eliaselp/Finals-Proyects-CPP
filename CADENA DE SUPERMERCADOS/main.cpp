#include <bits/stdc++.h>
#include <fstream>
#include "Cadena.h"
#include "Almacen.h"
#include "Producto.h"
#include "Nacional.h"
#include "Importado.h"
using namespace std;

Cadena* Dentex;
Almacen* almacen;
Producto* producto;
Nacional*ProductoNacional;
Importado* ProductoImportado;


void SeccionAlmacenes(int n);
int main()
{
    ifstream in;
    in.open("Salve.txt");
    if(!in){
        int CantMax;
        cout<<"[#] Inserte Cantidad Maxima: ";cin>>CantMax;
        Dentex=new Cadena(CantMax);
    }else{
        int CantMax,CantAlmacenes;
        Dentex=new Cadena(CantMax);
        in>>CantMax>>CantAlmacenes;
        for(int i=0;i<CantAlmacenes;i++){
            int MaxProductos,CantProductos;
            in>>MaxProductos>>CantProductos;
            Almacen* nuevoAlmecen=new Almacen(MaxProductos);
            Dentex->AggAlmacen(nuevoAlmecen);
            for(int j=0;j<CantProductos;j++){
                int tipo;
                in>>tipo;in.ignore();
                if(tipo==1){
                    string Codigo;string Nombre; float PrecioCosto; int Cant; string Empresa;
                    fflush(stdin);getline(in,Codigo);
                    fflush(stdin);getline(in,Nombre);
                    in>>PrecioCosto;
                    in>>Cant;in.ignore();
                    fflush(stdin);getline(in,Empresa);
                    Nacional* nuevoProducto=new Nacional(Codigo,Nombre,PrecioCosto,Cant,Empresa);
                    nuevoAlmecen->AggProducto(nuevoProducto);
                }else if(tipo == 2){
                    string Codigo;string Nombre; float PrecioCosto; int Cant; string Pais; float USD;
                    fflush(stdin);getline(in,Codigo);
                    fflush(stdin);getline(in,Nombre);
                    in>>PrecioCosto;
                    in>>Cant;in.ignore();
                    fflush(stdin);getline(in,Pais);
                    in>>USD;
                    Importado* NuevoProducto=new Importado(Codigo,Nombre,PrecioCosto,Cant,Pais,USD);
                    nuevoAlmecen->AggProducto(NuevoProducto);
                }
            }
        }
    }
    in.close();
    int opc;
    do{
        system("cls");
        cout<<"***************************************************"<<endl;
        cout<<"**********    CADENA DE SUPERMERCADOS    **********"<<endl;
        cout<<"***************************************************"<<endl<<endl;
        cout<<"[1] Agregar Almacen."<<endl;
        cout<<"[2] Producto Mas Vendido: "<<endl;
        cout<<"[3] Produto menos vendido: "<<endl;
        cout<<"[4] Mostrar Productos Por Almacenes: "<<endl;
        cout<<"[5] Almacen Con Mayor Ganancia."<<endl;
        cout<<"[6] Ganancia NETA de Cadena Almacenes."<<endl;
        cout<<"[7] Seccion de gestion de Almacenes."<<endl;
        cout<<"[8] Salir."<<endl<<endl;
        cout<<"[+] OPCION >>>>> ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Dentex->getCantAlmacenes()<Dentex->getCantMaxAlmacenes()){
                int MaxProductos;
                cout<<"[+] Introduzca la cantidad maxima de Prodctos: ";
                cin>>MaxProductos;
                almacen=new Almacen(MaxProductos);
                Dentex->AggAlmacen(almacen);
                almacen=NULL;
            }else{
                cout<<"[#] No hay espacio para un nuevo Almacen."<<endl;
            }
        }else if(opc==2){
            Dentex->ProductoMaxVendido();
        }else if(opc==3){
            Dentex->ProductoMinVendido();
        }else if(opc==4){
            if(Dentex->getCantAlmacenes()>0){
                Dentex->DataAlmacenes();
            }else{
                cout<<"[#] La cadena no tiene Almacenes."<<endl;
            }
        }else if(opc==5){
            if(Dentex->getCantAlmacenes()>0){
                Dentex->AlmacenMaxGanancia();
            }else{
                cout<<"[#] La cadena no tiene Almacenes."<<endl;
            }
        }else if(opc==6){
            cout<<"Ganancia Neta >>>> "<<Dentex->GananciaNeta()<<endl;
        }else if(opc==7){
            if(Dentex->getCantAlmacenes()>0){
                Dentex->DataAlmacenes();
                int n;
                cout<<"[+] Inserte Numero de Almacen >>>>>> ";cin>>n;
                if(n>0&&n<=Dentex->getCantAlmacenes())SeccionAlmacenes(n);
                else cout<<"<<< Error >>>"<<endl;
            }else{
                cout<<"[#] La Cadena No tiene Almacen."<<endl;
            }
        }else if(opc==8){
            cout<<"[#] GOOD BYE."<<endl;
        }else{
            cout<<"<<< Error >>>"<<endl;
        }
        system("pause");
    }while(opc!=8);

    ofstream out;
    out.open("Salve.txt");
    out<<Dentex->getCantMaxAlmacenes()<<" "<<Dentex->getCantAlmacenes()<<"\n";
    for(int i=0;i<Dentex->getCantAlmacenes();i++){
        out<<Dentex->getListadoAlmacenes(i+1)->getMaxProductos()<<"\n";
        out<<Dentex->getListadoAlmacenes(i+1)->getCantProductos()<<"\n";
        for(int j=0;j<Dentex->getListadoAlmacenes(i+1)->getCantProductos();j++){
            //string Codigo,string Nombre, float PrecioCosto, int Cant
            if(dynamic_cast<Nacional*>(Dentex->getListadoAlmacenes(i+1)->ListaProductos[j])){
                out<<"1\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getCodigo()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getNombre()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getPrecioCosto()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getCant()<<"\n";
                Nacional* aux=dynamic_cast<Nacional*>(Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]);
                out<<aux->getEmpresa()<<"\n";
            }else if(dynamic_cast<Importado*>(Dentex->getListadoAlmacenes(i+1)->ListaProductos[j])){
                out<<"2\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getCodigo()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getNombre()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getPrecioCosto()<<"\n";
                out<<Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]->getCant()<<"\n";
                Importado* aux=dynamic_cast<Importado*>(Dentex->getListadoAlmacenes(i+1)->ListaProductos[j]);
                out<<aux->getPais()<<"\n";
                out<<aux->getUSD()<<"\n";
            }
        }

    }
    out.close();
    return 0;
}




void SeccionAlmacenes(int n){
    int opc;
    do{
        system("cls");
        cout<<"**************************************"<<endl;
        cout<<"*******  SECCION DE ALMACENES  *******"<<endl;
        cout<<"**************************************"<<endl<<endl;
        cout<<"[1] Agregar nuevo Producto."<<endl;
        cout<<"[2] Realizar Pedido a Cadena."<<endl;
        cout<<"[3] Nacional Precio Plus."<<endl;
        cout<<"[4] Buscar Producto por Pais"<<endl;
        cout<<"[5] Vender Producto"<<endl;
        cout<<"[6] Volver."<<endl<<endl;
        cout<<"[#] OPCION >>>>>> ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Dentex->getListadoAlmacenes(n)->getCantProductos()<Dentex->getListadoAlmacenes(n)->getMaxProductos()){
                cout<<"[1] Nacional"<<endl;
                cout<<"[2] Internacional."<<endl;
                cout<<"[#] Cancelar."<<endl;
                cout<<"Opcion >>> ";
                int Procedencia;
                cin>>Procedencia;
                system("cls");
                if(Procedencia==1){
                    string Codigo;
                    string Nombre;
                    float PrecioCosto;
                    int Cant;
                    string Empresa;
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    cout<<"[+] Precio de Costo: ";cin>>PrecioCosto;
                    cout<<"[+] Cantidad: ";cin>>Cant;
                    fflush(stdin);cout<<"[+] Nombre de la Empresa: ";getline(cin,Empresa);
                    producto=new Nacional(Codigo,Nombre,PrecioCosto,Cant,Empresa);
                }else if(Procedencia==2){
                    string Pais;
                    float USD;
                    string Codigo;
                    string Nombre;
                    float PrecioCosto;
                    int Cant;
                    string Empresa;
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Nombre: ";getline(cin,Nombre);
                    cout<<"[+] Precio de Costo: ";cin>>PrecioCosto;
                    cout<<"[+] Cantidad: ";cin>>Cant;
                    fflush(stdin);cout<<"[+] Pais: ";getline(cin,Pais);
                    cout<<"[+] Inversion USD: ";cin>>USD;
                    producto=new Importado(Codigo,Nombre,PrecioCosto,Cant,Pais,USD);
                }
                Dentex->getListadoAlmacenes(n)->AggProducto(producto);
                producto=NULL;
            }else{
                cout<<"[#] El Almacen esta lleno."<<endl;
            }
        }else if(opc==2){
            if(Dentex->getListadoAlmacenes(n)->getCantProductos()>0){
                cout<<"[+] Inserte cantidad: ";
                int Cantidad;cin>>Cantidad;
                Dentex->getListadoAlmacenes(n)->PedidoCadena(Cantidad);
            }else{
                cout<<"[#] El Almacen Esta VACIO."<<endl;
            }
        }else if(opc==3){
            if(Dentex->getListadoAlmacenes(n)->getCantProductos()>0){
                float Precio;
                cout<<"[+] Inserte precio: ";cin>>Precio;
                Dentex->getListadoAlmacenes(n)->NacionaPrecioPlus(Precio);
            }else{
                cout<<"[#] El Almacen Esta VACIO."<<endl;
            }
        }else if(opc==4){
            if(Dentex->getListadoAlmacenes(n)->CantImportado()>0){
                string Pais;
                fflush(stdin);cout<<"[+] Pais: ";getline(cin,Pais);
                Dentex->getListadoAlmacenes(n)->BuscarProductoPorPais(Pais);
            }else{
                cout<<"[#] No hay Productos Importados."<<endl;
            }
        }else if(opc==5){
            if(Dentex->getListadoAlmacenes(n)->getCantProductos()>0){
                if(Dentex->getListadoAlmacenes(n)->CantNacional()>0){
                    cout<<"[#] PRODUCTOS NACIONALES:"<<endl;
                    Dentex->getListadoAlmacenes(n)->DataNacional();
                }
                if(Dentex->getListadoAlmacenes(n)->CantImportado()>0){
                    cout<<"[#] PRODUCTOS IMPORTADOS:"<<endl;
                    Dentex->getListadoAlmacenes(n)->DataInternacional();
                }
                cout<<"[+] Inserte   << CODIGO >> de Producto: ";
                string Codigo;
                fflush(stdin);getline(cin,Codigo);
                cout<<"[+] Cantidad: ";int Cant;cin>>Cant;
                Dentex->getListadoAlmacenes(n)->Vender(Codigo,Cant);
            }else{
                cout<<"[#] El Almacen Esta VACIO."<<endl;
            }
        }else if(opc==6){
            cout<<"Hasta Luego."<<endl;
        }else {
            cout<<"<<<<<<  ERROR  >>>>>>"<<endl;
        }

        system("pause");
    }while(opc!=6);
}
