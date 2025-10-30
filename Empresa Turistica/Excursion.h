#ifndef EXCURSION_H
#define EXCURSION_H
#include <iostream>
#include "Persona.h"
#include "Guia.h"
#include "Turista.h"
#include "Vehiculo.h"
#include "Carro.h"
#include "Guagua.h"
using namespace std;

class Excursion
{
    public:
        Excursion(int NumeroExc,string NombreExc,float PrecioxP, Guia* guia, Vehiculo* Trans);
        virtual ~Excursion();
        /***************/
        int getNumeroExc();
        string getNombreExc();
        float getPrecioxP();
        int getCantRealP();
        Persona* getListaPersonas(int n);
        bool getGuiada();
        Guia* getguia();
        Vehiculo* getTrans();
        /***************/

        void AggTurista(Turista* nuevo);
        float PrecioExc();
        void INFO();
    protected:

    private:
        int NumeroExc;
        string NombreExc;
        float PrecioxP;
        int CantRealP;
        Persona**ListaPersonas;

        bool Guiada;
        Guia* guia;

        Vehiculo* Trans;
};

#endif // EXCURSION_H
