#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class usuarios{
    private:
        string nombre;
        string clave;
    public:
        string lectura(string txt);
        string getNombre() const;
        void setNombre(const string &value);
        string getContrasenia() const;
        void setConstrasenia(const string &value);
        bool loginNew(string name, string pasword, int mapa);
        void cargar_mapa(string txt, int mapa);
        map<string,string> comparar;
        map<string,string> compararCli;
};

string usuarios::getNombre() const
{
    return nombre;
}

void usuarios::setNombre(const string &value)
{
    nombre = value;
}

string usuarios::getContrasenia() const
{
    return clave;
}

void usuarios::setConstrasenia(const string &value)
{
    clave=value;
}



