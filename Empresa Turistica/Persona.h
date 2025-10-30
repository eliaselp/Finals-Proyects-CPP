#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona
{
    public:
        Persona(string Nombre);
        virtual ~Persona();
        /**************/
        string getNombre();
        virtual void InfoPersonal();
    protected:

    private:
        string Nombre;
};

#endif // PERSONA_H
