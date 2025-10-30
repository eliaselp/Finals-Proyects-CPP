#include <iostream>
#include <fstream>
#include "Administrador.h"
#include "Electronico.h"
#include "Medio.h"
#include "Mobiliario.h"
using namespace std;

Administrador* Admin;
int main()
{
    ifstream in;
    in.open("Salva.txt");
    if(!in){
        int MaxMedios;
        cout<<"[#] Inserte Maxima cantidad de medios: ";cin>>MaxMedios;
        Admin=new Administrador(MaxMedios);
    }else{
        int MaxMedios,CantReal;
        in>>MaxMedios>>CantReal;
        Admin=new Administrador(MaxMedios);
        for(int i=0;i<CantReal;i++){
            int tipo;in>>tipo;in.ignore();
            if(tipo==1){
                string Inventario;float CostoUnitario;string Estado;string Tipo;string Marca;string Proveedor;int Garantia;
                fflush(stdin);getline(in,Inventario);
                fflush(stdin);in>>CostoUnitario;in.ignore();
                fflush(stdin);getline(in,Estado);
                fflush(stdin);getline(in,Tipo);
                fflush(stdin);getline(in,Marca);
                fflush(stdin);getline(in,Proveedor);
                fflush(stdin);in>>Garantia;in.ignore();
                Electronico* aux=new Electronico(Inventario,CostoUnitario,Estado,Tipo,Marca,Proveedor,Garantia);
                Admin->AggMedio(aux);
            }else if(tipo==2){
                string Inventario;float CostoUnitario;string Estado;string Tipo;string Proveedor;int Explotacion;string Local;
                fflush(stdin);getline(in,Inventario);
                fflush(stdin);in>>CostoUnitario;in.ignore();
                fflush(stdin);getline(in,Estado);
                fflush(stdin);getline(in,Tipo);
                fflush(stdin);getline(in,Proveedor);
                fflush(stdin);in>>Explotacion;in.ignore();
                fflush(stdin);getline(in,Local);
                Mobiliario* aux=new Mobiliario(Inventario,CostoUnitario,Estado,Tipo,Proveedor,Explotacion,Local);
                Admin->AggMedio(aux);
            }
        }
    }
    in.close();
    int opc;
    do{
        ofstream out;
        out.open("Salva.txt");
        out<<Admin->getMaxMedios()<<" "<<Admin->getCantReal()<<"\n";
        for(int i=0;i<Admin->getCantReal();i++){
            if(dynamic_cast<Electronico*>(Admin->getListaMedios(i+1))){
                out<<"1\n";
                //(string Inventario,float CostoUnitario,string Estado,string Tipo,string Marca,string Proveedor,int Garantia
                out<<Admin->getListaMedios(i+1)->getInventario()<<"\n";
                out<<Admin->getListaMedios(i+1)->getCostoUnitario()<<"\n";
                out<<Admin->getListaMedios(i+1)->getEstado()<<"\n";
                out<<Admin->getListaMedios(i+1)->getTipo()<<"\n";
                Electronico* aux=dynamic_cast<Electronico*>(Admin->getListaMedios(i+1));
                out<<aux->getMarca()<<"\n";
                out<<aux->getProveedor()<<"\n";
                out<<aux->getGarantia()<<"\n";
            }else if(dynamic_cast<Mobiliario*>(Admin->getListaMedios(i+1))){
                out<<"2\n";
                //string Inventario,float CostoUnitario,string Estado,string Tipo,string Proveedor,int Explotacion,string Local)
                Mobiliario* aux=dynamic_cast<Mobiliario*>(Admin->getListaMedios(i+1));
                out<<aux->getInventario()<<"\n";
                out<<aux->getCostoUnitario()<<"\n";
                out<<aux->getEstado()<<"\n";
                out<<aux->getTipo()<<"\n";
                out<<aux->getProveedor()<<"\n";
                out<<aux->getExplotacion()<<"\n";
                out<<aux->getLocal()<<"\n";
            }
        }
        out.close();
        system("cls");
        cout<<"[1] Agregar Medio."<<endl;
        cout<<"[2] Eliminar Medio."<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"[3] Equipos por Marca."<<endl;
        cout<<"[4] Medios Mas Estado por Tipo"<<endl;
        cout<<"[5] Equipo de Mas y Menos Garantia"<<endl;
        cout<<"[6] Principales Proveedores."<<endl;
        cout<<"[7] Cantidad de Muebles x Tipo (FICHEROS)"<<endl;
        cout<<"[8] Costo Total por Tipo."<<endl;
        cout<<"[9] Costo Promedio por Tipos Desglosado."<<endl;
        cout<<"[10] Datos Medios Mobiliarios por tipo."<<endl;
        cout<<"[11] Salir."<<endl<<endl<<endl;
        cout<<"[#] OPCION ==>";cin>>opc;
        system("cls");
        if(opc==1){
            if(Admin->getCantReal()<Admin->getMaxMedios()){
                int m;
                cout<<"[1] Electronico."<<endl;
                cout<<"[2] Mobiliario."<<endl<<endl;
                cout<<"[#] OPCION ==>";cin>>m;
                system("cls");
                if(m==1){
                    string Inventario;float CostoUnitario;string Estado;string Tipo;string Marca;string Proveedor;int Garantia;
                    fflush(stdin);cout<<"[#] Inventario: ";getline(cin,Inventario);
                    fflush(stdin);cout<<"[#] Costo Unitario: ";cin>>CostoUnitario;
                    int e=1;
                    do{
                        system("cls");
                        if(e<0||e>4)cout<<"#####  ERROR  #####"<<endl;
                        fflush(stdin);cout<<"[#] Estado:   <1> Bien    <2> Regular   <3> Mal"<<endl;
                                      cout<<"              <4> CANCELAR."<<endl<<endl;
                        cout<<"# ===>> ";cin>>e;
                    }while(e<0||e>4);
                    if(e==1)Estado="Bien";
                    else if(e==2)Estado="Regular";
                    else if(e==3)Estado="Mal";
                    if(e!=4){
                        int t=1;
                        do{
                            system("cls");
                            if(t<0||t>7)cout<<"#####  ERROR  #####"<<endl;
                            //refrigerador, TV, video, ventilador, aire acondicionado, computadora
                            fflush(stdin);cout<<"[#] Tipo:   <1> Refrigerador.     <2> TV.     <3> Video."<<endl;
                                          cout<<"              <4> Ventilador.      <5>Aire Acondicionado.  <6> Computadora."<<endl;
                                          cout<<"               <7> CANCELAR."<<endl<<endl;
                            cout<<"# ===>> ";cin>>t;
                        }while(t<0||t>7);
                        if(t==1)Tipo="Refrigerador";
                        else if(t==2)Tipo="TV";
                        else if(t==3)Tipo="Video";
                        else if(t==4)Tipo="Ventilador";
                        else if(t==5)Tipo="Aire Acondicionado";
                        else if(t==6)Tipo="Computadora";
                        if(t!=7){
                            int m=1;
                            do{
                                system("cls");
                                if(m<0||m>5)cout<<"#####  ERROR  #####"<<endl;
                                //Sony, Sanyo, Atec Panda, LG
                                fflush(stdin);cout<<"[#] Marca:   <1> SONY.     <2> SANYO.     <3> ATEC PANDA."<<endl;
                                              cout<<"              <4> LG         <5> CANCELAR."<<endl<<endl;
                                cout<<"# ===>> ";cin>>m;
                            }while(m<0||m>5);
                            if(m==1)Marca="SONY";
                            else if(m==2)Marca="SANYO";
                            else if(m==3)Marca="ATEC PANDA";
                            else if(m==4)Marca="LG";
                            if(m!=5){
                                fflush(stdin);cout<<"[#] Proveedor: ";getline(cin,Proveedor);
                                fflush(stdin);cout<<"[#] Garantia: ";cin>>Garantia;
                                Electronico* nuevo=new Electronico(Inventario,CostoUnitario,Estado,Tipo,Marca,Proveedor,Garantia);
                                Admin->AggMedio(nuevo);
                            }else cout<<"[#] Proceso Cancelado."<<endl;
                        }else cout<<"[#] Proceso Cancelado."<<endl;
                    }else cout<<"[#] Proceso Cancelado."<<endl;
                }else if(m==2){
                    string Inventario;float CostoUnitario;string Estado;string Tipo;string Proveedor;int Explotacion;string Local;
                    fflush(stdin);cout<<"[#] Inventario: ";getline(cin,Inventario);
                    fflush(stdin);cout<<"[#] Costo Unitario: ";cin>>CostoUnitario;
                    int e=1;
                    do{
                        system("cls");
                        if(e<0||e>4)cout<<"#####  ERROR  #####"<<endl;
                        fflush(stdin);cout<<"[#] Estado:   <1> Bien    <2> Regular   <3> Mal"<<endl;
                                      cout<<"              <4> CANCELAR."<<endl<<endl;
                        cout<<"# ===>> ";cin>>e;
                    }while(e<0||e>4);
                    if(e==1)Estado="Bien";
                    else if(e==2)Estado="Regular";
                    else if(e==3)Estado="Mal";
                    if(e!=4){
                        int t=1;
                        do{
                            system("cls");
                            if(t<0||t>6)cout<<"#####  ERROR  #####"<<endl;
                            //silla, mesa, buró, cama, mueble PC
                            fflush(stdin);cout<<"[#] Tipo:   <1> Silla.     <2> Mesa.     <3> Buro."<<endl;
                                          cout<<"              <4> Cama.      <5> Mueble de PC."<<endl;
                                          cout<<"               <6> CANCELAR."<<endl<<endl;
                            cout<<"# ===>> ";cin>>t;
                        }while(t<0||t>6);
                        if(t==1)Tipo="Silla";
                        else if(t==2)Tipo="Mesa";
                        else if(t==3)Tipo="Buro";
                        else if(t==4)Tipo="Cama";
                        else if(t==5)Tipo="Mueble PC";
                        if(t!=6){
                            fflush(stdin);cout<<"[#] Proveedor: ";getline(cin,Proveedor);
                            fflush(stdin);cout<<"[#] Tiempo Explotacion: ";cin>>Explotacion;
                            int l=1;
                            do{
                                system("cls");
                                if(l<0||l>6)cout<<"#####  ERROR  #####"<<endl;
                                //laboratorio, aula, apartamento, oficina
                                fflush(stdin);cout<<"[#] Ubicacion:   <1> Laboratorio.     <2> Aula.     <3> Apartamento."<<endl;
                                              cout<<"              <4> Oficina.      <5> CANCELAR."<<endl<<endl;
                                cout<<"# ===>> ";cin>>l;
                            }while(l<0||l>5);
                            if(l==1)Local="Laboratorio";
                            else if(l==2)Local="Aula";
                            else if(l==3)Local="Apartamento";
                            else if(l==4)Local="Oficina";
                            if(l!=5){
                                Mobiliario* nuevo=new Mobiliario(Inventario,CostoUnitario,Estado,Tipo,Proveedor,Explotacion,Local);
                                Admin->AggMedio(nuevo);
                            }else cout<<"[#] Proceso Cancelado."<<endl;
                        }else cout<<"[#] Proceso Cancelado."<<endl;
                    }else cout<<"[#] Proceso Cancelado."<<endl;
                }else cout<<"#####  ERROR  #####"<<endl;
            }else cout<<"[#] No hay Capacidad Pera nuevo Medio.\n";
        }else if(opc==2){
            if(Admin->getCantReal()>0){
                int t;
                cout<<"[#] Seleccione Tipo.\n";
                cout<<"[1] Electronico."<<endl;
                cout<<"[2] Mobiliario."<<endl<<endl;
                cout<<"# ===>> ";cin>>t;
                system("cls");
                int d;
                if(t==1){
                    if(Admin->CantElectronico()>0){
                        Admin->DataElectronico();
                        cout<<"\n\nSELECCIONE INDEXADO ==>> ";cin>>d;
                        if(d>0&&d<=Admin->CantElectronico()){
                            if(dynamic_cast<Electronico*>(Admin->getListaMedios(d))){
                                Admin->EliminarMedio(d);
                            }else cout<<"[#] El medio insertado no es Electronico."<<endl;
                        }else cout<<"#####  ERROR  #####"<<endl;
                    }else cout<<"[#] No hay Medios Electronicos Registrados.\n";
                }else if(t==2){
                    if(Admin->CantMobiliario()>0){
                        Admin->DataMobiliario();
                        cout<<"\n\nSELECCIONE INDEXADO ==>> ";cin>>d;
                        if(d>0&&d<=Admin->CantMobiliario()){
                            if(dynamic_cast<Mobiliario*>(Admin->getListaMedios(d))){
                                Admin->EliminarMedio(d);
                            }else cout<<"[#] El medio insertado no es Mobiliario."<<endl;
                        }else cout<<"#####  ERROR  #####"<<endl;
                    }else cout<<"[#] No hay Medios Mobiliarios Registrados."<<endl;
                }else cout<<"#####  ERROR  #####"<<endl;
            }else cout<<"[#] No hay medios Registrados."<<endl;
        }else if(opc==3){
            if(Admin->getCantReal()>0){
                if(Admin->CantElectronico()>0){
                    string Tipo;
                    fflush(stdin);cout<<"[#] Inserte Tipo: ";getline(cin,Tipo);
                    Admin->CantMarcaxTipo(Tipo);
                }else cout<<"[#] No hay Medios Electronicos Registrados."<<endl;
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==4){
            if(Admin->getCantReal()>0){
                Admin->CantMalEstadoxTipo();
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==5){
            if(Admin->getCantReal()>0){
                if(Admin->CantElectronico()>0){
                    Admin->MaxMinGarantia();
                }else cout<<"[#] No hay Medios Electronicos Registrados."<<endl;
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==6){
            if(Admin->getCantReal()>0){
                Admin->Principales_Proveedores();
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==7){
            if(Admin->getCantReal()>0){
                if(Admin->CantMobiliario()>0){
                    cout<<Admin->CantMueblesxTipo();
                }else cout<<"[#] No hay Medios Mobiliarios Registrados."<<endl;
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==8){
            if(Admin->getCantReal()>0){
                Admin->CostoxTipo();
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==9){
            if(Admin->getCantReal()>0){
                Admin->CostoPromedioxTipo();
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==10){
            if(Admin->getCantReal()>0){
                if(Admin->CantMobiliario()>0){
                    Admin->DataMobiliario();
                }else cout<<"[#] No hay Medios Mobiliarios Registrados."<<endl;
            }else cout<<"[#] No hay Medios Registrados."<<endl;
        }else if(opc==11){
            cout<<"[#] Hasta Pronto."<<endl;
        }else cout<<"#####  ERROR  #####"<<endl;
        system("pause");
    }while(opc!=11);
    return 0;
}
