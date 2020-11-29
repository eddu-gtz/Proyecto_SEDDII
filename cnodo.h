#ifndef CNODO_H_INCLUDED
#define CNODO_H_INCLUDED

#include "cPueblo.h"
#include "cCamino.h"

class CNodo{
private:
    friend class CLista;
    friend class CIterador;

    CNodo* pSig = nullptr;
    CNodo* pAnt = nullptr;
    CPueblo* NodoPueblo;
    CCamino* CaminoPueblo;


    void insertarAdelante(CPueblo* );
    void insertarAdelante(CCamino* );
    CPueblo* eliminarAdelante();
    CCamino* eliminarAdelanteCamino();
};

#endif // CNODO_H_INCLUDED
