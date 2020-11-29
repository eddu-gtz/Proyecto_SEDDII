#include  "cCamino.h"
#include <iostream>

using namespace std;

CCamino::CCamino()
{
   origen = new CPueblo;
   destino = new CPueblo;
}

CCamino::~CCamino()
{
}

CCamino::CCamino( CPueblo* orig, CPueblo* des, int pes)
    : origen(orig), destino(des), peso(pes){ }


void CCamino::Imprimir()
{
    cout<<"\t<=  Origen: "<<origen->nombre<<", "<<origen->estado<<"   =>\n";
    cout<<"\t    Destino: "<<destino->nombre<<", "<<destino->estado<<" \n";
    cout<<"\t    Peso: "<<peso<<endl;

}

void CCamino::Salvar(fstream& out){
    out<<GetCLSID()<<endl;
    origen->Salvar(out);
    destino->Salvar(out);
    out<<peso<<endl;
}

void CCamino::Cargar(fstream& in ){
    int CLSID;
    int satisfaccion;
    int costo;

    in>>CLSID;
    /*string nom, nombre, estado;
    getline(in, nom);
    getline(in, nombre);
    getline(in, estado);
    in>>satisfaccion;
    in>>costo;*/
    //CPueblo* pueblito = new CPueblo;

    //origen = hashpueblos.Buscar(nombre, estado);


    origen->Cargar(in);
    in>>CLSID;

    /*getline(in, nom);
    getline(in, nombre);
    getline(in, estado);
    in>>satisfaccion;
    in>>costo;*/

    //destino = hashpueblos.Buscar(nombre, estado);

    destino->Cargar(in);
    in>>peso;
}


int CCamino::GetCLSID(){
    return CLSID_CAMINO;
}

