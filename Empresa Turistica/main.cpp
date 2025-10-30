#include <iostream>
#include <fstream>
#include "Vehiculo.h"
#include "Carro.h"
#include "Guagua.h"
#include "Excursion.h"
#include "Persona.h"
#include "Guia.h"
#include "Turista.h"
#include "Empresa.h"
using namespace std;
Empresa* Cubatur;

void GestionExc(int n);
int main()
{
    ifstream in;
    in.open("Salve.txt");
    int MaxExcursiones,MaxGuias,MaxVehiculos;
    if(!in){
        cout<<"[#] Maxima cantidad de Excursiones: ";cin>>MaxExcursiones;
        cout<<"[#] Maxima Cantidad de Guias: ";cin>>MaxGuias;
        cout<<"[#] Maxima Cantidad de Vehiculos: ";cin>>MaxVehiculos;
        Cubatur=new Empresa(MaxExcursiones,MaxGuias,MaxVehiculos);
    }else{
        int CantExcursiones,CantGuias,CantVehiculos;
        in>>MaxExcursiones>>MaxGuias>>MaxVehiculos;
        in>>CantExcursiones>>CantGuias>>CantVehiculos;
        in.ignore();
        Cubatur=new Empresa(MaxExcursiones,MaxGuias,MaxVehiculos);
        for(int i=0;i<CantGuias;i++){
            string Nombre;
            fflush(stdin);getline(in,Nombre);
            Guia* nuevo=new Guia(Nombre);
            Cubatur->AggGuia(nuevo);
            nuevo=NULL;
        }
        for(int i=0;i<CantVehiculos;i++){
            int tipo;
            in>>tipo;in.ignore();
            if(tipo==1){
                string Matricula; int CantAsientos; string Chofer;
                getline(in,Matricula);
                in>>CantAsientos;in.ignore();
                getline(in,Chofer);
                Carro* nuevo=new Carro(Matricula,CantAsientos,Chofer);
                Cubatur->AggVehiculo(nuevo);
                nuevo=NULL;
            }else if(tipo==2){
                string Matricula; int CantAsientos; string Chofer;int CantPisos;
                getline(in,Matricula);
                in>>CantAsientos;in.ignore();
                getline(in,Chofer);
                in>>CantPisos;in.ignore();
                Guagua* nuevo=new Guagua(Matricula,CantAsientos,Chofer,CantPisos);
                Cubatur->AggVehiculo(nuevo);
                nuevo=NULL;
            }
        }
        for(int i=0;i<CantExcursiones;i++){
            int NumeroExc;string NombreExc;float PrecioxP; string Nombre; string Matricula;bool Guiada;
            in>>NumeroExc;in.ignore();
            getline(in,NombreExc);
            in>>PrecioxP;in.ignore();
            in>>Guiada;in.ignore();
            Guia* guia=NULL;
            if(Guiada==true){
                getline(in,Nombre);
                for(int j=0;j<CantGuias;j++){
                    if(Cubatur->getListaGuias(j+1)->getNombre()==Nombre){
                        guia=Cubatur->getListaGuias(j=1);
                    }
                }
            }
            Vehiculo* nuevo=NULL;
            getline(in,Matricula);
            for(int j=0;j<CantVehiculos;j++){
                if(Cubatur->getListaVehiculos(j+1)->getMatricula()==Matricula){
                    nuevo=Cubatur->getListaVehiculos(j+1);
                }
            }
            Excursion* nueva=new Excursion(NumeroExc,NombreExc,PrecioxP,guia,nuevo);
            Cubatur->AggExcursion(nueva);
            int CantRealP;
            in>>CantRealP;in.ignore();
            for(int j=0;j<CantRealP;j++){
                string Nombre;string Sexo; string Passport;
                getline(in,Nombre);
                getline(in,Sexo);
                getline(in,Passport);
                Turista* cliente=new Turista(Nombre,Sexo,Passport);
                nueva->AggTurista(cliente);
                cliente=NULL;
            }
            nueva=NULL;
            nuevo=NULL;
            guia=NULL;
        }
        system("pause");
    }
    in.close();
    int opc;
    do{
        system("cls");
        cout<<"[1] Agregar Guia."<<endl;
        cout<<"[2] Eliminar Guia."<<endl;
        cout<<"[3] Agregar Vehiculo."<<endl;
        cout<<"[4] Eliminar Vehiculo."<<endl;
        cout<<"[5] Agregar Excursion."<<endl;
        cout<<"[6] Eliminar Excursion."<<endl;
        cout<<"[7] GESTION DE EXCURSION."<<endl;
        cout<<"[8] Listado Ascendente x Recaudacion."<<endl;
        cout<<"[9] Excurciones en Guagua."<<endl;
        cout<<"[10] Info Excurcion (#Nombre)."<<endl;
        cout<<"[11] Excursiones Preco < 15 y Capacidad >50"<<endl;
        cout<<"[12] Total Dinero Recaudado."<<endl;
        cout<<"[13] Salir."<<endl<<endl;
        cout<<"# ===>> ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Cubatur->getMaxGuias()>Cubatur->getCantGuias()){
                string Nombre;
                cout<<"[#] Inserte el Nombre: ";fflush(stdin);getline(cin,Nombre);
                Guia* guia=new Guia(Nombre);
                Cubatur->AggGuia(guia);
                guia=NULL;
            }else{
                cout<<"[#] No hay Plazas disponibles para nuevo Guia."<<endl;
            }
        }else if(opc==2){
            if(Cubatur->getCantGuias()>0){
                Cubatur->DataGuias();
                cout<<"<<<INDEXADO>>> ==>> ";
                int n;cin>>n;
                if(n>0&&n<=Cubatur->getCantGuias()){
                    bool Asignado=false;
                    for(int i=0;i<Cubatur->getCantExcursiones();i++){
                        if(Cubatur->getListaExcursiones(i+1)->getguia()!=NULL)
                            if(Cubatur->getListaExcursiones(i+1)->getguia()==Cubatur->getListaGuias(n+1))Asignado=true;
                    }
                    if(Asignado==false){
                        Cubatur->EliminarGuia(n);
                    }else{
                        cout<<"[#] El guia esta asignado a una Excursion."<<endl;
                    }
                }else{
                    cout<<"<<<<<<<    ERROR    >>>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Guias Registrados."<<endl;
            }
        }else if(opc==3){
            if(Cubatur->getCantVehiculos()<Cubatur->getMaxVehiculos()){
                int v;
                cout<<"[1] Carro."<<endl;
                cout<<"[2] Autobus."<<endl;
                cout<<"# ===>> ";cin>>v;
                if(v==1){
                    string Matricula;
                    int CantAsientos;
                    string Chofer;
                    fflush(stdin);cout<<"[#] Matricula: ";getline(cin,Matricula);
                    fflush(stdin);cout<<"[#] Cantidad de Asientos: ";cin>>CantAsientos;
                    fflush(stdin);cout<<"[#] Chofer: ";getline(cin,Chofer);fflush(stdin);
                    Vehiculo* Trans=new Carro(Matricula,CantAsientos,Chofer);
                    Cubatur->AggVehiculo(Trans);
                    Trans=NULL;
                }else if(v==2){
                    string Matricula;
                    int CantAsientos;
                    string Chofer;
                    int CantPisos;
                    fflush(stdin);cout<<"[#] Matricula: ";getline(cin,Matricula);
                    fflush(stdin);cout<<"[#] Cantidad de Asientos: ";cin>>CantAsientos;
                    fflush(stdin);cout<<"[#] Chofer: ";getline(cin,Chofer);fflush(stdin);
                    fflush(stdin);cout<<"[#] Cantidad de Pisos: ";cin>>CantPisos;fflush(stdin);
                    Vehiculo* Trans=new Guagua(Matricula,CantAsientos,Chofer,CantPisos);
                    Cubatur->AggVehiculo(Trans);
                    Trans=NULL;
                }else{
                    cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay capacidad para nuevo Vehiculo."<<endl;
            }
        }else if(opc==4){
            if(Cubatur->getCantVehiculos()>0){
                Cubatur->DataVehiculos();
                cout<<"<<<<INDEXADO>>>> ==>> ";int n;cin>>n;
                if(n>0&&n<=Cubatur->getCantVehiculos()){
                    bool Asignado=false;
                    for(int i=0;i<Cubatur->getCantExcursiones();i++){
                        if(Cubatur->getListaExcursiones(i+1)->getTrans()==Cubatur->getListaVehiculos(n))Asignado=true;
                    }
                    if(Asignado==false){
                        Cubatur->EliminarVehiculo(n);
                    }else{
                        cout<<"[#] El Vehiculo esta Asignado a una Excursion."<<endl;
                    }
                }else{
                    cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Vehiculos Registrados."<<endl;
            }
        }else if(opc==5){
            if(Cubatur->getCantExcursiones()<Cubatur->getMaxExcursiones()){
                if(Cubatur->getCantVehiculos()>0){
                    int NumeroExc;
                    string NombreExc;
                    float PrecioxP;
                    Guia* guia=NULL;
                    Vehiculo* Trans;

                    fflush(stdin);cout<<"[#] Numero de Excursion: ";cin>>NumeroExc;
                    fflush(stdin);cout<<"[#] Nombre de Excursion: ";getline(cin,NombreExc);
                    fflush(stdin);cout<<"[#] Precio por Persona: ";cin>>PrecioxP;
                    int n;
                    do{
                        system("cls");
                        Cubatur->DataVehiculos();
                        cout<<"<<<< INDEXADO >>>>  ==>> ";
                        cin>>n;
                    }while(n<1||n>Cubatur->getCantVehiculos());
                    Trans=Cubatur->getListaVehiculos(n);

                    char c;
                    bool continuar=true;
                    do{
                        if(continuar==false){
                            cout<<"<<<< Error >>>>"<<endl;
                        }else continuar=false;
                        fflush(stdin);cout<<"[#] Tiene Guia S/N: ";cin>>c;
                        if(c=='s'||c=='S'){
                            if(Cubatur->getCantGuias()>0){
                                int n;
                                do{
                                    system("cls");
                                    Cubatur->DataGuias();
                                    cout<<"<<<< INDEXADO >>>>  ==>> ";cin>>n;
                                }while(n<1||n>Cubatur->getCantGuias());
                                guia=Cubatur->getListaGuias(n);
                                continuar=true;
                            }
                        }else if(c=='n'||c=='N')continuar=true;
                    }while(continuar==false);

                    Excursion* Salida=new Excursion(NumeroExc,NombreExc,PrecioxP,guia,Trans);
                    Cubatur->AggExcursion(Salida);
                    Salida=NULL;
                    Trans=NULL;
                    guia=NULL;
                }else cout<<"[#] No hay Vehiculos disponibles."<<endl;
            }else cout<<"[#] No hay capacidad para una nueva excurcion."<<endl;
        }else if(opc==6){
            if(Cubatur->getCantExcursiones()>0){
                Cubatur->DataExcursiones();
                cout<<"<<<<INDEXADO>>>> ==>> ";int n;cin>>n;
                if(n>0&&n<=Cubatur->getCantExcursiones()){
                    Cubatur->EliminarExcursion(n);
                }else{
                    cout<<"<<<<<<<  ERROR  >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Excursiones Registradas."<<endl;
            }
        }else if(opc==7){
            if(Cubatur->getCantExcursiones()>0){
                int n;
                Cubatur->DataExcursiones();
                cout<<"<<<INDEXADO>>> ==>> ";cin>>n;
                if(n>0&&n<=Cubatur->getCantExcursiones()){
                    GestionExc(n);
                }else{
                    cout<<"<<<<ERROR>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Excursiones Registradas."<<endl;
            }
        }else if(opc==8){
            if(Cubatur->getCantExcursiones()>0){
                Cubatur->Recaudacion();
            }else cout<<"[#] No hay Excursiones Registradas."<<endl;
        }else if(opc==9){
            if(Cubatur->getCantExcursiones()>0){
                Cubatur->DataExcGuagua();
            }else cout<<"[#] No hay Excursiones Registradas."<<endl;
        }else if(opc==10){
            if(Cubatur->getCantExcursiones()>0){
                string Nombre;
                fflush(stdin);cout<<"[#] Inserte Nombre de la Excursion Deseada: ";
                getline(cin,Nombre);
                Cubatur->BuscarExcurcion(Nombre);
            }else cout<<"[#] No hay Excursiones Registradas."<<endl;
        }else if(opc==11){
            if(Cubatur->getCantExcursiones()>0){
                cout<<"[#] Cantidad de excursiones de Precio<15  y  Capacidad > 50: "<<endl;
                cout<<"[#] ===>> "<<Cubatur->CantExcCondicion();
            }else cout<<"[#] No hay Excursiones Registradas."<<endl;
        }else if(opc==12){
            cout<<"[#] Ganancia Neta: "<<Cubatur->getGanancia()<<endl;
        }else if(opc==13){
            cout<<"[#] Hasta Pronto."<<endl;
        }else{
            cout<<"<<<<ERROR>>>>"<<endl;
        }
        system("pause");
    }while(opc!=13);
    ofstream out;
    out.open("Salve.txt");
    out<<Cubatur->getMaxExcursiones()<<" "<<Cubatur->getMaxGuias()<<" "<<Cubatur->getMaxVehiculos()<<"\n";
    out<<Cubatur->getCantExcursiones()<<" "<<Cubatur->getCantGuias()<<" "<<Cubatur->getCantVehiculos()<<"\n";
    for(int i=0;i<Cubatur->getCantGuias();i++){
        out<<Cubatur->getListaGuias(i+1)->getNombre()<<"\n";
    }
    for(int i=0;i<Cubatur->getCantVehiculos();i++){
        if(dynamic_cast<Carro*>(Cubatur->getListaVehiculos(i+1))){
            out<<"1\n";
            out<<Cubatur->getListaVehiculos(i+1)->getMatricula()<<"\n";
            out<<Cubatur->getListaVehiculos(i+1)->getCantAsientos()<<"\n";
            out<<Cubatur->getListaVehiculos(i+1)->getChofer()<<"\n";
        }
        if(dynamic_cast<Guagua*>(Cubatur->getListaVehiculos(i+1))){
            out<<"2\n";
            out<<Cubatur->getListaVehiculos(i+1)->getMatricula()<<"\n";
            out<<Cubatur->getListaVehiculos(i+1)->getCantAsientos()<<"\n";
            out<<Cubatur->getListaVehiculos(i+1)->getChofer()<<"\n";
            Guagua* aux=dynamic_cast<Guagua*>(Cubatur->getListaVehiculos(i+1));
            out<<aux->getCantPisos()<<"\n";
        }
    }
    for(int i=0;i<Cubatur->getCantExcursiones();i++){
        //int NumeroExc,string NombreExc,float PrecioxP, Guia* guia, Vehiculo* Trans
        out<<Cubatur->getListaExcursiones(i+1)->getNumeroExc()<<"\n";
        out<<Cubatur->getListaExcursiones(i+1)->getNombreExc()<<"\n";
        out<<Cubatur->getListaExcursiones(i+1)->getPrecioxP()<<"\n";
        out<<Cubatur->getListaExcursiones(i+1)->getGuiada()<<"\n";
        if(Cubatur->getListaExcursiones(i+1)->getGuiada()==true)
            out<<Cubatur->getListaExcursiones(i+1)->getguia()->getNombre()<<"\n";
        out<<Cubatur->getListaExcursiones(i+1)->getTrans()->getMatricula()<<"\n";

        out<<Cubatur->getListaExcursiones(i+1)->getCantRealP()<<"\n";
        for(int j=0;j<Cubatur->getListaExcursiones(i+1)->getCantRealP();j++){
            //string Nombre,string Sexo, string Passport
            out<<Cubatur->getListaExcursiones(i+1)->getListaPersonas(j+1)->getNombre()<<"\n";
            Turista* aux=dynamic_cast<Turista*>(Cubatur->getListaExcursiones(i+1)->getListaPersonas(j+1));
            out<<aux->getSexo()<<"\n";
            out<<aux->getPassport()<<"\n";
        }
    }
    out.close();
    return 0;
}


void GestionExc(int n){
    int opc;
    do{
        system("cls");
        cout<<"[1] REALIZAR RESERVACION"<<endl;
        cout<<"[2] VOLVER."<<endl;
        cout<<"# ====>> ";cin>>opc;
        if(opc==1){
            string Nombre,Sexo,Passport;
            fflush(stdin);cout<<"[#] Nombre: ";getline(cin,Nombre);
            fflush(stdin);cout<<"[#] Sexo: ";getline(cin,Sexo);
            fflush(stdin);cout<<"[#] Pasaporte: ";getline(cin,Passport);
            Turista* nuevo=new Turista(Nombre,Sexo,Passport);
            Cubatur->getListaExcursiones(n)->AggTurista(nuevo);
            nuevo=NULL;
        }else if(opc>2||opc<1){
            cout<<"<<<ERROR>>>"<<endl;
        }
    }while(opc!=2);
    return;
}
