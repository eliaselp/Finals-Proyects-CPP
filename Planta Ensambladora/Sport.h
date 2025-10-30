#ifndef SPORT_H
#define SPORT_H
#include "Carro.h"
#include "Trabajo.h"
class Sport:public Carro
{
    public:
        Sport(int Plazas, float VelocidadMax,int CantVelocidades, bool CambioUniversal, Trabajo* motor);
        virtual ~Sport();
        Trabajo* motor;
        //----------------------------------------------------------------------------
        int getCantVelocidades();
        bool getCambioUniversal();
        //-----------------------------------------------------------------------------
        void setCantVelocidades(int CantVelocidades);
        void setCambioUniversal(bool CambioUniversal);
        void setMotor(Trabajo* motor);
        //-----------------------------------------------------------------------------
        void setPrecioVenta()override;
        void FichaTecnica()override;
    protected:

    private:

        int CantVelocidades;
        bool CambioUniversal;
};

#endif // SPORT_H
