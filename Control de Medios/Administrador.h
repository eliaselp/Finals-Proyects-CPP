#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include "Medio.h"
#include "Electronico.h"
#include "Mobiliario.h"
#include <fstream>
using namespace std;
class Administrador
{
    public:
        Administrador(int MaxMedios);
        virtual ~Administrador();
        /********/
        Medio* getListaMedios(int n);
        int getCantReal();
        int getMaxMedios();

        void AggMedio(Medio* nuevo);
        void EliminarMedio(int n);

        void CantMarcaxTipo(string Tipo);
        void CantMalEstadoxTipo();
        void MaxMinGarantia();
        void Principales_Proveedores();
        string CantMueblesxTipo();

        void CostoxTipo();
        void CostoPromedioxTipo();
        //silla, mesa, buró, cama, mueble PC
        int CantMobiliario();
        int CantSilla();
        int CantMesa();
        int CantBuro();
        int CantCama();
        int CantMueblePC();
        //refrigerador, TV, video, ventilador, aire acondicionado, computadora
        int CantElectronico();
        int CantRefrigerador();
        int CantTV();
        int CantVideo();
        int CantVentilador();
        int CantAireAcondicionado();
        int CantComputadora();

        void DataElectronico();
        void DataRefrigerador();
        void DataTV();
        void DataVideo();
        void DataVentilador();
        void DataAireAcondicionado();
        void DataComputadora();

        void DataMobiliario();
        void DataSilla();
        void DataMesa();
        void DataBuro();
        void DataCama();
        void DataMueblePC();
    protected:

    private:
        Medio**ListaMedios;
        int CantReal;
        int MaxMedios;
};

#endif // Administrador_H
