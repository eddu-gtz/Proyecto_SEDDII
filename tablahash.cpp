#include "tablahash.h"
#include <iostream>

using namespace std;

TablaHash::TablaHash(){
    longArreglo = 17;
    for (int i(0); i < longArreglo; i++){
        Arreglo[i] = new CLista;
    }
}

///FUNCION PROPIA
int TablaHash::FnHash(string nombre, string estado)
{
    //Recibe el nombre del pueblo y el estado
    unsigned long valorHash=0;
    int seed = 131;

    //Funcion de complejidad constante:
    //ValorHash almacena el valor calculado con la semilla o pivote mas el valor ascii de cada letra

    valorHash += (valorHash * seed) + (int)nombre[0]; //M = 77
    valorHash += (valorHash * seed) + (int)nombre[1]; //a = 97

    valorHash += (valorHash * seed) + (int)estado[0]; //J = 74
    valorHash += (valorHash * seed) + (int)estado[1]; //a = 97


    //Se obtiene el modulo para entrar en el rango de elementos del arreglo
    int val = valorHash % longArreglo;

	return  val;
}

/*
int TablaHash::FnHash(string clave, string estado)
{
    long int valorHash=0;

	for(int i=0; i<clave.size(); i++)
    {
        valorHash += (int)clave[i];
    }

	return  valorHash % longArreglo;
}*/

/*
///FUNCION djb2
int TablaHash::FnHash(string key, string estado)
    {

        unsigned long hashv = 5381;

        for(int i=0; i<4; i++)
        {
            hashv = ((hashv << 5) + hashv) + (int)key[i]; // hash * 33 + c
        }

        return hashv%longArreglo;
    }
*/
/*
///FUNCION CON SEMILLA O PIVOTE
int TablaHash::FnHash(string clave, string estado)
{
    int seed = 131;
    unsigned long hashv = 0;

    for(int i = 0; i < clave.size(); i++)
    {
        hashv = (hashv * seed) + clave[i];
    }
    return hashv % longArreglo;
}
*/
/*
///FUNCION sdbm
int TablaHash::FnHash(string clave, string estado)
{
    unsigned long hashv = 0;
    int c;

    for(int i = 0; i < clave.size(); i++)
        hashv = clave[i] + (hashv << 6) + (hashv << 16) - hashv;

    return hashv % longArreglo;
}
*/


void TablaHash::Insertar(CPueblo* elemento)
{
    int pos = FnHash(elemento->nombre, elemento->estado);

    CLista* lista = new CLista;

    lista = Arreglo[pos];

    lista->insertarAlFinal(elemento);

}

CPueblo* TablaHash::Buscar(string nombre, string estado)
{
    int pos = FnHash(nombre, estado);

    CLista* lista = new CLista();

    lista = Arreglo[pos];

    return lista->buscarPueblo(nombre, estado);

}

CPueblo* TablaHash::Eliminar(string nombre, string estado)
{
    int pos = FnHash(nombre, estado);

    CLista* lista = new CLista();

    lista = Arreglo[pos];

    return lista->eliminarPueblo(nombre, estado);
}

void TablaHash::Imprimir()
{
    for(int i(0); i< longArreglo; i++){
        if(!Arreglo[i]->isEmpty()){
            cout<<"Posicion Arreglo:  "<<i<<endl;
            Arreglo[i]->Imprimir();
        }
    }
}


void TablaHash::Salvar(fstream& out)
{

    out<<GetCLSID()<<endl;
    for(int i(0); i < longArreglo; i++){
        if(!Arreglo[i]->isEmpty()){
            out<<i<<endl;
            Arreglo[i]->Salvar(out);
        }

    }
}

void TablaHash::Cargar(fstream& in)
{
    int CLSID(0);
    int pos(0);

    while(!in.eof()){
        in>>pos;
        in>>CLSID;

        if(in.eof())
            break;

        CLista* pLista = new CLista();

        if(CLSID != CLSID_LISTA){
            cout<<" No se como cargar esto"<<endl;
            break;
        }
        else{
            pLista->Cargar(in);

            Arreglo[pos] = pLista;
        }
    }
}


void TablaHash::CargarCamino(fstream& in, TablaHashCaminos& )
{
    int CLSID(0);
    int pos(0);

    while(!in.eof()){
        in>>pos;
        in>>CLSID;

        if(in.eof())
            break;

        CLista* pLista = new CLista();

        if(CLSID != CLSID_LISTA){
            cout<<" No se como cargar esto"<<endl;
            break;
        }
        else{
            pLista->Cargar(in);

            Arreglo[pos] = pLista;
        }
    }
}

int TablaHash::GetCLSID()
{
    return CLSID_TABLA;
}

