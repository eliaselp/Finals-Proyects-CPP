#include <fstream>
#include <bits/stdc++.h>
#include "Planta.h"
#include "Motor.h"
#include "Alta.h"
#include "Fuerza.h"
#include "Trabajo.h"
#include "Vehiculo.h"
#include "Formula.h"
#include "Bus.h"
#include "Deportivo.h"
#include "Lujo.h"
using namespace std;

Planta* Mercedes;
Motor* motor;
Alta* MotorAlta;
Fuerza* MotorFuerza;
Trabajo* MotorTrabajo;
Vehiculo* Carro;
Formula* CarroFormula;
Bus* CarroBus;
Lujo* CarroLujo;
Deportivo* CarroDeportivo;

void SeccionVehiculos(int n);
int main()
{
    ifstream Load;
    Load.open("Cantidades.txt",ios::in);
    int MaxCarros,MaxMotores;
    if(Load.fail()){
        cout<<"[#] Plan de Produccion de Motores: ";cin>>MaxMotores;
        cout<<"[#] Plan de Produccion de Vehiculos: ";cin>>MaxCarros;
        Mercedes=new Planta(MaxMotores,MaxCarros);
    }else{
        Load>>MaxMotores;
        Load>>MaxCarros;
        Mercedes=new Planta(MaxMotores,MaxCarros);
        int CantMotores,CantCarros;
        float Ganancia;
        Load>>CantMotores>>CantCarros>>Ganancia;
        Load.close();
        Mercedes->setGanancia(Ganancia);
        for(int i=1;i<=CantCarros;i++){
            string CarroName="Carros "+to_string(i)+".txt";
            Load.open(CarroName.c_str());
            int Plazas;float VMax;string FechaSalida;
            Load>>Plazas>>VMax;
            getline(Load,FechaSalida,'\n');
            int Tipo;Load>>Tipo;
            if(Tipo==1){
                float PesoCarroceria;
                Load>>PesoCarroceria;Load.ignore();

                string Codigo;string FechaSalidaMotor;string Especialista;
                getline(Load,Codigo,'\n');
                getline(Load,FechaSalidaMotor,'\n');
                getline(Load,Especialista,'\n');

                float MaxRPM,Consumo;
                Load>>MaxRPM>>Consumo;
                Load.close();
                motor=new Alta(Codigo,FechaSalidaMotor,Especialista,MaxRPM,Consumo);
                Carro=new Formula(motor,Plazas,VMax,FechaSalida,PesoCarroceria);
                Mercedes->AggVehiculo(Carro);
                Carro=NULL;
                motor=NULL;
            }else if(Tipo==2){
                int CantPuertas;
                Load>>CantPuertas;Load.ignore();
                string Codigo;string FechaSalidaMotor;string Especialista;
                getline(Load,Codigo,'\n');
                getline(Load,FechaSalidaMotor,'\n');
                getline(Load,Especialista,'\n');
                float CaballosFuerza;
                Load>>CaballosFuerza;
                Load.close();
                motor=new Fuerza(Codigo,FechaSalidaMotor,Especialista,CaballosFuerza);
                Carro=new Bus(motor,Plazas,VMax,FechaSalida,CantPuertas);
                Mercedes->AggVehiculo(Carro);
                Carro=NULL;
                motor=NULL;
            }else if(Tipo==3){
                int CantidadVelocidades;bool Universal;
                Load>>CantidadVelocidades>>Universal;Load.ignore();

                string Codigo;string FechaSalidaMotor;string Especialista;
                getline(Load,Codigo,'\n');
                getline(Load,FechaSalidaMotor,'\n');
                getline(Load,Especialista,'\n');
                bool Artesanal;
                Load>>Artesanal;
                Load.close();

                motor=new Trabajo(Codigo,FechaSalidaMotor,Especialista,Artesanal);
                Carro=new Deportivo(motor,Plazas,VMax,FechaSalida,CantidadVelocidades,Universal);
                Mercedes->AggVehiculo(Carro);
                cout<<Mercedes->DataCarros();
                Carro=NULL;
                motor=NULL;
            }else if(Tipo==4){
                float CostoTapiceria;
                Load>>CostoTapiceria;Load.ignore();
                string Codigo;string FechaSalidaMotor;string Especialista;
                getline(Load,Codigo,'\n');
                getline(Load,FechaSalidaMotor,'\n');
                getline(Load,Especialista,'\n');
                bool Artesanal;
                Load>>Artesanal;
                Load.close();
                motor=new Trabajo(Codigo,FechaSalidaMotor,Especialista,Artesanal);
                Carro=new Lujo(motor,Plazas,VMax,FechaSalida,CostoTapiceria);
                Mercedes->AggVehiculo(Carro);
                Mercedes->DataCarros();
                Carro=NULL;
                motor=NULL;
            }

        }

        ifstream mot;
        for(int i=1;i<=CantMotores;i++){
            string MotorName="Motor ";MotorName+=to_string(i);MotorName+=".txt";
            mot.open(MotorName.c_str());
            string Codigo;string FechaSalida;string Especialista;
            fflush(stdin);getline(mot,Codigo);
            fflush(stdin);getline(mot,FechaSalida);
            fflush(stdin);getline(mot,Especialista);
            int tipo;mot>>tipo;
            if(tipo==1){
                float CaballoFuerza;
                mot>>CaballoFuerza;
                MotorFuerza=new Fuerza(Codigo,FechaSalida,Especialista,CaballoFuerza);
                Mercedes->AggMotor(MotorFuerza);
                MotorFuerza=NULL;
            }else if(tipo==2){
                float MaxRPM,Consumo;
                mot>>MaxRPM>>Consumo;
                MotorAlta=new Alta(Codigo,FechaSalida,Especialista,MaxRPM,Consumo);
                Mercedes->AggMotor(MotorAlta);
                MotorAlta=NULL;
            }else if(tipo==3){
                bool Artesanal;
                mot>>Artesanal;
                MotorTrabajo=new Trabajo(Codigo,FechaSalida,Especialista,Artesanal);
                Mercedes->AggMotor(MotorTrabajo);
                MotorTrabajo=NULL;
            }

            mot.close();
        }
    }
    int opc;
    system("pause");
    do{
        system("cls");
        cout<<"#######################################"<<endl;
        cout<<"#####     PLANTA ENSAMBLEDORA     #####"<<endl;
        cout<<"#####        MERCEDES BENZ        #####"<<endl;
        cout<<"#######################################"<<endl<<endl;
        cout<<"[1] Agregar Motor."<<endl;
        cout<<"[2] Eliminar Motor"<<endl;
        cout<<"[3] Agregar Vehiculo"<<endl;
        cout<<"[4] Seccion de Vehiculos"<<endl;
        cout<<"[5] Datos de Motores Disponibles"<<endl;
        cout<<"[6] Datos de Carros Mas Veloces (+150kmh)"<<endl;
        cout<<"[7] Datos Omnibus Mayor Capacidad."<<endl;
        cout<<"[8] Datos Vehiculos Disponibles."<<endl;
        cout<<"[9] Datos de Vehiculos con Motor Reensamblado."<<endl;
        cout<<"[10] Porciento de Cumplimiento de Produccion."<<endl;
        cout<<"[11] Mostrar Ganancia Total."<<endl;
        cout<<"[12] Salir"<<endl;
        cout<<"[#] OPCION  >>>>>  ";cin>>opc;
        system("cls");
        if(opc==1){
            if(Mercedes->getCantMotores()<Mercedes->getMaxMotores()){
                int m;
                cout<<"[1] Fuerza."<<endl;
                cout<<"[2] Alta."<<endl;
                cout<<"[3] Trabajo."<<endl<<endl;
                cout<<"[#] OPCION  >>>>>  ";cin>>m;
                system("cls");
                if(m==1){
                    string Codigo;
                    string FechaSalida;
                    string Especialista;
                    float CaballosFuerza;
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);
                    fflush(stdin);cout<<"[+] Especialista Encargado: ";getline(cin,Especialista);
                    fflush(stdin);cout<<"[+] Caballos de Fuerza: ";cin>>CaballosFuerza;
                    motor=new Fuerza(Codigo,FechaSalida,Especialista,CaballosFuerza);
                    Mercedes->AggMotor(motor);
                    motor=NULL;
                }else if(m==2){
                    string Codigo;
                    string FechaSalida;
                    string Especialista;
                    float MaxRPM;
                    float Consumo;
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);
                    fflush(stdin);cout<<"[+] Especialista Encargado: ";getline(cin,Especialista);
                    fflush(stdin);cout<<"[+] Maximas RPM: ";cin>>MaxRPM;
                    fflush(stdin);cout<<"[+] Consumo: ";cin>>Consumo;
                    motor=new Alta(Codigo,FechaSalida,Especialista,MaxRPM,Consumo);
                    Mercedes->AggMotor(motor);
                    motor=NULL;
                }else if(m==3){
                    string Codigo;
                    string FechaSalida;
                    string Especialista;
                    bool Artesanal;
                    fflush(stdin);cout<<"[+] Codigo: ";getline(cin,Codigo);
                    fflush(stdin);cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);
                    fflush(stdin);cout<<"[+] Especialista Encargado: ";getline(cin,Especialista);
                    char C='s';
                    do{
                        system("cls");
                        if(C!='s'&&C!='S'&&C!='n'&&C!='N')cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                        cout<<"[#] Artesanal S/N: ";
                        cin>>C;
                        if(C=='s'||C=='S')Artesanal=true;
                        else if(C=='n'||C=='N')Artesanal=false;
                    }while(C!='s'&&C!='S'&&C!='n'&&C!='N');
                    motor=new Trabajo(Codigo,FechaSalida,Especialista,Artesanal);
                    Mercedes->AggMotor(motor);
                    motor=NULL;
                }else{
                    cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay capacidad para un nuevo motor."<<endl;
            }
        }else if(opc==2){
            if(Mercedes->getCantMotores()>0){
                int m=1;
                system("cls");
                cout<<Mercedes->DataMotores();
                cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                if(m<1||m>Mercedes->getCantMotores())cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                else Mercedes->EliminarMotor(m);
            }else{
                cout<<"[#] No hay Motores Disponibles."<<endl;
            }
        }else if(opc==3){
            if(Mercedes->getCantCarros()<Mercedes->getMaxCarros()){
                int a;
                cout<<"[1] Formula 1."<<endl;
                cout<<"[2] Omnibus."<<endl;
                cout<<"[3] Deportivo."<<endl;
                cout<<"[4] Lujoso."<<endl<<endl;
                cout<<"[#] OPCION  >>>>>  ";cin>>a;
                int m=1;
                bool create=false;
                if(a==1){
                    if(Mercedes->CantAlta()>0){
                        bool Continue=true;
                        do{
                            system("cls");
                            cout<<Mercedes->DataAlta();
                            if(Continue==false)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            Continue=false;
                            cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                            if(m>=1&&m<=Mercedes->getCantMotores())
                                if(dynamic_cast<Alta*>(Mercedes->getListaMotores(m)))Continue=true;
                        }while(Continue==false);
                        Motor* motor=Mercedes->getListaMotores(m);
                        int Plazas=1;
                        float VMax;
                        string FechaSalida;
                        float PesoCarroceria;
                        cout<<"[#] Velocidad Maxima: ";cin>>VMax;
                        fflush(stdin);cout<<"[#] Fecha de Salida: ";getline(cin,FechaSalida);
                        fflush(stdin);cout<<"[#] Peso de la Carroceria: ";cin>>PesoCarroceria;
                        Carro=new Formula(motor,Plazas,VMax,FechaSalida,PesoCarroceria);
                        Mercedes->AggVehiculo(Carro);
                        create=true;
                        Carro=NULL;
                        motor=NULL;
                    }else{
                        cout<<"[#] No hay Motores de Alta."<<endl;
                    }
                }else if(a==2){
                    if(Mercedes->CantFuerza()>0){
                        bool Continue=true;
                        do{
                            system("cls");
                            cout<<Mercedes->DataFuerza();
                            if(Continue==false)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                            Continue=false;
                            if(m>=1&&m<=Mercedes->getCantMotores())
                            if(dynamic_cast<Fuerza*>(Mercedes->getListaMotores(m)))Continue=true;
                        }while(Continue==false);
                        Motor* motor=Mercedes->getListaMotores(m);
                        MotorFuerza=dynamic_cast<Fuerza*>(motor);
                        int Plazas=MotorFuerza->getCaballosFuerza()/10;
                        float VMax;
                        string FechaSalida;
                        int CantPuertas;
                        cout<<"[#] Velocidad Maxima: ";cin>>VMax;
                        fflush(stdin);cout<<"[#] Fecha de Salida: ";getline(cin,FechaSalida);
                        fflush(stdin);cout<<"[#] Cantidad de Puertas: ";cin>>CantPuertas;
                        Carro=new Bus(motor,Plazas,VMax,FechaSalida,CantPuertas);
                        Mercedes->AggVehiculo(Carro);
                        create=true;
                        Carro=NULL;
                        motor=NULL;
                        MotorFuerza=NULL;
                    }else{
                        cout<<"[#] No hay Motores de Fuerza."<<endl;
                    }
                }else if(a==3){
                    if(Mercedes->CantTrabajo()>0){
                        bool Continue=true;
                        do{
                            system("cls");
                            cout<<Mercedes->DataTrabajo();
                            if(Continue==false)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                            Continue=false;
                            if(m>=1&&m<=Mercedes->getCantMotores())
                            if(dynamic_cast<Trabajo*>(Mercedes->getListaMotores(m)))Continue=true;
                        }while(Continue==false);
                        Motor* motor=Mercedes->getListaMotores(m);
                        int Plazas=2;
                        do{
                            system("cls");
                            if(Plazas<2||Plazas>4)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[+] Plazas [2-4]: ";cin>>Plazas;
                        }while(Plazas<2||Plazas>4);
                        float VMax;
                        cout<<"[+] Velocidad Maxima: ";cin>>VMax;
                        string FechaSalida;
                        fflush(stdin);cout<<"[+] Fecha Salida: ";getline(cin,FechaSalida);
                        int CantVelocidades;
                        fflush(stdin);cout<<"[+] Cantidad de Velocidades: ";cin>>CantVelocidades;
                        bool CambioUniversal;
                        char c='s';
                        do{
                            if(c!='S'&&c!='s'&&c!='N'&&c!='n')cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[+] Cambio Universal S/N: ";cin>>c;
                            if(c=='S'||c=='s')CambioUniversal=true;
                            else if(c=='n'||c=='N')CambioUniversal=false;
                        }while(c!='S'&&c!='s'&&c!='N'&&c!='n');
                        Carro=new Deportivo(motor,Plazas,VMax,FechaSalida,CantVelocidades,CambioUniversal);
                        Mercedes->AggVehiculo(Carro);
                        create=true;
                        Carro=NULL;
                        motor=NULL;
                    }else{
                        cout<<"[#] No hay Motores de Trabajo."<<endl;
                     }
                }else if(a==4){
                    if(Mercedes->CantArtesanal()>0){
                        bool Continue=true;
                        do{
                            system("cls");
                            cout<<Mercedes->DataArtesanal();
                            if(Continue==false)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                            Continue=false;
                            if(m>=1&&m<=Mercedes->getCantMotores())
                                if(dynamic_cast<Trabajo*>(Mercedes->getListaMotores(m))){
                                    MotorTrabajo=dynamic_cast<Trabajo*>(Mercedes->getListaMotores(m));
                                    if(MotorTrabajo->getArtesanal()==true)Continue=true;
                                }
                        }while(Continue==false);
                        Motor* motor=Mercedes->getListaMotores(m);
                        int Plazas=2;
                        do{
                            system("cls");
                            if(Plazas<2||Plazas>4)cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                            cout<<"[+] Plazas [2-4]: ";cin>>Plazas;
                        }while(Plazas<2||Plazas>4);
                        float VMax;
                        cout<<"[+] Velocidad Maxima: ";cin>>VMax;
                        string FechaSalida;
                        fflush(stdin);cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);
                        float CostoTapiceria;
                        fflush(stdin);cout<<"[+] Costo de Tapiceria: ";cin>>CostoTapiceria;
                        Carro=new Lujo(motor,Plazas,VMax,FechaSalida,CostoTapiceria);
                        Mercedes->AggVehiculo(Carro);
                        create=true;
                        Carro=NULL;
                        motor=NULL;
                        MotorTrabajo=NULL;
                    }else{
                        cout<<"[+] No hay Motores de Trabajo Artesanal."<<endl;
                    }
                }else{
                    cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                }
                if(create==true){
                    Mercedes->UtilizarMotor(m);
                }
            }else{
                cout<<"[#] NO HAY ESPACIO DISPONIBLE."<<endl;
            }
        }else if(opc==4){
            if(Mercedes->getCantCarros()>0){
                int m;
                cout<<Mercedes->DataCarros();
                cout<<"[#] Inserte << INDEXADO >> ==>> ";cin>>m;
                if(m>0&&m<=Mercedes->getCantCarros()){
                    SeccionVehiculos(m);
                }else{
                    cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
                }
            }else{
                cout<<"[#] No hay Vehiculos Disponibles."<<endl;
            }
        }else if(opc==5){
            if(Mercedes->getCantMotores()>0){
                    cout<<Mercedes->DataMotores();
            }else{
                cout<<"[#] No hay Motores Disponibles."<<endl;
            }
        }else if(opc==6){
            if(Mercedes->getCantCarros()>0){
                Mercedes->CarrosMaxVelocidad();
            }else{
                cout<<"[#] No hay Vehiculos Disponibles."<<endl;
            }
        }else if(opc==7){
            if(Mercedes->CantBus()>0){
                Mercedes->BusMaxPlazas();
            }else{
                cout<<"[#] No hay Omnibus Disponibles."<<endl;
            }
        }else if(opc==8){
            if(Mercedes->getCantCarros()>0){
                cout<<Mercedes->DataCarros();
            }else{
                cout<<"[#] No hay Vehiculos Disponibles."<<endl;
            }
        }else if(opc==9){
            if(Mercedes->getCantCarros()>0){
                Mercedes->CarroMotorReensamblado();
            }else{
                cout<<"[#] No hay Vehiculos Disponibles."<<endl;
            }
        }else if(opc==10){
            float fm=((100*Mercedes->getCantMotores())/Mercedes->getMaxMotores());
            float fc=((100*Mercedes->getCantCarros())/Mercedes->getMaxCarros());
            cout<<"[#] Cumplimiento de Produccion Motores: "<<fm<<"%";
            cout<<"[#] Cumplimiento de Produccion Carros: "<<fc<<"%";
        }else if(opc==11){
            cout<<"[#] Ganancia: "<<Mercedes->getGanancia()<<endl;
        }else if(opc==12){
            cout<<"[#] Gracias por Elegirnos."<<endl;
        }else{
            cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
        }

        system("pause");
    }while(opc!=12);
    ofstream Cantidades;
    Cantidades.open("Cantidades.txt");
    Cantidades<<Mercedes->getMaxMotores()<<"\n";
    Cantidades<<Mercedes->getMaxCarros()<<"\n";
    Cantidades<<Mercedes->getCantMotores()<<"\n";
    Cantidades<<Mercedes->getCantCarros()<<"\n";
    Cantidades<<Mercedes->getGanancia()<<"\n";
    Cantidades.close();
    //////////////////////////////////////////////////////
    ofstream SalveCarros;
    for(int i=1;i<=Mercedes->getCantCarros();i++){
        string CarroName="Carros ";CarroName+=i+48;CarroName+=".txt";
        SalveCarros.open(CarroName.c_str());

        SalveCarros<<Mercedes->getListaCarros(i)->getPlazas()<<" ";
        SalveCarros<<Mercedes->getListaCarros(i)->getVMax()<<" ";
        SalveCarros<<Mercedes->getListaCarros(i)->getFechaSalida()<<"\n";
        if(dynamic_cast<Formula*>(Mercedes->getListaCarros(i))){
            SalveCarros<<"1 ";
            /**Motor* motor,int Plazas,float VMax,string FechaSalida,float PesoCarroceria**/
            CarroFormula=dynamic_cast<Formula*>(Mercedes->getListaCarros(i));
            SalveCarros<<CarroFormula->getPesoCarroceria()<<"\n";
            /** string Codigo,string FechaSalida,string Especialista,float MaxRPM,float Consumo**/
            SalveCarros<<CarroFormula->getMotor()->getCodigo()<<"\n";
            SalveCarros<<CarroFormula->getMotor()->getFechaSalida()<<"\n";
            SalveCarros<<CarroFormula->getMotor()->getEspecialista()<<"\n";
            /**/
            MotorAlta=dynamic_cast<Alta*>(CarroFormula->getMotor());
            SalveCarros<<MotorAlta->getMaxRPM()<<" ";
            SalveCarros<<MotorAlta->getConsumo()<<" ";
            CarroFormula=NULL;
            MotorAlta=NULL;
        }else if(dynamic_cast<Bus*>(Mercedes->getListaCarros(i))){
            SalveCarros<<"2 ";
            CarroBus=dynamic_cast<Bus*>(Mercedes->getListaCarros(i));
            /**int CantPuertas**/
            SalveCarros<<CarroBus->getCantPuertas()<<"\n";
            SalveCarros<<CarroBus->getMotor()->getCodigo()<<"\n";
            SalveCarros<<CarroBus->getMotor()->getFechaSalida()<<"\n";
            SalveCarros<<CarroBus->getMotor()->getEspecialista()<<"\n";

            /**float CaballosFuerza*/
            MotorFuerza=dynamic_cast<Fuerza*>(CarroBus->getMotor());
            SalveCarros<<MotorFuerza->getCaballosFuerza()<<" ";
            CarroBus=NULL;
            MotorFuerza=NULL;
        }else if(dynamic_cast<Deportivo*>(Mercedes->getListaCarros(i))){
            SalveCarros<<"3 ";
            CarroDeportivo=dynamic_cast<Deportivo*>(Mercedes->getListaCarros(i));
            /***int CantVelocidades,bool CambioUniversal**/
            SalveCarros<<CarroDeportivo->getCantVelocidades()<<" ";
            SalveCarros<<CarroDeportivo->getCambioUniversal()<<"\n";
            /**string Codigo,string FechaSalida,string Especialista,bool Artesanal**/
            SalveCarros<<CarroDeportivo->getMotor()->getCodigo()<<"\n";
            SalveCarros<<CarroDeportivo->getMotor()->getFechaSalida()<<"\n";
            SalveCarros<<CarroDeportivo->getMotor()->getEspecialista()<<"\n";

            MotorTrabajo=dynamic_cast<Trabajo*>(CarroDeportivo->getMotor());
            SalveCarros<<MotorTrabajo->getArtesanal()<<" ";
            CarroDeportivo=NULL;
            MotorTrabajo=NULL;
        }else if(dynamic_cast<Lujo*>(Mercedes->getListaCarros(i))){
            SalveCarros<<"4 ";
            CarroLujo=dynamic_cast<Lujo*>(Mercedes->getListaCarros(i));
            /**float CostoTapiceria**/
            SalveCarros<<CarroLujo->getCostoTapiceria()<<"\n";
            SalveCarros<<CarroLujo->getMotor()->getCodigo()<<"\n";
            SalveCarros<<CarroLujo->getMotor()->getFechaSalida()<<"\n";
            SalveCarros<<CarroLujo->getMotor()->getEspecialista()<<"\n";

            MotorTrabajo=dynamic_cast<Trabajo*>(CarroLujo->getMotor());
            SalveCarros<<MotorTrabajo->getArtesanal()<<" ";
            CarroLujo=NULL;
            MotorTrabajo=NULL;
        }
        SalveCarros.close();
    }
    ////////////////////////////////////////////////////////////////
    ofstream SalveMotores;
    for(int i=1;i<=Mercedes->getCantMotores();i++){
        string MotorName="Motor ";MotorName+=to_string(i);MotorName+=".txt";
        SalveMotores.open(MotorName.c_str());

        /** string Codigo,string FechaSalida,string Especialista**/
        SalveMotores<<Mercedes->getListaMotores(i)->getCodigo()<<"\n";
        SalveMotores<<Mercedes->getListaMotores(i)->getFechaSalida()<<"\n";
        SalveMotores<<Mercedes->getListaMotores(i)->getEspecialista()<<"\n";
        if(dynamic_cast<Fuerza*>(Mercedes->getListaMotores(i))){
            MotorFuerza=dynamic_cast<Fuerza*>(Mercedes->getListaMotores(i));
            SalveMotores<<"1 ";
            SalveMotores<<MotorFuerza->getCaballosFuerza()<<" ";
            MotorFuerza=NULL;
        }else if(dynamic_cast<Alta*>(Mercedes->getListaMotores(i))){
            MotorAlta=dynamic_cast<Alta*>(Mercedes->getListaMotores(i));
            SalveMotores<<"2 ";
            /** float MaxRPM,float Consumo **/
            SalveMotores<<MotorAlta->getMaxRPM()<<" ";
            SalveMotores<<MotorAlta->getConsumo()<<" ";
            MotorAlta=NULL;
        }else if(dynamic_cast<Trabajo*>(Mercedes->getListaMotores(i))){
            MotorTrabajo=dynamic_cast<Trabajo*>(Mercedes->getListaMotores(i));
            SalveMotores<<"3 ";
            SalveMotores<<MotorTrabajo->getArtesanal();
            MotorTrabajo=NULL;
        }
        SalveMotores.close();
    }
    return 0;
}


void SeccionVehiculos(int n){
    int opc;
    cout<<"[1] Vender"<<endl;
    cout<<"[2] Desmantelar"<<endl<<endl;
    cout<<"[#] OPCION  >>>>>  ";cin>>opc;
    if(opc==1){
        Mercedes->VenderVehiclo(n);
    }else if(opc==2){
        Mercedes->DesmantelarVehiculo(n);
    }else{
        cout<<"<<<<<<<     ERROR     >>>>>>>"<<endl;
    }
}

