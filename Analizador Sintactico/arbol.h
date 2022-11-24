#ifndef ARBOL_H
#define ARBOL_H
#include <bits/stdc++.h>


using namespace std;

class Arbol
{
    private:
        Arbol *izq;
        Arbol *der;
        string value;

    public:
        Arbol(Arbol *izq, Arbol *der, string value);
};

#endif