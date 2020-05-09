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
