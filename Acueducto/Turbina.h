#ifndef TURBINA_H
#define TURBINA_H
#include <iostream>
#include "Equipo.h"
class Turbina:public Equipo
{
    public:
        Turbina(string Estado,float Regimen,float Fuerza);
        virtual ~Turbina();
        //----------------------------
        float getFuerza();
        //----------------------------
        string DataEquipo()override;
    protected:

    private:
        float Fuerza;
};

#endif // TURBINA_H
