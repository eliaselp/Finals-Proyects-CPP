#ifndef EQUIPO_H
#define EQUIPO_H
#include <iostream>
using namespace std;

class Equipo
{
    public:
        Equipo(string Estado,float Regimen);
        virtual ~Equipo();
        //-------------------------------
        string getEstado();
        float getRegimen();
        //------------------------------
        virtual string DataEquipo();
    protected:

    private:
        string Estado;
        float Regimen;
};

#endif // EQUIPO_H
