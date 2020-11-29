#ifndef CSERIALIZABLE_H_INCLUDED
#define CSERIALIZABLE_H_INCLUDED

#include <fstream>

using namespace std;

class CSerializable{
    public:
    virtual void Salvar(fstream& out) = 0;
    virtual void Cargar(fstream& in) = 0;
    virtual int GetCLSID() = 0;
};

#endif // CSERIALIZABLE_H_INCLUDED
