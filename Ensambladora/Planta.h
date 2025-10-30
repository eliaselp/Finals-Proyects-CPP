#ifndef PLANTA_H
#define PLANTA_H
#include <iostream>
#include "Vehiculo.h"
#include "Motor.h"
#include "Alta.h"
#include "Fuerza.h"
#include "Trabajo.h"
#include "Bus.h"
#include "Formula.h"
#include "Deportivo.h"
#include "Lujo.h"
using namespace std;


class Planta
{
    public:
        Planta(int MaxMotores,int MaxCarros);
        virtual ~Planta();
        //-------------------------------------------
        Motor* getListaMotores(int n);
        int getMaxMotores();
        int getCantMotores();

        Vehiculo* getListaCarros(int n);
        int getMaxCarros();
        int getCantCarros();
        float getGanancia();
        //-----------------------------------------
        void setGanancia(float entrada);
        //------------------------------------------
        int CantFuerza();
        int CantTrabajo();
        int CantArtesanal();
        int CantAlta();

        int CantFormula();
        int CantBus();
        int CantDeportivo();
        int CantLujo();
        //------------------------------------------
        string DataMotores();
        string DataFuerza();
        string DataTrabajo();
        string DataAlta();
        string DataArtesanal();

        string DataCarros();
        string DataFormula();
        string DataBus();
        string DataDeportivo();
        string DataLujo();
        //-----------------------------------------
        void AggVehiculo(Vehiculo* nuevo);
        void ELiminarVehiculo(int n);
        void AggMotor(Motor* nuevo);
        void EliminarMotor(int n);
        void UtilizarMotor(int m);
        //-----------------------------------------
        void VenderVehiclo(int n);
        void DesmantelarVehiculo(int n);
        //------------------------------------------
        void CarrosMaxVelocidad();//150
        void BusMaxPlazas();
        void CarroMotorReensamblado();//Cuanto dsminuyo su precio.

    protected:
        float Ganancia;
    private:
        Motor** ListaMotores;
        int MaxMotores;
        int CantMotores;

        Vehiculo** ListaCarros;
        int MaxCarros;
        int CantCarros;

};

#endif // PLANTA_H
