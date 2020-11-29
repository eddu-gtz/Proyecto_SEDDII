#include "cnodo.h"

void CNodo::insertarAdelante(CPueblo* dat)
{
    //Crea un nuevo nodo
    CNodo* pNuevo = new (CNodo);
    //se asigna el dato al nodo
    pNuevo->NodoPueblo = dat;
    //El nuevo nodo en su campo anterior apunta a this
    pNuevo->pAnt = this;
    //Se en laza el puntero siguiente
    pNuevo->pSig = this->pSig;
    //Se enlazan los punteros de los nodos existentes al nuevo nodo
    pNuevo->pSig->pAnt = pNuevo;

    this->pSig = pNuevo;
}

CPueblo* CNodo::eliminarAdelante()
{
    CPueblo* dat;
    //Se crea un putero auxiliar para posteriormente eliminar el nodo
    CNodo* aux = this->pSig;
    //Se quita el enlace al nodo a eliminar
    aux->pSig->pAnt = this;

    this->pSig = aux->pSig;
    //Se recupera el dato
    dat = aux->NodoPueblo;
    //Se elimina el nodo
    delete aux;

    //Retorna el dato
    return dat;
}

void CNodo::insertarAdelante(CCamino* dat)
{
    //Crea un nuevo nodo
    CNodo* pNuevo = new (CNodo);
    //se asigna el dato al nodo
    pNuevo->CaminoPueblo = dat;
    //El nuevo nodo en su campo anterior apunta a this
    pNuevo->pAnt = this;
    //Se en laza el puntero siguiente
    pNuevo->pSig = this->pSig;
    //Se enlazan los punteros de los nodos existentes al nuevo nodo
    pNuevo->pSig->pAnt = pNuevo;

    this->pSig = pNuevo;
}

CCamino* CNodo::eliminarAdelanteCamino()
{
    CCamino* dat;
    //Se crea un putero auxiliar para posteriormente eliminar el nodo
    CNodo* aux = this->pSig;
    //Se quita el enlace al nodo a eliminar
    aux->pSig->pAnt = this;

    this->pSig = aux->pSig;
    //Se recupera el dato
    dat = aux->CaminoPueblo;
    //Se elimina el nodo
    delete aux;

    //Retorna el dato
    return dat;
}
