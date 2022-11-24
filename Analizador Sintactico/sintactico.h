#ifndef SINTACTICO_H
#define SINTACTICO_H
#include <string>
#include <stdlib.h>

using namespace std;

class Sintaxis
{
    private:
        string oracion[10];
        string sujetos[1000];
        string verbos[1000];
        string predicado[1000];
        string articulos[15];

    public:
        string buscarSujeto();
        string buscarVerbo();
        string buscarPredicado();
        string verificador();
        void reiniciar();
};

#endif