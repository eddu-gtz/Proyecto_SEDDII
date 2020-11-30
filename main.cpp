#include <iostream>
#include <string>

#include "cnodo.h"
#include "cCamino.h"
#include "tablahash.h"
#include "tablaHashCaminos.h"
#include "clistaCamino.h"
#include "citerador.h"

using namespace std;



///MENU
int main()
{
    int opc, opc2, opc3;
    int satisfaccion, costo, peso;
    string nombre, estado;

    TablaHash HashPueblos;
    TablaHashCaminos HashCaminos;
    CIterador it;

    /*
    CPueblo* pueblito0 = new CPueblo("Mazamitla", "Jalisco",8,6);
    CPueblo* pueblito1 = new CPueblo("Tequila", "Jalisco",7,6);
    CPueblo* pueblito2 = new CPueblo("Tapalpa", "Jalisco",6,5);
    CPueblo* pueblito3 = new CPueblo("Lagos de Moreno", "Jalisco",6,4);
    CPueblo* pueblito4 = new CPueblo("Valladolid", "Yucatan",7,7);
    CPueblo* pueblito5 = new CPueblo("Mascota", "Jalisco",5,5);
    CPueblo* pueblito6 = new CPueblo("Talpa de Allende", "Jalisco",6,7);
    CPueblo* pueblito7 = new CPueblo("Dolores Hidalgo", "Guanajuato",7,7);
    CPueblo* pueblito8 = new CPueblo("Jala", "Nayarit",5,3);
    CPueblo* pueblito9 = new CPueblo("San Joaquin", "Queretaro",4,5);
    CPueblo* pueblito10 = new CPueblo("Palenque", "Chiapas",9,7);
    CPueblo* pueblito11 = new CPueblo("Patzcuaro", "Michoacan",8,5);
    CPueblo* pueblito12 = new CPueblo("Valle de Bravo", "Estado de Mexico",6,7);
    CPueblo* pueblito13 = new CPueblo("Mineral de Pozos", "Guanajuato",6,5);
    CPueblo* pueblito14 = new CPueblo("Loreto", "Baja California Sur",8,6);
    CPueblo* pueblito15 = new CPueblo("Papantla", "Veracruz",9,8);
    CPueblo* pueblito16 = new CPueblo("San Cristobal de las Casas", "Chiapas",8,7);
    CPueblo* pueblito17 = new CPueblo("San Pablo Villa de Mitla", "Oaxaca",4,3);
    CPueblo* pueblito18 = new CPueblo("Sombrerete", "Zacatecas",6,7);
    CPueblo* pueblito19 = new CPueblo("Taxco de Alarcon", "Guerrero",6,7);

    HashPueblos.Insertar(pueblito0);
    HashPueblos.Insertar(pueblito1);
    HashPueblos.Insertar(pueblito2);
    HashPueblos.Insertar(pueblito3);
    HashPueblos.Insertar(pueblito4);
    HashPueblos.Insertar(pueblito5);
    HashPueblos.Insertar(pueblito6);
    HashPueblos.Insertar(pueblito7);
    HashPueblos.Insertar(pueblito8);
    HashPueblos.Insertar(pueblito9);
    HashPueblos.Insertar(pueblito10);
    HashPueblos.Insertar(pueblito11);
    HashPueblos.Insertar(pueblito12);
    HashPueblos.Insertar(pueblito13);
    HashPueblos.Insertar(pueblito14);
    HashPueblos.Insertar(pueblito15);
    HashPueblos.Insertar(pueblito16);
    HashPueblos.Insertar(pueblito17);
    HashPueblos.Insertar(pueblito18);
    HashPueblos.Insertar(pueblito19);


    CCamino* camino1 = new CCamino(pueblito0, pueblito1, 36);
    CCamino* camino2 = new CCamino(pueblito0, pueblito2, 27);
    CCamino* camino3 = new CCamino(pueblito0, pueblito11, 79);

    CCamino* camino4 = new CCamino(pueblito1, pueblito0, 36);
    CCamino* camino5 = new CCamino(pueblito1, pueblito3, 47);

    CCamino* camino6 = new CCamino(pueblito2, pueblito0, 27);
    CCamino* camino7 = new CCamino(pueblito2, pueblito6, 31);
    CCamino* camino8 = new CCamino(pueblito2, pueblito5, 35);

    CCamino* camino9 = new CCamino(pueblito3, pueblito7, 38);
    CCamino* camino10 = new CCamino(pueblito3, pueblito1, 47);

    CCamino* camino11 = new CCamino(pueblito4, pueblito10, 195);

    CCamino* camino12 = new CCamino(pueblito5, pueblito2, 35);
    CCamino* camino13 = new CCamino(pueblito5, pueblito8, 42);

    CCamino* camino14 = new CCamino(pueblito6, pueblito2, 31);
    CCamino* camino15 = new CCamino(pueblito6, pueblito9, 196);

    CCamino* camino16 = new CCamino(pueblito7, pueblito3, 38);
    CCamino* camino17 = new CCamino(pueblito7, pueblito9, 53);
    CCamino* camino18 = new CCamino(pueblito7, pueblito13, 15);

    CCamino* camino19 = new CCamino(pueblito8, pueblito5, 42);
    CCamino* camino20 = new CCamino(pueblito8, pueblito18, 87);
    CCamino* camino21 = new CCamino(pueblito8, pueblito14, 115);

    CCamino* camino22 = new CCamino(pueblito9, pueblito7, 53);
    CCamino* camino23 = new CCamino(pueblito9, pueblito6, 196);
    CCamino* camino24 = new CCamino(pueblito9, pueblito15, 93);

    CCamino* camino25 = new CCamino(pueblito10, pueblito4, 195);
    CCamino* camino26 = new CCamino(pueblito10, pueblito16, 23);
    CCamino* camino27 = new CCamino(pueblito10, pueblito17, 103);

    CCamino* camino28 = new CCamino(pueblito11, pueblito0, 79);
    CCamino* camino29 = new CCamino(pueblito11, pueblito12, 82);
    CCamino* camino30 = new CCamino(pueblito11, pueblito17, 180);

    CCamino* camino31 = new CCamino(pueblito12, pueblito11, 82);
    CCamino* camino32 = new CCamino(pueblito12, pueblito19, 91);

    CCamino* camino33 = new CCamino(pueblito13, pueblito7, 15);

    CCamino* camino34 = new CCamino(pueblito14, pueblito8, 115);

    CCamino* camino35 = new CCamino(pueblito15, pueblito9, 93);

    CCamino* camino36 = new CCamino(pueblito16, pueblito10, 23);

    CCamino* camino37 = new CCamino(pueblito17, pueblito19, 103);
    CCamino* camino38 = new CCamino(pueblito17, pueblito11, 180);
    CCamino* camino39 = new CCamino(pueblito17, pueblito10, 103);

    CCamino* camino40 = new CCamino(pueblito18, pueblito8, 87);

    CCamino* camino41 = new CCamino(pueblito19, pueblito12, 91);
    CCamino* camino42 = new CCamino(pueblito19, pueblito17, 103);


    HashCaminos.Insertar(camino1);
    HashCaminos.Insertar(camino2);
    HashCaminos.Insertar(camino3);
    HashCaminos.Insertar(camino4);
    HashCaminos.Insertar(camino5);
    HashCaminos.Insertar(camino6);
    HashCaminos.Insertar(camino7);
    HashCaminos.Insertar(camino8);
    HashCaminos.Insertar(camino9);
    HashCaminos.Insertar(camino10);
    HashCaminos.Insertar(camino11);
    HashCaminos.Insertar(camino12);
    HashCaminos.Insertar(camino13);
    HashCaminos.Insertar(camino14);
    HashCaminos.Insertar(camino15);
    HashCaminos.Insertar(camino16);
    HashCaminos.Insertar(camino17);
    HashCaminos.Insertar(camino18);
    HashCaminos.Insertar(camino19);
    HashCaminos.Insertar(camino20);
    HashCaminos.Insertar(camino21);
    HashCaminos.Insertar(camino22);
    HashCaminos.Insertar(camino23);
    HashCaminos.Insertar(camino24);
    HashCaminos.Insertar(camino25);
    HashCaminos.Insertar(camino26);
    HashCaminos.Insertar(camino27);
    HashCaminos.Insertar(camino28);
    HashCaminos.Insertar(camino29);
    HashCaminos.Insertar(camino30);
    HashCaminos.Insertar(camino31);
    HashCaminos.Insertar(camino32);
    HashCaminos.Insertar(camino33);
    HashCaminos.Insertar(camino34);
    HashCaminos.Insertar(camino35);
    HashCaminos.Insertar(camino36);
    HashCaminos.Insertar(camino37);
    HashCaminos.Insertar(camino38);
    HashCaminos.Insertar(camino39);
    HashCaminos.Insertar(camino40);
    HashCaminos.Insertar(camino41);
    HashCaminos.Insertar(camino42);

*/

    fstream entrada2("pueblitos.txt", ios_base::in);
    ///Validar si se abrio correctamente
    if(entrada2.good())
    {
        int CLSID(0);
        entrada2>>CLSID;
        if(CLSID == HashPueblos.GetCLSID())
        {
            cout<<" Cargando"<<endl;
            HashPueblos.Cargar(entrada2);
        }
        else
            cout<<" No se como cargar esto"<<endl;
    }
    else
    {
        cout<<" El archivo no existe o no puede ser abierto"<<endl;
    }
    entrada2.close();


    fstream entrada("caminos.txt", ios_base::in);
    ///Validar si se abrio correctamente
    if(entrada.good())
    {
        int CLSID(0);
        entrada>>CLSID;
        if(CLSID == HashCaminos.GetCLSID())
        {
            cout<<" Cargando"<<endl;
            HashCaminos.CargarCamino(entrada, HashPueblos);
        }
        else
            cout<<" No se como cargar esto"<<endl;
    }
    else
    {
        cout<<" El archivo no existe o no puede ser abierto"<<endl;
    }
    entrada.close();



    do
    {

        ///Imprimir menu
        system("cls");
        cout<<" [1]  Opciones pueblos y caminos"<<endl;
        cout<<" [2]  Imprimir tabla"<<endl;
        //cout<<" [3]  Buscar pueblo"<<endl;
        //cout<<" [4]  Eliminar pueblo"<<endl;
        cout<<" [5]  Salir"<<endl;
        cout<<"\n Ingresa una opcion: ";
        cin>>opc;
        cin.sync();

        switch(opc)
        {
        ///NUEVO VERTICE
        case 1:
        {
            system("cls");
            cout<<" -------  PUEBLOS  -------"<<endl;
            cout<<" [1]  Agregar Pueblo"<<endl;
            cout<<" [2]  Buscar Pueblo"<<endl;
            cout<<" [3]  Actualizar Pueblo"<<endl;
            cout<<" [4]  Eliminar Pueblo"<<endl;
            cout<<" -------  CAMINOS  -------"<<endl;
            cout<<" [5]  Agregar Camino"<<endl;
            cout<<" [6]  Buscar Camino"<<endl;
            cout<<" [7]  Actaulizar Camino"<<endl;
            cout<<" [8]  Eliminar Camino"<<endl;

            cout<<endl<<"\n Ingresa una opcion: ";
            cin>>opc2;

            cout<<endl<<endl;
            cin.sync();

            switch(opc2)
            {
            ///INGRESAR PUEBLO
            case 1:
            {
                cout<<endl<<" Ingresa el nombre del pueblo magico: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el estado del pueblo magico: ";
                getline(cin, estado);
                cout<<endl<<" Ingresa el grado de satisfaccion que te brinda: ";
                cin>>satisfaccion;
                cout<<endl<<" Ingresa el costo por estar ahi: ";
                cin>>costo;


                if(HashPueblos.Buscar(nombre, estado))
                {
                    cout<<endl<<" El dato ya existe en la tabla y no puede ser ingresado nuevamente"<<endl;
                    system("pause");
                    break;
                }

                CPueblo* pueblito = new CPueblo(nombre,estado,satisfaccion,costo);

                HashPueblos.Insertar(pueblito);

                break;
            }

            ///BUSCAR PUEBLO
            case 2:
            {
                cout<<endl<<" Ingresa el Nombre del pueblo a buscar: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el Estado del pueblo: ";
                getline(cin, estado);

                CPueblo* pueblito = new CPueblo();

                pueblito = HashPueblos.Buscar(nombre, estado);

                if(pueblito)
                {
                    cout<<endl;
                    pueblito->Imprimir();
                }
                else
                    cout<<endl<<" El dato no existe en la tabla"<<endl;


                system("pause");
                break;
            }

            ///ACTUALIZAR PUEBLO
            case 3:
            {

                cout<<endl<<" Ingresa el Nombre del pueblo a actualizar: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el Estado del pueblo: ";
                getline(cin, estado);

                CPueblo* pueblito = new CPueblo();

                pueblito = HashPueblos.Buscar(nombre, estado);

                if(pueblito)
                {

                    cout<<endl<<endl<<" -------  Actualizar  -------"<<endl;
                    cout<<" [1]  Nombre del Pueblo"<<endl;
                    cout<<" [2]  Estado del Pueblo"<<endl;
                    cout<<" [3]  Satisfaccion"<<endl;
                    cout<<" [4]  Costo"<<endl;

                    cout<<endl<<"\n Ingresa una opcion: ";
                    cin>>opc3;

                    cout<<endl<<endl;
                    cin.sync();

                    switch(opc3)
                    {
                    case 1:
                        cout<<endl<<" Nuevo nombre: ";
                        getline(cin, nombre);
                        pueblito->setNombre(nombre);
                        break;

                    case 2:
                        cout<<endl<<" Nuevo estado: ";
                        getline(cin, estado);
                        pueblito->setEstado(estado);
                        break;

                    case 3:
                        cout<<endl<<" Nueva Satisfaccion: ";
                        cin>>satisfaccion;
                        pueblito->setSatisfaccion(satisfaccion);
                        break;


                    case 4:
                        cout<<endl<<" Nuevo Costo: ";
                        cin>>costo;
                        pueblito->setCosto(costo);
                        break;

                    default:
                        cout<<endl<<" Opcion no valida ";
                        break;
                    }
                    cout<<endl;
                    pueblito->Imprimir();
                }
                else
                    cout<<endl<<" El dato no existe en la tabla"<<endl;

                break;
            }

            ///ELIMINAR PUEBLO
            case 4:
            {

                cout<<endl<<" Ingresa el Nombre del pueblo a eliminar: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el Estado del pueblo: ";
                getline(cin, estado);

                CPueblo* pueblito = new CPueblo();



                pueblito = HashPueblos.Eliminar(nombre, estado);

                ///Eliminar los caminos hacia ese pueblo
                CListaCamino* lista = new CListaCamino;
                CPueblo* destino = new CPueblo;
                CCamino* camino = new CCamino;
                CCamino* camino1 = new CCamino;

                lista = HashCaminos.BuscarOrigen(pueblito->getNombre(), pueblito->getEstado());

                for(it = lista->Begin(); it != lista->End(); it++){
                    camino = *it;

                    destino = camino->getDestino();

                    camino = HashCaminos.Eliminar(nombre, estado, destino->getNombre(), destino->getEstado());
                    camino1 = HashCaminos.Eliminar(destino->getNombre(), destino->getEstado(), nombre, estado);

                    if(camino && camino1)
                        cout<<"Se elimino correctamente el camino"<<endl;

                }


                if(pueblito)
                    cout<<endl<<" Se ha eliminado correctamente"<<endl;
                else
                    cout<<endl<<" El dato no existe en la tabla"<<endl;


                break;
            }

            ///AGREGAR CAMINO
            case 5:
            {
                string nombreD, estadoD;
                cout<<endl<<" Ingresa el nombre del pueblo magico de origen: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el estado del pueblo magico de origen: ";
                getline(cin, estado);
                cout<<endl<<" Ingresa el nombre del pueblo magico de destino: ";
                getline(cin, nombreD);
                cout<<endl<<" Ingresa el estado del pueblo magico de destino: ";
                getline(cin, estadoD);
                cout<<endl<<" Ingresa el costo por transitar entre estos dos pueblos: ";
                cin>>costo;


                if(HashCaminos.Buscar(nombre, estado, nombreD, estadoD))
                {
                    cout<<endl<<" El dato ya existe en la tabla y no puede ser ingresado nuevamente"<<endl;
                    break;
                }

                CPueblo* pueblo1 = new CPueblo;
                CPueblo* pueblo2 = new CPueblo;

                pueblo1 = HashPueblos.Buscar(nombre, estado);
                pueblo2 = HashPueblos.Buscar(nombreD, estadoD);

                if(pueblo1 && pueblo2)
                {
                    ///Insertar doble por que es un grafo no dirigido
                    CCamino* camino = new CCamino(pueblo1, pueblo2, costo);
                    HashCaminos.Insertar(camino);

                    CCamino* camino2 = new CCamino(pueblo2, pueblo1, costo);
                    HashCaminos.Insertar(camino2);
                }
                else
                {
                    cout<<endl<<" No se encontro alguno de esos pueblos"<<endl;
                    break;
                }

                break;
            }

            ///BUSCAR CAMINO
            case 6:
            {
                string nombreD, estadoD;
                cout<<endl<<" Ingresa el nombre del pueblo magico de origen: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el estado del pueblo magico de origen: ";
                getline(cin, estado);
                cout<<endl<<" Ingresa el nombre del pueblo magico de destino: ";
                getline(cin, nombreD);
                cout<<endl<<" Ingresa el estado del pueblo magico de destino: ";
                getline(cin, estadoD);

                CCamino* camino = HashCaminos.Buscar(nombre, estado, nombreD, estadoD);

                if(camino)
                {
                    camino->Imprimir();
                }
                else
                {
                    cout<<endl<<" No se encontró ese camino"<<endl;
                }
                break;
            }

            ///ACTUALIZAR CAMINO
            case 7:
            {
                string nombreD, estadoD;
                cout<<endl<<" Ingresa el nombre del pueblo magico de origen: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el estado del pueblo magico de origen: ";
                getline(cin, estado);
                cout<<endl<<" Ingresa el nombre del pueblo magico de destino: ";
                getline(cin, nombreD);
                cout<<endl<<" Ingresa el estado del pueblo magico de destino: ";
                getline(cin, estadoD);

                CCamino* camino = new CCamino;

                camino = HashCaminos.Buscar(nombre, estado, nombreD, estadoD);

                if(camino)
                {
                    cout<<endl<<endl<<" -------  Actualizar  -------"<<endl;
                    cout<<" Nuevo peso: ";
                    cin>>peso;

                    camino->setPeso(peso);
                    break;
                }

                camino = HashCaminos.Buscar(nombreD, estadoD, nombre, estado);
                camino->setPeso(peso);
            }

            ///ELIMINAR CAMINO
            case 8:
            {
                string nombreD, estadoD;
                cout<<endl<<" Ingresa el nombre del pueblo de origen: ";
                getline(cin, nombre);
                cout<<endl<<" Ingresa el estado del pueblo de origen: ";
                getline(cin, estado);
                cout<<endl<<" Ingresa el nombre del pueblo de destino: ";
                getline(cin, nombreD);
                cout<<endl<<" Ingresa el estado del pueblo de destino: ";
                getline(cin, estadoD);

                CCamino* camino1 = new CCamino();
                CCamino* camino2 = new CCamino();

                camino1 = HashCaminos.Eliminar(nombre, estado, nombreD, estadoD);
                camino2 = HashCaminos.Eliminar(nombreD, estadoD, nombre, estado);

                if(camino1 && camino2)
                    cout<<endl<<" Se ha eliminado correctamente"<<endl;
                else
                    cout<<endl<<" El dato no se encontro"<<endl;

                break;
            }

            default:
                cout<<endl<<" Opcion incorrecta"<<endl;
            }

            cout<<endl;
            system("pause");
            break;

        }

        ///IMPRIMIR
        case 2:
        {
            system("cls");
            cout<< "----------------- Pueblos ----------------"<<endl;
            HashPueblos.Imprimir();
            system("pause");
            cout<< "----------------- Caminos ----------------"<<endl;
            HashCaminos.Imprimir();
            system("pause");
            break;
        }

        ///BUSCAR
        case 3:
        {
            system("cls");


            break;
        }
        ///ELIMINAR
        case 4:
        {
            system("cls");


            break;
        }
        break;
        ///SALIR
        case 7:
            cout<<" Ha salido del programa"<<endl;
            break;

        default:
            cout<<" Esa opcion no existe"<<endl;
        }

    }
    while(opc != 7);

    fstream salida("pueblitos.txt", ios_base::out);
    ///Validar si se logro abrir el archivo
    if(salida.good())
    {
        HashPueblos.Salvar(salida);
        cout<<" Se ha guardado correctamente"<<endl;
    }
    else
    {
        cout<<" El archivo no pudo ser creado"<<endl;
    }
    salida.close();


    fstream salida2("caminos.txt", ios_base::out);
    ///Validar si se logro abrir el archivo
    if(salida2.good())
    {
        HashCaminos.Salvar(salida2);
        cout<<" Se ha guardado correctamente"<<endl;
    }
    else
    {
        cout<<" El archivo no pudo ser creado"<<endl;
    }
    salida2.close();


    system("pause");

    return 0;
}
