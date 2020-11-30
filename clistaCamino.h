#ifndef CLISTACAMINO_H_INCLUDED
#define CLISTACAMINO_H_INCLUDED

#include "cnodo.h"
#include "citerador.h"
#include "cserializable.h"
#include "cCamino.h"

#include "tablahash.h"

#define CLSID_LISTA 500

class CListaCamino: public CSerializable{
private:
    CNodo Inicio;
    CNodo Final;

    CIterador m_ItBegin;
    CIterador m_ItEnd;

public:

    CListaCamino();
    ~CListaCamino();

    void insertarAlFinal(CCamino* );
    CCamino* eliminarAlFinalCamino();

    int Size();
    bool isEmpty();
    bool isFull();

    void ImprimirCamino();
    void ImprimirTodo();

    CIterador& Begin();
    CIterador& End();

    CListaCamino* buscarOrigen(std::string, std::string);

    CCamino* buscarCamino(std::string, std::string, std::string, std::string);
    CCamino* eliminarCamino(std::string, std::string, std::string, std::string);

    virtual void Salvar(fstream& );
    virtual void Cargar(fstream& );
    void CargarCamino(fstream& , TablaHash& );
    virtual int GetCLSID();
};

#endif // CLISTACAMINO_H_INCLUDED
