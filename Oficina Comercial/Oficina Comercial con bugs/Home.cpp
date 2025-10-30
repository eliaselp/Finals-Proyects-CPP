#include "Home.h"

Home::Home(string Nombre, string Direccion, string Telefono,string CI):Usuario(Nombre,Direccion,Telefono)
{
    this->CI=CI;
}

Home::~Home()
{
    //dtor
}

string Home::getCI(){
    return this->CI;
}


/***************************************************************************/
/******************  METODOS OVERRIDE   ******************************/
/***************************************************************************/
void Home::DataUsuario(){
    cout<<"[#] Tipo: Particular."<<endl;
    Usuario::DataUsuario();
    cout<<"[#] Indentificion Permanente: "<<this->CI<<endl;
    cout<<"[#] Estado: ";
    if(this->getCategoria()==1)cout<<"Activo."<<endl;
    if(this->getCategoria()==2)cout<<"En Cola."<<endl;
    if(this->getCategoria()==3)cout<<"Baneado."<<endl;
    return;
}

void Home::setConsumo(int Mes){
    if(this->Pay==false){
        if(this->Minutos>300){
            int d=this->Minutos-300;
            this->Consumo[Mes-1]=6.25+(d*0.05);
        }else if(this->Minutos<=300&&this->Minutos>0){
            this->Consumo[Mes-1]=6.25;
        }else{
            this->Consumo[Mes-1]=0;
        }
    }else{
        if(Mes==12)Mes=1;
        if(this->Minutos>300){
            int d=this->Minutos-300;
            this->Consumo[Mes]=6.25+(d*0.05);
        }else if(this->Minutos<=300&&this->Minutos>0){
            this->Consumo[Mes]=6.25;
        }else{
            this->Consumo[Mes]=0;
        }
    }
    return;
}
