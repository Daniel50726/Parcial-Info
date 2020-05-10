#include <usuario.h>

string usuarios::lectura(string txt){
    string text;
    int i=0;
    char textin;
    ifstream tex(txt, ios::in);
    while (!tex.eof()){
        tex.get(textin);
        text.push_back(textin);
        i++;
    }
    text.pop_back();
    tex.close();
    return text;
}

void usuarios::cargar_mapa(string text, int mapa){
    string copia;
    string nameUsu,paswordUsu;
    long long int tam=text.size();
    int lineas=1,i=0;

    for(int k=0;k<tam;k++){ //contamos las lineas del archivo
        if(text[k]=='\n') lineas++;
    }

    for(int k=0;k<lineas;k++){
         while(text[i]!='\n' and text[i] !='\0'){
            copia.append(1,text[i]);
            i++;
        }
         i++;

         nameUsu=copia.substr(0,copia.find(" "));
         paswordUsu=copia.substr(copia.find(" ")+1);

         copia.clear();
         if(mapa==1) comparar[nameUsu]=paswordUsu;
         if(mapa==0) compararCli[nameUsu]=paswordUsu;
    }
}

bool usuarios::loginNew(string name, string pasword, int mapa){
    if(mapa==1){
        if(comparar.find(name)->second==pasword){
            cout<<endl<<"LOGEADO CON EXITO"<<endl;
            return true;
        }
        else cout<<endl<<"USUARIO O CONTRASENIA INCORRECTA"<<endl;
        return false;
    }
    if(mapa==0){
        if(compararCli.find(name)->second==pasword){
            cout<<endl<<"LOGEADO CON EXITO"<<endl;
            return true;
        }
        else cout<<endl<<"USUARIO O CONTRASENIA INCORRECTA"<<endl;
        return false;
    }
    else return false;
}

void usuarios::cargar_inventario(){
    vector <int> can_pre;
    int espacio,peso;
    int precio,cantidad;
    string copia;
    string namePro,cashPro,cantPro="";
    string Producto="Producto.txt";
    Producto=lectura(Producto);
    long long int tam=Producto.size();
    int lineas=1,i=0;

    for(int k=0;k<tam;k++){ //contamos las lineas del archivo
        if(Producto[k]=='\n') lineas++;
    }

    for(int k=0;k<lineas;k++){
         while(Producto[i]!='\n' and Producto[i] !='\0'){
            copia.append(1,Producto[i]);
            i++;
        }
         i++;

         namePro=copia.substr(0,copia.find('/')-1);
         espacio=copia.find('/');
         peso=copia.find('$');

         cashPro=copia.substr(peso+1);
         for(int i=espacio+1;i<peso-1;i++){
             cantPro+=copia[i];
         }

         cantidad=stoi(cantPro);
         precio=stoi(cashPro);
         can_pre.push_back(cantidad);
         can_pre.push_back(precio);
         productos[namePro]=can_pre;
         can_pre.clear();
         cantPro.clear();
         copia.clear();
    }
}

void usuarios::imprimir_vector(){
    map <string,vector<int>>::iterator r;
    int id=1;
    cout<<endl<<"EL INVENTARIO ES"<<endl;
    cout<<endl<<"id|       nombre                     |cant|precio|"<<endl;
    for(r=productos.begin();r!=productos.end();r++){
        cout<<endl<<"|"<<id<<"|"<<r->first<<"        |"<<r->second[0]<<" | "<<"$"<<r->second[1];
        id++;
    }
}
