#include "clistaCamino.h"
#include <iostream>

using namespace std;

CListaCamino::CListaCamino()
{
     //Enlazar los nodos cabecera
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CListaCamino::~CListaCamino()
{
    //Eliminar todos los nodos de la lista
    while(Inicio.pSig != &Final){
         Inicio.eliminarAdelante();
    }
}

void CListaCamino::insertarAlFinal(CCamino* ndato)
{
    //Regresar uno para poder insertar al final
    Final.pAnt->insertarAdelante(ndato);
}

CCamino* CListaCamino::eliminarAlFinalCamino()
{
    //Regresar dos posiciones para poder eliminar al final
    return Final.pAnt->pAnt->eliminarAdelanteCamino();
}

int CListaCamino::Size()
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

bool CListaCamino::isEmpty()
{
    ///Si regresa verdadero es porque esta vacia
    return Inicio.pSig == &Final;
}

bool CListaCamino::isFull()
{
    CNodo* pNodo = new (CNodo);
    ///Si regresa nullptr es porque se acabo la memoria
    return pNodo == nullptr;
}

CIterador& CListaCamino::Begin()
{
    //Retorna por referencia el nodo que se encuentra al inicio de la lista
    m_ItBegin.SetNodo(Inicio.pSig);
    return m_ItBegin;
}

CIterador& CListaCamino::End()
{
    //Retorna por referencia el nodo que se encuentra al final de la lista
    m_ItEnd.SetNodo(&Final);
    return m_ItEnd;
}

void CListaCamino::ImprimirCamino()
{
    CIterador it;
    for(it = Begin(); it != End(); it++){
        it.pActual->CaminoPueblo->Imprimir();
        cout<<endl<<endl;
    }
}

CListaCamino* CListaCamino::buscarOrigen(string nombre, string estado){
    CIterador it;

    if(!isEmpty())
    {
        CListaCamino* lista = new CListaCamino;

        for(it = Begin(); it != End(); it++)
        {
            if((it.pActual->CaminoPueblo->origen->nombre == nombre) && (it.pActual->CaminoPueblo->origen->estado == estado))
            {
                /*if((it.pActual->CaminoPueblo->destino->nombre == nombreD) && (it.pActual->CaminoPueblo->destino->estado == estadoD))
                {
                    return  it.pActual->CaminoPueblo;
                }*/
                lista->insertarAlFinal(*it);
            }
        }
        return lista;
    }
    return 0;
}

CCamino* CListaCamino::buscarCamino(string nombre, string estado, string nombreD, string estadoD){

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

CCamino* CListaCamino::eliminarCamino(string nombre, string estado, string nombreD, string estadoD){

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

void CListaCamino::Salvar(fstream& out)
{
    CIterador it;

    out<<GetCLSID()<<endl;
    out<<Size()<<endl;
    for(it = Begin(); it != End(); it++){
        it.pActual->CaminoPueblo->Salvar(out);
    }
}

void CListaCamino::Cargar(fstream& in)
{
    int tamanio(0);
    int CLSID(0);

    in>>tamanio;

    for(int i=0; i<tamanio; i++){

        in>>CLSID;
        switch(CLSID){
            case CLSID_PUEBLO:{
                /*CPueblo* pObj = new CPueblo();
                pObj->Cargar(in);
                insertarAlFinal(pObj);*/
                break;
            }

            case CLSID_CAMINO:{
                CCamino* pObj2 = new CCamino();
                pObj2->Cargar(in);
                insertarAlFinal(pObj2);
                break;
            }

            default:
                cout<<" Hubo un error al cargar | Lista"<<endl;
                break;
        }
    }
}

void CListaCamino::CargarCamino(fstream& in, TablaHash& tabla)
{
    int tamanio(0);
    int CLSID(0);

    in>>tamanio;

    for(int i=0; i<tamanio; i++){

        in>>CLSID;
        switch(CLSID){
            case CLSID_PUEBLO:{
                cout<<" Hubo un error al cargar | Lista"<<endl;
                break;
            }

            case CLSID_CAMINO:{
                string nom, nombre, estado;
                int CLSID2;
                int satisfaccion;
                int costo;
                int peso;

                in>>CLSID2;
                getline(in, nom);
                getline(in, nombre);
                getline(in, estado);
                in>>satisfaccion;
                in>>costo;

                CPueblo* pueblito1 = new CPueblo;
                pueblito1 = tabla.Buscar(nombre, estado);

                in>>CLSID2;
                getline(in, nom);
                getline(in, nombre);
                getline(in, estado);
                in>>satisfaccion;
                in>>costo;

                CPueblo* pueblito2 = new CPueblo;
                pueblito2 = tabla.Buscar(nombre, estado);

                in>>peso;

                CCamino* pObj2 = new CCamino(pueblito1, pueblito2, peso);

                insertarAlFinal(pObj2);
                break;
            }

            default:
                cout<<" Hubo un error al cargar | Lista"<<endl;
                break;
        }
    }
}

int CListaCamino::GetCLSID()
{
    return CLSID_LISTA;
}

