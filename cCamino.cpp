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

void CCamino::setPeso(int pes){
    peso = pes;
}

void CCamino::Salvar(fstream& out){
    out<<GetCLSID()<<endl;
    origen->Salvar(out);
    destino->Salvar(out);
    out<<peso<<endl;
}

void CCamino::Cargar(fstream& in ){
    int CLSID;

    in>>CLSID;
    origen->Cargar(in);
    in>>CLSID;
    destino->Cargar(in);
    in>>peso;
}


int CCamino::GetCLSID(){
    return CLSID_CAMINO;
}

CPueblo* CCamino::getDestino()
{
    return destino;
}


