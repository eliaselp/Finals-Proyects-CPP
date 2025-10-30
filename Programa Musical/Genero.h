#ifndef GENERO_H
#define GENERO_H

#include <iostream>
using namespace std;

class Genero
{
    public:
        Genero(int Duracion,string Autor,int Anio,int Votos,int CantDiscos);
        virtual ~Genero();
        //------------------------------------------------------------------------
        int getDuracion();
        string getAutor();
        int getAnio();
        int getVotos();
        int getCantDiscos();
        float getLevel_Accepted();
        float getCostoProduccion();
        //--------------------------------------------------------------------------
        void setDuracion(int Duracion);
        void setAutor(string Autor);
        void setAnio(int Anio);
        void setVotos(int Votos);
        void setCantDiscos(int CantDiscos);
        //----------------------------------------------------------------------------
        virtual void setLevel_Accepted()=0;
        virtual void setCostoProduccion()=0;
    protected:
        float CostoProduccion;
        float Level_Accepted;
    private:
        int Duracion;
        string Autor;
        int Anio;
        int Votos;
        int CantDiscos;
};

#endif // GENERO_H
