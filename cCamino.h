#ifndef CCAMINO_H_INCLUDED
#define CCAMINO_H_INCLUDED

#include "CPueblo.h"
#include "cserializable.h"

#define CLSID_CAMINO 200

class CCamino: public CSerializable{
private:
    CPueblo* origen;
    CPueblo* destino;
    int peso;

    friend class TablaHashCaminos;
    friend class CLista;

public:
    CCamino();
    ~CCamino();
    CCamino(CPueblo* , CPueblo* , int);
    void Imprimir();

    void Salvar(fstream& );
    void Cargar(fstream& );
    int GetCLSID( );

};

#endif // CCAMINO_H_INCLUDED
