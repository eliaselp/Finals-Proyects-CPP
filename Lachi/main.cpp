#include <iostream>
#include "Salsa.h"
#include "HeavyMetal.h"
using namespace std;

int main()
{
    HeavyMetal* cancion=new HeavyMetal(3.5,"Lachi",2023,11000000,7);

    cout<<"[#] Autor: "<<cancion->getAutor();
    delete cancion;
    return 0;
}
