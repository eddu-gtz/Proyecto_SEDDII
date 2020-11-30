#ifndef CPUEBLO_H_INCLUDED
#define CPUEBLO_H_INCLUDED

#include <string>
#include "cserializable.h"

#define CLSID_PUEBLO 100


class CPueblo: public CSerializable {
private:
    std::string nombre;
    std::string estado;
    int satisfaccion;
    int costo;

    friend class TablaHash;
    friend class TablaHashCaminos;
    friend class CCamino;
    friend class CLista;
    friend class CListaCamino;

public:
    CPueblo();
    ~CPueblo();
    CPueblo(std::string, std::string, int, int);
    void Imprimir();

    void Salvar(fstream& );
    void Cargar(fstream& );
    int GetCLSID( );

    void setNombre(std::string);
    void setEstado(std::string);
    void setSatisfaccion(int);
    void setCosto(int);

    std::string getNombre();
    std::string getEstado();

};

#endif // CPUEBLO_H_INCLUDED
