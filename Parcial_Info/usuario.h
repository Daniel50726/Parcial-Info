#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>
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
        void cargar_inventario();
        void imprimir_vector();
        void guardar_mapa();
        void cambiar_mapa(int id, int cantidad);
        void agregar_mapa(string name,int cantidad, int precioU);
        bool comprobar_inv(int id, int cantidad);
        void guardar_combo(string name, vector<int> precio);
        void agregar_usu(string name, string pasword, string txt);
        void cargar_combos(string txt);
        void imprimir_combos();
        bool compro_dis(int id);
        bool din_suf(int id,int dinero);
        void cambiar_invCom(int id, int cant);
        void mod_inventario(int id);
        void mayor_menor(int id, int dinero);

        map<int,map <string,vector<int>>>::iterator r;
        map<string,vector<int>>::iterator r2;
        map<string,string> comparar;
        map<string,string> compararCli;
        map<int,map<string,vector<int>>> Inventario;
        map<int,map<string,vector<int>>> combos;
        map<string,vector<int>> productos;
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

int regresoCliente(int cosCom,int dinCli);


