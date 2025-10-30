#ifndef CANCION_H
#define CANCION_H
#include <iostream>
using namespace std;

class Cancion
{
    public:
        Cancion(float Duracion, string Autor, int Anio, int Votos, int CantDiscos);
        virtual ~Cancion();
        //--------------------------------------------------------------------------------
        float getDuracion();
        string getAutor();
        int getAnio();
        int getVotos();
        int getCantDiscos();
        float getCostoProduccion();
        float getNivelAceptacion();
    protected:
        float NivelAceptacion;
        float Costo;
        virtual void setNivelAceptacion()=0;
        virtual void setCostoProduccion()=0;
    private:
        float Duracion;
        string Autor;
        int Anio;
        int Votos;
        int CantDiscos;
};

#endif // CANCION_H
