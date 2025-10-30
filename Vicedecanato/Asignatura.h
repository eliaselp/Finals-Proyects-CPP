#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <iostream>
using namespace std;

class Asignatura
{
    public:
        Asignatura(string Nombre,float NotaFinal,int Anio,int Semestre);
        virtual ~Asignatura();
        //--------------------------------
        string getNombre();
        float getNotaFinal();
        int getAnio();
        int getSemestre();
        //------------------------------
        void DataAsignatura();
    protected:

    private:
        string Nombre;
        float NotaFinal;
        int Anio;
        int Semestre;
};

#endif // ASIGNATURA_H
