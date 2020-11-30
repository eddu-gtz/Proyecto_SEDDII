#ifndef TABLAHASH_H_INCLUDED
#define TABLAHASH_H_INCLUDED

#include "clista.h"
#include "cserializable.h"
#include "CPueblo.h"
#include <string>

#define CLSID_TABLA 1000

class TablaHash : public CSerializable{
private:
    int longArreglo;
    CLista* Arreglo[17];
    int FnHash(std::string, std::string);

public:
    TablaHash();

    //int FnHash(std::string);
    void Insertar(CPueblo* elemento);
    CPueblo* Buscar(std::string, std::string);
    CPueblo* Eliminar(std::string, std::string);

    void Imprimir();

    virtual void Salvar(fstream& );
    virtual void Cargar(fstream& );
    virtual int GetCLSID();

};

#endif // TABLAHASH_H_INCLUDED
