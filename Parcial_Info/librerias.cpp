#include <librerias.h>

string lectura(string txt){
    string y;
    ifstream archivo;
    archivo.open(txt,ios::in); //abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout<<"No se pude abrir el programa"<<endl;
    }
    //tenemos en la varieble y todo lo que esta en el archivo
    while(!archivo.eof()){
        getline(archivo,y);
    }
    archivo.close();
    return y;
}
