#ifndef CLISTACAMINO_H_INCLUDED
#define CLISTACAMINO_H_INCLUDED

#include "cnodo.h"
#include "citerador.h"
#include "cserializable.h"
#include "cCamino.h"


#include "tablaHashCaminos.h"

#define CLSID_LISTA 500

class CListaCamino: public CSerializable{
private:
    CNodo Inicio;
    CNodo Final;

    CIterador m_ItBegin;
    CIterador m_ItEnd;

public:


    CLista();
    ~CLista();

    void insertarAlFinal(CCamino* );
    CCamino* eliminarAlFinalCamino();

    int Size();
    bool isEmpty();
    bool isFull();

    void Imprimir();
    void ImprimirCamino();
    void ImprimirTodo();

    CIterador& Begin();
    CIterador& End();


    CCamino* buscarCamino(std::string, std::string, std::string, std::string);
    CCamino* eliminarCamino(std::string, std::string, std::string, std::string);

    virtual void Salvar(fstream& );
    virtual void SalvarCamino(fstream& );
    virtual void Cargar(fstream& );
    void CargarCamino(fstream& , TablaHashCaminos&);
    virtual int GetCLSID();
};

#endif // CLISTACAMINO_H_INCLUDED
