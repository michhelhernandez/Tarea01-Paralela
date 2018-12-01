#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;


void CopiarConPuntos()
{
    ifstream archivo;
    ofstream copia;
    string texto;

    archivo.open("numeros.txt",ios::in);
    copia.open("copia.txt",ios::out);

    if(archivo.fail() || copia.fail())
        cout<<"Error, no se pudo abrir el archivo!"<<endl;

    while(!archivo.eof())    //mientras no sea el final del archivo
    {
        getline(archivo,texto);
        if(texto!="")
        {
            texto.replace(1,1, ".");
            copia << texto<<endl;
        }
    }

    archivo.close();
    copia.close();
}

int Cantidad()
{
    ifstream archivo;
    string texto;
    int notas=0;

    archivo.open("numeros.txt",ios::in);

    if(archivo.fail())
        cout<<"Error, no se pudo abrir el archivo!"<<endl;

    while(!archivo.eof())    //mientras no sea el final del archivo
    {
        getline(archivo,texto); //guarda una linea en la variable "texto"
        if(texto!="")
            notas++;
    }

    archivo.close();
    return notas;
}

float SumaTotal()
{
    CopiarConPuntos();
    ifstream archivo;
    string texto;
    float nota,suma=0.0;
    char cad[5];

    archivo.open("copia.txt",ios::in);

    if(archivo.fail())
        cout<<"Error, no se pudo abrir el archivo!"<<endl;

    while(!archivo.eof())    //mientras no sea el final del archivo
    {
        getline(archivo,texto); //guarda una linea en la variable "texto"
        if(texto!="")
        {
            nota=atof(strcpy(cad, texto.c_str()));
            suma=suma+nota;
        }
    }

    archivo.close();
    return suma;
}

float Promedio()
{
    float suma=SumaTotal();
    int n=Cantidad();

    if (n!=0)
        return (suma/n);
    else
        return 0;
}

int main()
{
    cout<<"Cantidad de notas: "<<Cantidad()<<endl;
    cout<<"La suma total de notas: "<<SumaTotal()<<endl;
    cout<<"El promedio de notas: "<<Promedio()<<endl;
    return 0;
}
