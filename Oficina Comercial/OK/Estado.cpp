#include "Estado.h"

Estado::Estado(string Nombre, string Direccion, string Telefono,string Empresa):Usuario(Nombre,Direccion,Telefono)
{
    this->Empresa=Empresa;
}

Estado::~Estado()
{
    //dtor
}






/***************************************************************************/
/******************  METODOS GETERS   ******************************/
/***************************************************************************/
string Estado::getEmpresa(){
    return this->Empresa;
}




/***************************************************************************/
/******************  METODOS OVERRIDE   ******************************/
/***************************************************************************/
void Estado::DataUsuario(){
    cout<<"[#] Tipo: Empresarial"<<endl;
    cout<<"[#] Nombre Empresa: "<<this->Empresa<<endl;
    Usuario::DataUsuario();
    cout<<"[#] Estado: ";
    if(this->getCategoria()==1)cout<<"Activo."<<endl;
    if(this->getCategoria()==2)cout<<"En Cola."<<endl;
    if(this->getCategoria()==3)cout<<"Baneado."<<endl;
    return;
}


void Estado::setConsumo(int Mes){
    if(this->Pay==false){
        if(this->Minutos>450){
            int d=this->Minutos-450;
            this->Consumo[Mes-1]=7.00+d*0.03;
        }else if(this->Minutos>0&&this->Minutos<=450){
            this->Consumo[Mes-1]=7.00;
        }else{
            this->Consumo[Mes-1]=0;
        }
    }else{
        if(Mes==12)Mes=1;
        if(this->Minutos>450){
            int d=this->Minutos-450;
            this->Consumo[Mes]=7.00+d*0.03;
        }else if(this->Minutos>0&&this->Minutos<=450){
            this->Consumo[Mes]=7.00;
        }else{
            this->Consumo[Mes]=0;
        }
    }
    return;
}
