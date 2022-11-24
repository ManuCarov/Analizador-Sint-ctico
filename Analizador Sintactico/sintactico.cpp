#include <bits/stdc++.h>
#include "sintactico.h" 
#include "arbol.h"
#include <fstream>
using namespace std;

static const string inicio = "Ingrese una oracion: ";
static const string final = "Escriba otra oracion para analizar o escriba FIN para terminar el programa: ";
static const string correcto = "Oración simple valida";
static const string incorrecto = "Oracion invalida";

bool buscador(string name[], string comparar[], int x)
{
    const int num = sizeof(comparar);
    int verb = 0;
    for(int i=0; i<=num; i++)
    {
        if(comparar[i] == name[x])
        {
            verb++;
        }
    }

    if (verb == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Sintaxis::buscarSujeto()
{
    const int num = sizeof(oracion);

    // for(int i = 0; i<=num; i++)
    // {
    //     bool respuesta = buscador(oracion, articulos, i);
    //     if (respuesta == true)
    //     {
    //         string articulo = oracion[i];
    //         return articulo;
    //         break;
    //     }
    // }

    for(int i = 0; i<=num; i++)
    {
        bool respuesta2 = buscador(oracion, sujetos, i);

        if(respuesta2 == true)
        {
            string sujeto = oracion[i];
            return sujeto;
            break;
        }
    }
    
}

string Sintaxis::buscarVerbo()
{
    const int num = sizeof(oracion);

    for(int i = 0; i<=num; i++)
    {
        bool respuesta = buscador(oracion, verbos, i);
        if (respuesta == true)
        {
            string verbo = oracion[i];
            return verbo;
            break;
        }
    }
}

string Sintaxis::buscarPredicado()
{
    const int num = sizeof(oracion);

    for(int i = 0; i<=num; i++)
    {
        bool respuesta = buscador(oracion, verbos, i);
        if (respuesta == true)
        {
            string predicado = oracion[i];
            return predicado;
        }
    }
}

string Sintaxis::verificador()
{
    //Arbol *arbolito = new Arbol(new Arbol(NULL,NULL,sujeto),new Arbol(NULL,NULL,predicado),verbo);
    const int num = sizeof(oracion);
    string verbo = buscarVerbo();
    int posicion;
    for(int i=0; i<=num; i++)
    {
        if(oracion[i] == verbo)
        {
            posicion = i;
            break;
        }
    }
   
    string sujeto = buscarSujeto();
    string predicado = buscarPredicado();
    
}

void Sintaxis::reiniciar()
{

}

void mensaje(string mensaje){
	cout << mensaje;
}

void mensajeBienvenida(){
	mensaje("Analizador Sintactico\n\n");
	mensaje(inicio);
} 

void mensajeError(){
    mensaje(incorrecto);
}



string* arreglo(std::string cadenaInicial, string oracion[])
{
    string palabra;
    int i = 0;
    stringstream input_stringstream(cadenaInicial);
    while (getline(input_stringstream, palabra, ' '))
    {
        oracion[i] = palabra;
        i++;
    }
    return oracion;
}

string* archivoUno(string sujetos[])
{
    ifstream archivo1;
    int i=0;

    archivo1.open("Sujetos.txt", ios::in);

    if(archivo1.fail())
    {
        cout<<"Fallo al abrir el archivo 'Sujetos'";
        exit(1); 
    }

    while(!archivo1.eof())
    {
        getline(archivo1, sujetos[i]);
        i++;
    }

    archivo1.close();
    return sujetos;
}

string* archivoDos(string verbos[])
{
    ifstream archivo2;
    int i=0;

    archivo2.open("Verbos.txt", ios::in);

    if(archivo2.fail())
    {
        cout<<"Fallo al abrir el archivo 'Verbos'";
        exit(1); 
    }

    while(!archivo2.eof())
    {
        getline(archivo2, verbos[i]);
    }

    archivo2.close();
    return verbos;
}

string* archivoTres(string predicado[])
{
    ifstream archivo3;
    int i=0;

    archivo3.open("Predicado.txt", ios::in);

    if(archivo3.fail())
    {
        cout<<"Fallo al abrir el archivo 'Predicado'";
        exit(1); 
    }

    while(!archivo3.eof())
    {
        getline(archivo3, predicado[i]);
    }

    archivo3.close();
    return predicado;
}

string* archivoCuatro(string articulos[])
{
    ifstream archivo4;
    int i=0;

    archivo4.open("articulos.txt", ios::in);

    if(archivo4.fail())
    {
        cout<<"Fallo al abrir el archivo 'Articulos'";
        exit(1); 
    }

    while(!archivo4.eof())
    {
        getline(archivo4, articulos[i]);
    }

    archivo4.close();
    return articulos;
}

int main()
{ 
    string oracion[10];
    string sujetos[1000];
    string verbos[1000];
    string predicado[1000];
    string articulos[15];

    mensajeBienvenida();
    string cadenaInicial;
    std::cin >> cadenaInicial;
    string *arre = arreglo(cadenaInicial, oracion);
    string *suj = archivoUno(sujetos);
    return 0;
}
