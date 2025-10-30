#ifndef EQUIPO_H
#define EQUIPO_H
#include<iostream>
#include "Proyecto.h"
#include "Lider.h"
#include "Programador.h"
#include "Multimedia.h"
#include "Empresarial.h"

class Equipo
{
    public:
        Equipo(int MaxProgramadores,Lider* Jefe,Proyecto* Pincha);
        virtual ~Equipo();

        Programador* getProgramadores(int n);
        int getCantProgramadores();
        int getMaxProgramadores();
        Lider* getJefe();
        Proyecto* getPincha();
        //------------------------------------
        void AggProgramador(Programador* nuevo);
        void QuitarProgramador(int n);

    protected:

    private:
        Programador**Programadores;
        int CantProgramadores;
        int MaxProgramadores;
        Lider* Jefe;
        Proyecto* Pincha;
};

#endif // EQUIPO_H
