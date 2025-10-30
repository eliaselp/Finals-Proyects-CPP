#ifndef CENTRAL_H
#define CENTRAL_H
#include <iostream>
#include "Cliente.h"
#include "Estatal.h"
#include "Residencial.h"
#include "Llamada.h"
#include "Internacional.h"
#include "Nacional.h"
using namespace std;

class Central
{
    public:
        Central(int CantPaises, int TeleseleccionInternacional,int TeleseleccionProvincial);
        virtual ~Central();
        //--------------------------------------------------------------------------------
        Cliente* getCliente(int n);
        int getCantClientes();
        int getCantPaises();
        int getCantLlamadas();
        int getTeleseleccionInternacional();
        int getTeleseleccionProvincial();
        //----------------------------------------
        bool BuscarPais(int Code);
        int getPosPais(int Code);
        float getTarifa(int n);
        //----------------------------------------
        void AggCliente(Cliente* nuevo);
        void BanearCliente(int n);
        void ActivarCliente(int n);
        void AggLlamada(Llamada* nueva);
        //----------------------------------------
        int CantActivos();
        int CantBaneados();
        int CantEstatalAct();
        int CantResidencialAct();
        int CantEstatalIN();
        int CantResidencialIN();
        int CantInternacional();
        int CantNacional();
        void DataClientes();
        void DataActivo();
        void DataInactivo();
        //-----------------------------------------
        void DataEstatalACT();
        void DataResidencialACT();
        void DataEstatalIN();
        void DataResidencialIN();

        void DataRegistro();
        void DataInternacional();
        void DataNacional();
        //-------------------------------------------
        float Deuda(int n);
        void RunRastreo(int n);
        void ClienteEspecial();
        void ListadoClientesTeleseleccion();
    protected:

    private:
        Cliente* ListaClientes;
        int CantClientes;
        Llamada* Registro;
        int CantLlamadas;

        int CantPaises;
        int* CodigoPaises;
        float* Tarifas;
        int TeleseleccionInternacional;
        int TeleseleccionProvincial;
};

#endif // CENTRAL_H
