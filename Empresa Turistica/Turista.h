#ifndef TURISTA_H
#define TURISTA_H
#include <iostream>
#include "Persona.h"
using namespace std;

class Turista:public Persona
{
    public:
        Turista(string Nombre,string Sexo, string Passport);
        virtual ~Turista();
        /*************/
        string getSexo();
        string getPassport();
        /************/
        void InfoPersonal()override;

    protected:

    private:
        string Sexo;
        string Passport;
};

#endif // TURISTA_H
