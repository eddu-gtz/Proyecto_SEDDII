#include "clista.h"
#include <iostream>

using namespace std;

CLista::CLista()
{
     //Enlazar los nodos cabecera
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::~CLista()
{
    //Eliminar todos los nodos de la lista
    while(Inicio.pSig != &Final){
         Inicio.eliminarAdelante();
    }
}

void CLista::insertarAlInicio(CPueblo* ndato)
{
    Inicio.insertarAdelante(ndato);
}

void CLista::insertarAlFinal(CPueblo* ndato)
{
    //Regresar uno para poder insertar al final
    Final.pAnt->insertarAdelante(ndato);
}

void CLista::insertarAlFinal(CCamino* ndato)
{
    //Regresar uno para poder insertar al final
    Final.pAnt->insertarAdelante(ndato);
}

CPueblo* CLista::eliminarAlInicio()
{
    return Inicio.eliminarAdelante();
}

CPueblo* CLista::eliminarAlFinal()
{
    //Regresar dos posiciones para poder eliminar al final
    return Final.pAnt->pAnt->eliminarAdelante();
}

CCamino* CLista::eliminarAlFinalCamino()
{
    //Regresar dos posiciones para poder eliminar al final
    return Final.pAnt->pAnt->eliminarAdelanteCamino();
}

int CLista::Size()
{
    //Contar el numero de nodos que contiene la lista
    int numNodos(0);

    CNodo* aux = Inicio.pSig;

    while( aux != &Final){
        numNodos++;
        aux = aux->pSig;
    }

    return numNodos;
}

bool CLista::isEmpty()
{
    ///Si regresa verdadero es porque esta vacia
    return Inicio.pSig == &Final;
}

bool CLista::isFull()
{
    CNodo* pNodo = new (CNodo);
    ///Si regresa nullptr es porque se acabo la memoria
    return pNodo == nullptr;
}

CIterador& CLista::Begin()
{
    //Retorna por referencia el nodo que se encuentra al inicio de la lista
    m_ItBegin.SetNodo(Inicio.pSig);
    return m_ItBegin;
}

CIterador& CLista::End()
{
    //Retorna por referencia el nodo que se encuentra al final de la lista
    m_ItEnd.SetNodo(&Final);
    return m_ItEnd;
}

void CLista::Imprimir()
{
    CIterador it;
    for(it = Begin(); it != End(); it++){
        it.pActual->NodoPueblo->Imprimir();
        cout<<endl;
    }
}

void CLista::ImprimirCamino()
{
    CIterador it;
    for(it = Begin(); it != End(); it++){
        it.pActual->CaminoPueblo->Imprimir();
        cout<<endl<<endl;
    }
}


CPueblo* CLista::buscarPueblo(string buscado, string estado){

    CIterador it;

    if(!isEmpty())
    {
        for(it = Begin(); it != End(); it++)
        {

            if(it.pActual->NodoPueblo->nombre == buscado && it.pActual->NodoPueblo->estado == estado)
            {
                return  it.pActual->NodoPueblo;
            }
        }
    }
    return 0;
}

CPueblo* CLista::eliminarPueblo(string buscado, string estado){

    CIterador it;

    if(!isEmpty())
    {
        for(it = Begin(); it != End(); it++)
        {
            if(it.pActual->NodoPueblo->nombre == buscado && it.pActual->NodoPueblo->estado == estado)
            {
                return  it.EliminarSiguiente();
            }
        }
    }
    return 0;
}

CCamino* CLista::buscarCamino(string nombre, string estado, string nombreD, string estadoD){

    CIterador it;

    if(!isEmpty())
    {
        for(it = Begin(); it != End(); it++)
        {
            if((it.pActual->CaminoPueblo->origen->nombre == nombre) && (it.pActual->CaminoPueblo->origen->estado == estado))
            {
                if((it.pActual->CaminoPueblo->destino->nombre == nombreD) && (it.pActual->CaminoPueblo->destino->estado == estadoD))
                {
                    return  it.pActual->CaminoPueblo;
                }
            }
        }
    }
    return 0;
}

CCamino* CLista::eliminarCamino(string nombre, string estado, string nombreD, string estadoD){

    CIterador it;

    if(!isEmpty())
    {
        for(it = Begin(); it != End(); it++)
        {
            if((it.pActual->CaminoPueblo->origen->nombre == nombre) && (it.pActual->CaminoPueblo->origen->estado == estado))
            {
                if((it.pActual->CaminoPueblo->destino->nombre == nombreD) && (it.pActual->CaminoPueblo->destino->estado == estadoD))
                {
                    return  it.EliminarSiguienteCamino();
                }
            }
        }
    }
    return 0;
}

void CLista::Salvar(fstream& out)
{
    CIterador it;

    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    for(it = Begin(); it != End(); it++){
        it.pActual->NodoPueblo->Salvar(out);
    }
}

void CLista::SalvarCamino(fstream& out)
{
    CIterador it;

    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    for(it = Begin(); it != End(); it++){
        it.pActual->CaminoPueblo->Salvar(out);
    }
}

void CLista::Cargar(fstream& in)
{
    int tamanio(0);
    int CLSID(0);

    in>>tamanio;

    for(int i=0; i<tamanio; i++){

        in>>CLSID;
        switch(CLSID){
            case CLSID_PUEBLO:{
                CPueblo* pObj = new CPueblo();
                pObj->Cargar(in);
                insertarAlFinal(pObj);
            }
                break;

            case CLSID_CAMINO:{
                CCamino* pObj2 = new CCamino();
                pObj2->Cargar(in);
                insertarAlFinal(pObj2);
            }
                break;

            default:
                cout<<" Hubo un error al cargar | Lista"<<endl;
                break;
        }
    }
}

int CLista::GetCLSID()
{
    return CLSID_LISTA;
}

