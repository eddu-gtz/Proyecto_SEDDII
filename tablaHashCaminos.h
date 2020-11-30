#ifndef TABLAHASHCAMINOS_H_INCLUDED
#define TABLAHASHCAMINOS_H_INCLUDED

#include "clistaCamino.h"
#include "cserializable.h"
#include "cCamino.h"
#include <string>

#include "tablahash.h"


#define CLSID_TABLACAMINOS 2000

class TablaHashCaminos : public CSerializable{
private:
    int longArreglo;
    CListaCamino* Arreglo[41];
    //int FnHash(std::string, std::string, std::string, std::string);
    int FnHash(std::string, std::string);

public:
    TablaHashCaminos();

    void Insertar(CCamino* elemento);
    CListaCamino* BuscarOrigen(std::string, std::string);
    //CCamino* Eliminar(std::string, std::string, std::string, std::string);

    CCamino* Buscar(std::string, std::string, std::string, std::string);
    CCamino* Eliminar(std::string, std::string, std::string, std::string);

    void Imprimir();

    virtual void Salvar(fstream& );
    virtual void Cargar(fstream& );
    void CargarCamino(fstream& , TablaHash&);
    virtual int GetCLSID();

};


#endif // TABLAHASHCAMINOS_H_INCLUDED
