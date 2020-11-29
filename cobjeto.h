#ifndef COBJETO_H_INCLUDED
#define COBJETO_H_INCLUDED

#include <iostream>
#include <string>
#include "cserializable.h"
#include "CPueblo.h"

///OBJETO
class CObjeto: public CSerializable{
    public:
    virtual void Imprimir() = 0;

    CObjeto* objectFactory(int );
};

#endif // COBJETO_H_INCLUDED
