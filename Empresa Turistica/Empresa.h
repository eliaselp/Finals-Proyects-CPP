#ifndef EMPRESA_H
#define EMPRESA_H
#include "Vehiculo.h"
#include "Excursion.h"
#include "Carro.h"
#include "Guagua.h"
#include "Persona.h"
#include "Guia.h"
#include "Turista.h"
#include <iostream>
using namespace std;
class Empresa
{
    public:
        Empresa(int MaxExcursiones,int MaxGuias, int MaxVehiculos);
        virtual ~Empresa();
        /**********/
        Vehiculo* getListaVehiculos(int n);
        int getCantVehiculos();
        int getMaxVehiculos();
        Guia* getListaGuias(int n);
        int getCantGuias();
        int getMaxGuias();
        Excursion* getListaExcursiones(int n);
        int getCantExcursiones();
        int getMaxExcursiones();
        float getGanancia();
        int getTotalTuristas();
        /**********/
        int CantExcGuagua();
        /**********/
        void AggVehiculo(Vehiculo* Trans);
        void AggGuia(Guia* guia);
        void AggExcursion(Excursion* guia);
        void EliminarVehiculo(int n);
        void EliminarGuia(int n);
        void EliminarExcursion(int n);

        /*********/
        void DataVehiculos();
        void DataGuias();
        void DataExcursiones();
        /*********/
        void Recaudacion();
        void DataExcGuagua();
        void BuscarExcurcion(string Nombre);
        int CantExcCondicion();
        int GuiaCantExc(string Nombre);
        void OrdenExcDir();
    protected:

    private:
        Vehiculo** ListaVehiculos;
        int CantVehiculos;
        int MaxVehiculos;
        Guia** ListaGuias;
        int CantGuias;
        int MaxGuias;
        Excursion** ListaExcursiones;
        int CantExcursiones;
        int MaxExcursiones;
        float Ganancia;
        int totalTuristas;
};

#endif // EMPRESA_H
