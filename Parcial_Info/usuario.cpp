#include <usuario.h>

template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << setfill(' ') << t;
}

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

void usuarios::guardar_mapa(){
    int A=0;
    map<string,vector<int>> copia;
    int cantint,preint;
    string name,cant,pre;
    string text= "Producto.txt";
    ofstream agregar;
    for(r=Inventario.begin();r!=Inventario.end();r++){
        copia=r->second;
        for(r2=copia.begin();r2!=copia.end();r2++){
            name=r2->first; //Extraemos el nombre
            cantint=r2->second[0]; //Extraemos la cantidad
            preint=r2->second[1];//Extraemos el precio
            cant=std::to_string(cantint); //convertimos la cantidad a string
            pre=std::to_string(preint); //convertimos la cantidad a string

            if(A==0){
                agregar.open(text,ios::out); //abrimos el archivo en modo escritura para eliminar todo lo que tenia
                agregar<<name<<" "<<"/"<<cant<<" "<<"$"<<pre; //escribimos en el txt de la manera adecuada
                agregar.close();
                A+=1; //cambiamos el modo de abrir el txt
            }
            else{
                agregar.open(text,ios::app); //abrimos el archivo en modo agregar
                agregar<<"\n"<<name<<" "<<"/"<<cant<<" "<<"$"<<pre; //agregamos en el txt de la manera adecuada
                agregar.close();
            }
        }
    }
}

void usuarios::cargar_mapa(string text, int mapa){
    string copia;
    string nameUsu,paswordUsu;
    long long int tam=text.size();
    int lineas=1,i=0;

    for(int k=0;k<tam;k++){ //contamos las lineas del archivo
        if(text[k]=='\n') lineas++;
    }

    for(int k=0;k<lineas;k++){ //segmentamos linea a linea el txt
         while(text[i]!='\n' and text[i] !='\0'){
            copia.append(1,text[i]);
            i++;
        }
         i++;

         nameUsu=copia.substr(0,copia.find(" ")); //sacamos el nombre
         paswordUsu=copia.substr(copia.find(" ")+1); //sacamos la contraseña

         copia.clear();
         if(mapa==1) comparar[nameUsu]=paswordUsu; //Agregamos el nombre al mapa
         if(mapa==0) compararCli[nameUsu]=paswordUsu; //Agregamos la contraseña al mapa
    }
}

bool usuarios::loginNew(string name, string pasword, int mapa){
    if(mapa==1){
        if(comparar.find(name)->second==pasword){ //comparamos los datos del mapa, con los datos ingresados por el usuario
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
    int id=1;
    string namePro,cashPro,cantPro="";
    string Producto="Producto.txt";
    Producto=lectura(Producto);
    long long int tam=Producto.size();
    int lineas=1,i=0;

    for(int k=0;k<tam;k++){
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

         cantidad=stoi(cantPro); //convertimos la cantidad a entero
         precio=stoi(cashPro); //convertimos el costo a entero
         can_pre.push_back(cantidad);
         can_pre.push_back(precio); //vector
         productos[namePro]=can_pre; //se agrega todo al mapa1
         Inventario[id]=productos; //se agrega todo al mapa2
         id++;
         //reiniciamos variables
         productos.clear();
         can_pre.clear();
         cantPro.clear();
         copia.clear();
    }
}

void usuarios::imprimir_vector(){
    map<string,vector<int>> copia; //creamos una copia para acceder al segundo mapa
    cout<<endl<<"EL INVENTARIO ES"<<endl;
    cout<<endl<<"|id|                 Nombre                           |cant|precio|"<<endl;
    for(r=Inventario.begin();r!=Inventario.end();r++){
        printElement(r->first,5);
        copia=r->second;  //agregamos a la copia el segundo mapa
        for(r2=copia.begin();r2!=copia.end();r2++){
            printElement(r2->first,50);
            printElement(r2->second[0],5);
            printElement(r2->second[1],5);
            cout<<endl;
        }
    }
}

void usuarios::cambiar_mapa(int id, int cant){
    map<string,vector<int>> copia; //creamos un copia para el segundo mapa
    int precioUn;
    int canAc;
    int precioAc;
    copia=Inventario.find(id)->second; //buscamos la id del producto en el primer mapa
    for(r2=copia.begin();r2!=copia.end();r2++){ //recorremos el segundo mapa
        canAc=r2->second[0]; //accedemos a la cantidad
        precioAc=r2->second[1]; //accedemos al precio
        precioUn=precioAc/canAc; //calculamos el precio por unidad
        canAc+=cant; //modificamos la cantidad
        precioAc+=precioUn*cant; //modificamos el precio
        //ingresamos las modificaciones a la copia
        r2->second[0]=canAc;
        r2->second[1]=precioAc;
    }
    Inventario[id]=copia; //modificamos el mapa
}

void usuarios::agregar_mapa(string name, int cantidad, int precioU){
    int tam=Inventario.size(); //calculamos el tamaño, para agregar despues la id del nuevo producto
    map<string,vector<int>> copia; //creamos una copia del segundo mapa
    vector<int> can_pre; //creamos un vector de enteros
    can_pre.push_back(cantidad); //agregamos la cantidad brindada por el usuario
    precioU*=cantidad; //calculamos el precio total
    can_pre.push_back(precioU); //agregamos el precio
    copia[name]=can_pre; //creamos el mapa map<strin,vector<int>>
    Inventario[tam+1]=copia; //agregamos el nuevo producto

}
