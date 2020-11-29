#ifndef CLISTA_H_INCLUDED
#define CLISTA_H_INCLUDED

#include "cnodo.h"
#include "citerador.h"
#include "cserializable.h"
#include "cCamino.h"
#include "CPueblo.h"


#define CLSID_LISTA 500

class CLista: public CSerializable{
private:
    CNodo Inicio;
    CNodo Final;

    CIterador m_ItBegin;
    CIterador m_ItEnd;

public:

    CLista();
    ~CLista();

    void insertarAlInicio(CPueblo* );
    void insertarAlFinal(CPueblo* );
    void insertarAlFinal(CCamino* );
    CPueblo* eliminarAlInicio();
    CPueblo* eliminarAlFinal();
    CCamino* eliminarAlFinalCamino();

    int Size();
    bool isEmpty();
    bool isFull();

    void Imprimir();
    void ImprimirCamino();
    void ImprimirTodo();

    CIterador& Begin();
    CIterador& End();

    CPueblo* buscarPueblo(std::string, std::string);
    CPueblo* eliminarPueblo(std::string, std::string);

    CCamino* buscarCamino(std::string, std::string, std::string, std::string);
    CCamino* eliminarCamino(std::string, std::string, std::string, std::string);

    virtual void Salvar(fstream& );
    virtual void SalvarCamino(fstream& );
    virtual void Cargar(fstream& );
    //void CargarCamino(fstream& , TablaHashCaminos&);
    virtual int GetCLSID();
};

#endif // CLISTA_H_INCLUDED
