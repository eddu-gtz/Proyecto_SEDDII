#include "citerador.h"

void CIterador::SetNodo(CNodo* pNodo)
{
    pActual = pNodo;
}

void CIterador::InsertarAdelante(CPueblo* cont)
{
    pActual->insertarAdelante(cont);
}

CPueblo* CIterador::EliminarSiguiente()
{
    pActual = pActual->pAnt;
    return pActual->eliminarAdelante();
}

CCamino* CIterador::EliminarSiguienteCamino()
{
    pActual = pActual->pAnt;
    return pActual->eliminarAdelanteCamino();
}

///OPERADORES
void CIterador::operator=(CIterador& otro)
{
    pActual = otro.pActual;
}

bool CIterador::operator==(CIterador& otro)
{
    return pActual == otro.pActual;
}

bool CIterador::operator!=(CIterador& otro)
{
    return pActual != otro.pActual;
}

///Operador Infijo
void CIterador::operator++()
{
    pActual = pActual->pSig;
}

///Operador Infijo
void CIterador::operator--()
{
    pActual = pActual->pAnt;
}

CPueblo*& CIterador::operator*()
{
    return pActual->NodoPueblo;
}

///Operador Posfijo
void CIterador::operator++(int)
{
    pActual = pActual->pSig;
}

///Operador Posfijo
void CIterador::operator--(int)
{
    pActual = pActual->pAnt;
}
