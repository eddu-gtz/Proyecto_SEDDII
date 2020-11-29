#include "cobjeto.h"
#include "clista.h"
#include "tablahash.h"
#include "tablaHashCaminos.h"
#include "CPueblo.h"
#include "cCamino.h"

CObjeto* CObjeto::objectFactory(int CLSID)
{
    CObjeto* pObj = 0;

    switch(CLSID){

        case CLSID_LISTA:
            pObj = new CLista();
            break;

        case CLSID_TABLA:
            pObj = new TablaHash();
            break;

        case CLSID_TABLACAMINOS:
            pObj = new TablaHashCaminos();
            break;

        case CLSID_PUEBLO:
            //pObj = new CPueblo();
            break;

        case CLSID_CAMINO:
            //pObj = new CCamino();
            break;

        default:
            pObj = 0;

    }

    return pObj;
}
