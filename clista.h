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

    CPueblo* eliminarAlInicio();
    CPueblo* eliminarAlFinal();

    int Size();
    bool isEmpty();
    bool isFull();

    void Imprimir();
    void ImprimirTodo();

    CIterador& Begin();
    CIterador& End();

    CPueblo* buscarPueblo(std::string, std::string);
    CPueblo* eliminarPueblo(std::string, std::string);

    virtual void Salvar(fstream& );
    virtual void Cargar(fstream& );
    virtual int GetCLSID();
};

#endif // CLISTA_H_INCLUDED
