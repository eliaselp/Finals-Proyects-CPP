#ifndef INTERNACIONAL_H
#define INTERNACIONAL_H
#include "Llamada.h"
#include "Cliente.h"
#include "Estatal.h"
using namespace std;
class Internacional:public Llamada
{
    public:
        Internacional(int Duracion, Cliente* Emisor,int NumeroReceptor,int Hora,int Minuto,string Fecha,float Tarifa,int CodigoTeleseleccionInternacional,int CodigoPais,int CodigoProvinciaReceptor);
        virtual ~Internacional();
        /****************************************************************/
        float getTarifa();
        int getCodigoTeleseleccionInternacional();
        int getCodigoPais();
        int getCodigoProvinciaReceptor();
        /*******************************************************************/
        float ValorLlamada()override;
        void DataLlamada()override;
    protected:

    private:
        float Tarifa;
        int CodigoTeleseleccionInternacional;
        int CodigoPais;
        int CodigoProvinciaReceptor;
};

#endif // INTERNACIONAL_H
