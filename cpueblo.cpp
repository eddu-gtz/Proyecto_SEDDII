#include  "CPueblo.h"
#include <iostream>

using namespace std;

CPueblo::CPueblo()
{
    nombre = "";
    costo = 0;
    satisfaccion = 0;
}

CPueblo::~CPueblo()
{
}

CPueblo::CPueblo( std::string dato1, std::string dato2, int dato3, int dato4)
    : nombre(dato1), estado(dato2), satisfaccion(dato3), costo(dato4){ }


void CPueblo::Imprimir()
{
    cout<<"\t<=   "<<" "<<nombre<<", "<<estado<<"   =>\n";
    cout<<"\t   Satisfaccion: "<<satisfaccion<<"\t   Costo: "<<costo<<endl<<endl<<endl;
}

void CPueblo::Salvar(fstream& out){
    out<<GetCLSID()<<endl;
    out<<nombre<<endl;
    out<<estado<<endl;
    out<<satisfaccion<<endl;
    out<<costo<<endl;

}

void CPueblo::Cargar(fstream& in){
    string nom;
    getline(in, nom);
    getline(in, nombre);
    getline(in, estado);
    in>>satisfaccion;
    in>>costo;
}

int CPueblo::GetCLSID(){
    return CLSID_PUEBLO;
}

void CPueblo::setNombre(string nom){
    nombre = nom;
}

void CPueblo::setEstado(string est){
    estado = est;
}

void CPueblo::setSatisfaccion(int sas){
    satisfaccion = sas;
}

void CPueblo::setCosto(int cos){
    costo = cos;
}

string CPueblo::getNombre(){
    return nombre;
}

string CPueblo::getEstado(){
    return estado;
}
