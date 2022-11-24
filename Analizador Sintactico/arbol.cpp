#include <bits/stdc++.h>
#include <string>
#include "arbol.h"      


using namespace std;

Arbol::Arbol (Arbol *izq, Arbol *der, string value)
{
    this->izq = izq;
    this->der = der;
    this->value = value;
}