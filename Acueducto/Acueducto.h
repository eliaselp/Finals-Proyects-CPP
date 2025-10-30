#ifndef ACUEDUCTO_H
#define ACUEDUCTO_H
#include <iostream>
#include <fstream>
#include "Deposito.h"
#include "Tanque.h"
#include "Cisterna.h"
#include "Simple.h"
#include "Compuesta.h"
#include "Equipo.h"
#include "Turbina.h"
#include "Bomba.h"

using namespace std;

class Acueducto
{
    public:
        Acueducto(int CantMaxDepositos, int CantMaxEquipos);
        virtual ~Acueducto();
        //--------------------------------
        int getCantMaxDepositos();
        int getCantDepositos();
        Deposito* getListaDepositos(int n);
        Equipo* getListaEquipos(int n);
        int getCantMaxEquipos();
        int getCantEquipos();
        //----------------------------------Hidraulic
        void AggDeposito(Deposito* nuevo);
        void EliminarDeposito(int n);
        void AggEquipo(Equipo* nuevo);
        void EliminarEquipo(int n);
        //-------------------------------------
        int CantTanque();
        //los de fibrocemento, 2do los de metal, 3ro los de plástico
        int CantTFibro();
        int CantTMetal();
        int CantTPlastico();
        int CantCisterna();
        int CantCisSimple();
        int CantCisCompuesta();
        int CantBomba();
        int CantTurbina();
        //----------------------------------------
        string DataDeposito();
        string DataTanque();
        string DataCisterna();
        string DataCisSimple();
        string DataCisCompuesta();
        string DataEquipo();
        string DataBomba();
        string DataTurbina();
        //----------------------------------------
        void InfoDeposito(int Estado,string Abasto);
        void InfoOrdenMaterial();
        void EquipoMaxRegimen();
        float TiempoPromedioBombaBuenas();
        void EstadoTurbinaMaxFuerza();
        float CapacidadTotalCisternas(string Forma);//Fichero
        float CapacidadTotalCisternas(int Compartimientos);//Fichero

    protected:

    private:
        int CantMaxDepositos;
        int CantDepositos;
        Deposito** ListaDepositos;

        Equipo** ListaEquipos;
        int CantMaxEquipos;
        int CantEquipos;
};

#endif // ACUEDUCTO_H
