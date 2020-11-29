#ifndef CITERADOR_H_INCLUDED
#define CITERADOR_H_INCLUDED

#include "cnodo.h"

class CIterador{
private:
    CNodo* pActual;
    void SetNodo(CNodo* pNodo);
public:

    friend class CLista;

    void InsertarAdelante(CPueblo* );
    CPueblo* EliminarSiguiente();
    CCamino* EliminarSiguienteCamino();

    ///Sobrecarga de operadores
    void operator = (CIterador& otro);
    bool operator == (CIterador& otro);
    bool operator != (CIterador& otro);
    void operator ++ ();
    void operator -- ();
    CPueblo*& operator * ();

    void operator ++(int);
    void operator --(int);

};

#endif // CITERADOR_H_INCLUDED
