#include <bits/stdc++.h>
//----------------------------
#include "Alta.h"
#include "Fuerza.h"
#include "Trabajo.h"
//------------------------
#include "Formula.h"
#include "Bus.h"
#include "Sport.h"
#include "Lujo.h"
//-------------------------
#include "Planta.h"
using namespace std;
//Objetos globales
Planta* Mercedez = new Planta();
//------------------------------
Motor* motor;
Alta* MotorAlta;
Fuerza* MotorFuerza;
Trabajo* MotorTrabajo;
//-------------------------------
Bus* CarroBus;
Lujo* CarroLujo;
Sport* CarroSport;
Formula* CarroFormula;

//Prototipos de Funcion
void SeccionVehiculos();
bool CrearVehiculo();
void SeccionMotores();
bool CrearMotor();
int main(){
    int planta;
    do{
        system("cls");
        cout<<"***********************************************\n";
        cout<<"****** Planta Ensambladora Mercedez Benz ******\n";
        cout<<"***********************************************\n\n";
        cout<<"[1] Seccion de MOTORES.\n";
        cout<<"[2] Seccion de VEHICULOS.\n";
        cout<<"[3] Calcular Ganancia Total.\n";
        cout<<"[4] Cumplimiento de produccion de MOTORES\n";
        cout<<"[5] Cumplimiento de produccion de VEHICULOS\n";
        cout<<"[6] Salir.\n\n";
        cout<<"[+] OPCION: ";cin>>planta;
        system("cls");
        if(planta==1){
            SeccionMotores();
        }
        if(planta==2){
            SeccionVehiculos();
        }
        if(planta==3){
            cout<<"Ganancia Total de la Empresa: "<<Mercedez->getCantCarros()<<" USD.\n";
        }
        if(planta==4){
            int n;
            cout<<"[+] Inserte total de MOTORES planificados: ";cin>>n;
            cout<<"El porcentaje de Cumplimiento es: "<<Mercedez->CumplimientoMotores(n)<<" %.\n";
        }
        if(planta==5){
            int n;
            cout<<"[+] Inserte total de VEHICULOS planificados: ";cin>>n;
            cout<<"El porcentaje de Cumplimiento es: "<<Mercedez->CumplimientoCarros(n)<<" %.\n";
        }
        if(planta==6){
            cout<<"[+] Que tenga buen dia."<<endl;
        }

        system("pause");
    }while(planta!=6);
    delete Mercedez;
    return 0;
}

//Declaracion de Funciones
void SeccionVehiculos(){
    int carro;
    do{
        system("cls");
        cout<<"[1] Ver Cantidad de Vehiculos Disponibles.\n";
        cout<<"[2] Agregar Nuevo Carro.\n";
        cout<<"[3] Tramitar Vehiculo.\n";
        cout<<"[4] Mostrar Vehiculos de Alta Velocidad.\n";
        cout<<"[5] Mostrar AutoBus de mayor Capacidad.\n";
        cout<<"[6] Ficha Tecnica de Vehiculos Disponibles.\n";
        cout<<"[7] Mostrar Carros con Motor Reensamblado.\n";
        cout<<"[8] Volver a la Planta.\n\n";
        cout<<"[+] Opcion: ";
        cin>>carro;
        system("cls");
        if(carro==1){
            cout<<"Cantidad de Vehiculos Disponibles: "<<endl;
            cout<<"[#] Formula: "<<Mercedez->CantFormula()<<endl;
            cout<<"[#] Deportivos: "<<Mercedez->CantFormula()<<endl;
            cout<<"[#] De Lujo: "<<Mercedez->CantLujo()<<endl;
            cout<<"[#] Omnibus: "<<Mercedez->CantBus()<<endl<<endl;
            cout<<"Total: "<<Mercedez->getCantCarros()<<endl;
        }
        if(carro==2){
            CrearVehiculo();
        }
        if(carro==3){
            cout<<"*********************\n";
            cout<<"[#] Tipo: Formula 1"<<endl;
            Mercedez->DataFormula();
            cout<<endl;
            cout<<"*********************\n";
            cout<<"[#] Tipo: Deportivo"<<endl;
            Mercedez->DataSport();
            cout<<endl;
            cout<<"*********************\n";
            cout<<"[#] Tipo: Lujo"<<endl;
            Mercedez->DataLujo();
            cout<<endl;
            cout<<"*********************\n";
            cout<<"[#] Tipo: Omnibus"<<endl;
            Mercedez->DataBus();
            cout<<endl<<endl<<"[#] Inserte Numero de VEHICULO: ";
            int n;cin>>n;
            system("cls");
            cout<<"[1] Vender.\n";
            cout<<"[2] Desmantelar.\n\n";
            cout<<"[#] Cancelar.\n\n";
            int opc;cin>>opc;
            if(opc==1){
                Mercedez->VenderCarro(n);
            }
            if(opc==2){
                Mercedez->DesmantelarCarro(n);
            }
        }
        if(carro==4){

        }
        if(carro==5){

        }
        if(carro==6){

        }
        if(carro==7){

        }
        system("pause");
    }while(carro!=8);
}

bool CrearVehiculo(){
    system("cls");
    cout<<"[1] Omnibus. \n";
    cout<<"[2] Deportivo.\n";
    cout<<"[3] De Lujo. \n";
    cout<<"[4] Formula 1.\n";
    cout<<"[#] Cancelar.";
    int opc;cin>>opc;
    if(opc==1){
        if(Mercedez->CantFuerza()>0){
            Mercedez->MotoresFuerza();
            cout<<"Inserte numero del Motor: ";
            int x;cin>>x;
            Fuerza* motor=dynamic_cast<Fuerza*>(Mercedez->getMotor(x));
            float VelocidadMax;
            int cantPuertas;
            cout<<"[+] Velocidad Maxima: ";cin>>VelocidadMax;
            cout<<"[+] Cantidad de Puertas: ";cin>>cantPuertas;
            CarroBus=new Bus(VelocidadMax,cantPuertas,motor);
            Mercedez->AggCarro(CarroBus);
            Mercedez->EliminarMotor(x);
            CarroBus=NULL;
            return true;
        }else{
            return false;
        }
    }
    if(opc==2){
        if(Mercedez->CantTrabajo()>0){
            Mercedez->MotoresTrabajo();
            cout<<"Inserte numero del Motor: ";
            int x;cin>>x;
            Trabajo* motor=dynamic_cast<Trabajo*>(Mercedez->getMotor(x));
            int Plazas;
            float VelocidadMax;
            int CantVelocidades;
            bool CambioUniversal;
            cout<<"[+] Plazas: ";cin>>Plazas;
            cout<<"[+] Velocidad Maxima: ";cin>>VelocidadMax;
            cout<<"[+] Cantidad de Velocidades: ";cin>>CantVelocidades;
            cout<<"[+] Cambio Universal S/N: ";
            char c;cin>>c;
            if(c=='S'||c=='s')CambioUniversal=true;
            else CambioUniversal=false;
            CarroSport=new Sport(Plazas,VelocidadMax,CantVelocidades,CambioUniversal,motor);
            Mercedez->AggCarro(CarroSport);
            Mercedez->EliminarMotor(x);
            CarroSport=NULL;
            return true;
        }else{
            return false;
        }

    }
    if(opc==3){
        //de lujo
        if(Mercedez->CantTrabajoArtesanal()>0){
            Mercedez->getDataTrabajoArtesanal();
            cout<<"[+] Inserte Numero de MOTOR: ";
            int x;cin>>x;
            system("cls");
            Trabajo* motor=dynamic_cast<Trabajo*>(Mercedez->getMotor(x));
            int Plazas;
            float VelocidadMax;
            float CostoTapiceria;
            cout<<"[+] Plazas: ";cin>>Plazas;
            cout<<"[+] Velocidad Maxima: ";cin>>VelocidadMax;
            cout<<"[+] Costo de la Tapiceria: ";cin>>CostoTapiceria;
            CarroLujo=new Lujo(Plazas,VelocidadMax,CostoTapiceria,motor);
            Mercedez->EliminarMotor(x);
            CarroLujo=NULL;
            return true;
        }else{
            return false;
        }
    }
    if(opc==4){
        Mercedez->MotoresAlta();
        cout<<"[+] Inserte el numero del MOTOR: ";
        int x;cin>>x;
        system("cls");

        Alta* motor=dynamic_cast<Alta*>(Mercedez->getMotor(x));
        float VelocidadMax;
        float PesoCarroceria;
        cout<<"[+] Velocidad Maxima: ";cin>>VelocidadMax;
        cout<<"[+] Peso de la Carroceria: ";cin>>PesoCarroceria;
        CarroFormula=new Formula(VelocidadMax,motor,PesoCarroceria);
        Mercedez->EliminarMotor(x);
        CarroFormula=NULL;
        return true;
    }else{
        return false;
    }
}




























void SeccionMotores(){
    int Motores=0;
    do{
        fflush(stdin);
        system("cls");
        cout<<"[1] Ver Cantidad de Motores Disponibles.\n";
        cout<<"[2] Ver Ficha Tecnica de Motores Disponibles.\n";
        cout<<"[3] Agregar un nuevo Motor.\n";
        cout<<"[4] Volver a la Planta.\n\n";
        cout<<"[#] Opcion: ";
        cin>>Motores;
        system("cls");
        if(Motores==1){
            cout<<"[#] Cantidad de Motores Disponibles: "<<Mercedez->getCantMotores()<<endl;
        }
        if(Motores==2){
            Mercedez->DataMotores();
        }
        if(Motores==3){
            if(CrearMotor()==true){
                system("cls");
                Mercedez->AggMotor(motor);
                motor=NULL;
            }
        }
        system("pause");
    }while(Motores!=4);
    return;
}

bool CrearMotor(){
    system("cls");
    cout<<"[1] Motor de Alta.\n";
    cout<<"[2] Motor de Fuerza\n";
    cout<<"[3] Motor de Trabajo\n";
    cout<<"[#] Cancelar.\n\n";
    cout<<"[+] Opcion: ";
    int opc;cin>>opc;
    system("cls");
    if(opc==1){
        string Codigo;
        string FechaSalida;
        string Especialista;
        float MaxRevMin;
        float Consumo;
        fflush(stdin);
        cout<<"[+] Codigo: ";getline(cin,Codigo);fflush(stdin);
        cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);fflush(stdin);
        cout<<"[+] Especialista encargado: ";getline(cin,Especialista);fflush(stdin);
        cout<<"[+] Maxima Revoluciones por Minuto: ";cin>>MaxRevMin;
        cout<<"[+] Consumo: ";cin>>Consumo;
        MotorAlta=new Alta(Codigo,FechaSalida,Especialista,MaxRevMin,Consumo);
        system("cls");
        motor=MotorAlta;
        MotorAlta=NULL;
        return true;
    }
    if(opc==2){
        string Codigo;
        string FechaSalida;
        string Especialista;
        int CaballosFuerza;
        fflush(stdin);
        cout<<"[+] Codigo: ";getline(cin,Codigo);fflush(stdin);
        cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);fflush(stdin);
        cout<<"[+] Especialista encargado: ";getline(cin,Especialista);fflush(stdin);
        cout<<"[+] Caballos de Fuerza: ";cin>>CaballosFuerza;
        MotorFuerza=new Fuerza(Codigo,FechaSalida,Especialista,CaballosFuerza);
        motor=MotorFuerza;
        MotorFuerza=NULL;
        return true;
    }
    if(opc==3){
        string Codigo;
        string FechaSalida;
        string Especialista;
        bool Artesanal;
        fflush(stdin);
        cout<<"[+] Codigo: ";getline(cin,Codigo);fflush(stdin);
        cout<<"[+] Fecha de Salida: ";getline(cin,FechaSalida);fflush(stdin);
        cout<<"[+] Especialista encargado: ";getline(cin,Especialista);fflush(stdin);
        char c;
        cout<<"[+] Es Artesanal? S/N: ";cin>>c;
        if(c=='s'||c=='S'){
            Artesanal=true;
        }else{
            Artesanal=false;
        }
        MotorTrabajo=new Trabajo(Codigo,FechaSalida,Especialista,Artesanal);
        motor=MotorTrabajo;
        MotorTrabajo=NULL;
        return true;
    }
    return false;
}
