#include "tablaHashCaminos.h"
#include <iostream>

using namespace std;

TablaHashCaminos::TablaHashCaminos(){
    longArreglo = 41;
    for (int i(0); i < longArreglo; i++){
        Arreglo[i] = new CLista;
    }
}

///FUNCION PROPIA
int TablaHashCaminos::FnHash(string nombreO, string estadoO, string nombreD, string estadoD)
{
    //Recibe el nombre del pueblo y el estado
    unsigned long valorHash=0;
    int seed = 131;

    //Funcion de complejidad constante:
    //ValorHash almacena el valor calculado con la semilla o pivote mas el valor ascii de cada letra

    valorHash += (valorHash * seed) + (int)nombreO[0]; //M = 77
    valorHash += (valorHash * seed) + (int)nombreO[1]; //a = 97

    valorHash += (valorHash * seed) + (int)estadoO[0]; //J = 74
    valorHash += (valorHash * seed) + (int)estadoO[1]; //a = 97

    valorHash += (int)nombreD[0];
    valorHash += (int)nombreD[1];
    valorHash += (int)estadoD[0];
    valorHash += (int)estadoD[1];


    //Se obtiene el modulo para entrar en el rango de elementos del arreglo
    int val = valorHash % longArreglo;

	return  val;
}

/*
int TablaHashCaminos::FnHash(string clave, string estado)
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
int TablaHashCaminos::FnHash(string key, string estado)
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
int TablaHashCaminos::FnHash(string clave, string estado)
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
int TablaHashCaminos::FnHash(string clave, string estado)
{
    unsigned long hashv = 0;
    int c;

    for(int i = 0; i < clave.size(); i++)
        hashv = clave[i] + (hashv << 6) + (hashv << 16) - hashv;

    return hashv % longArreglo;
}
*/


void TablaHashCaminos::Insertar(CCamino* elemento)
{
    int pos = FnHash(elemento->origen->nombre,
                     elemento->origen->estado,
                     elemento->destino->nombre,
                     elemento->destino->estado );

    CLista* lista = new CLista;

    lista = Arreglo[pos];

    lista->insertarAlFinal(elemento);

}

CCamino* TablaHashCaminos::Buscar(string nombre, string estado, string nombreD, string estadoD)
{
    int pos = FnHash(nombre, estado, nombreD, estadoD);

    CLista* lista = new CLista();

    lista = Arreglo[pos];

    return lista->buscarCamino(nombre, estado, nombreD, estadoD);

}

CCamino* TablaHashCaminos::Eliminar(string nombre, string estado, string nombreD, string estadoD)
{
    int pos = FnHash(nombre, estado, nombreD, estadoD);

    CLista* lista = new CLista();

    lista = Arreglo[pos];

    return lista->eliminarCamino(nombre, estado, nombreD, estadoD);
}

void TablaHashCaminos::Imprimir()
{
    for(int i(0); i< longArreglo; i++){
        if(!Arreglo[i]->isEmpty()){
            cout<<"Posicion Arreglo:  "<<i<<endl;
            Arreglo[i]->ImprimirCamino();
        }
    }
}


void TablaHashCaminos::Salvar(fstream& out)
{
    out<<GetCLSID()<<endl;
    for(int i(0); i < longArreglo; i++){
        if(!Arreglo[i]->isEmpty()){
            out<<i<<endl;
            Arreglo[i]->SalvarCamino(out);
        }
    }
}

void TablaHashCaminos::Cargar(fstream& in)
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

int TablaHashCaminos::GetCLSID()
{
    return CLSID_TABLACAMINOS;
}

