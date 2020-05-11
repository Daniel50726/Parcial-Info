#include <usuario.cpp>

int main()
{
    bool login=false;
    int id=0,cantidadPro,preciouPro;
    string admin="Admin.txt",guardar; //txt donde estan guardados los datos del Admin
    string usuario="Usuario.txt",usu; //txt donde estan guardados los datos de los Usuarios
    string name, pasword, namePro;
    usuarios Admin, Cliente;
    char option=' ',optionAdmin=' ', optionUsuario=' ',optionid=' ';
    guardar=Admin.lectura(admin); //leemos el txt del Admin
    usu=Cliente.lectura(usuario); //leemos el txt del Cliente

    while(option!='C' and option!='c'){

        cout<<endl;
        cout<<"BIENVENIDO"<<endl;
        cout<<endl;
        cout<<"Que desea hacer?"<<endl;
        cout<<"A - Ingresar como Administrador"<<endl;
        cout<<"B - Ingresar como cliente"<<endl;
        cout<<"C - Salir"<<endl;
        cout<<"Su opcion es: ";
        cin>>option;  //leemos la manera de logearse

        if(option=='A' or option=='a'){

            Admin.cargar_mapa(guardar,1); //cargamos el txt en el mapa del Administrador

            cin.ignore();
            cout<<"Ingrese su nombre: ";
            getline(cin, name);
            Admin.setNombre(name);

            cout<<"Ingrese su clave: ";
            getline(cin, pasword);
            Admin.setConstrasenia(pasword);

            login=Admin.loginNew(name,pasword,1); //Comprobamos los datos ingresados

            while(login==true){

                cout<<endl;
                cout<<"A - Mirar inventario"<<endl;
                cout<<"B - Agregar inventario"<<endl;
                cout<<"C - Hacer combos"<<endl;
                cout<<"D - Registrar usuario"<<endl;
                cout<<"E - Reporte de ventas"<<endl;
                cout<<"F - Salir"<<endl;
                cout<<"Su opcion es: ";
                cin>>optionAdmin; //leemos las opciones del Admin

                if(optionAdmin=='A' or optionAdmin=='a'){
                    Admin.cargar_inventario();
                    Admin.imprimir_vector();
                    cout<<endl;
                }
                if(optionAdmin=='B' or optionAdmin=='b'){
                    cout<<endl<<"Desea ingresar un nuevo producto? Y/N ";
                    cin>>optionid;
                    if(optionid=='N'){
                        cout<<"Ingrese la id: ";
                        cin>>id;
                        cout<<"Ingresa la cantidad: ";
                        cin>>cantidadPro;
                        Admin.cargar_inventario();
                        Admin.cambiar_mapa(id,cantidadPro);
                        Admin.imprimir_vector();
                        Admin.guardar_mapa();
                    }
                    else {
                        cout<<"Ingrese el nombre del Producto: ";
                        cin>>namePro;
                        cout<<"Ingrese la cantidad: ";
                        cin>>cantidadPro;
                        cout<<"Ingrese el precio por unidad: ";
                        cin>>preciouPro;
                        Admin.cargar_inventario();
                        Admin.agregar_mapa(namePro,cantidadPro,preciouPro);
                        Admin.imprimir_vector();
                        Admin.guardar_mapa();
                    }
                }
                if(optionAdmin=='C' or optionAdmin=='c'){
                    cout<<endl<<"Estamos trabajando en eso"<<endl;
                }
                if(optionAdmin=='D' or optionAdmin=='d'){
                    cout<<endl<<"Estamos trabajando en eso"<<endl;
                }
                if(optionAdmin=='E' or optionAdmin=='e'){
                    cout<<endl<<"Estamos trabajando en eso"<<endl;
                }
                if(optionAdmin=='F' or optionAdmin=='f'){
                    login=false;
                }
            }

        }

        if(option=='B' or option=='b'){

            Cliente.cargar_mapa(usu,0); //cargamos el txt en el mapa de los Clientes

            cin.ignore();
            cout<<"Ingrese su nombre: ";
            getline(cin,name);
            Cliente.setNombre(name);

            cout<<"Ingrese su clave: ";
            getline(cin,pasword);
            Cliente.setNombre(pasword);

            login=Cliente.loginNew(name,pasword,0); //comprobamos la informacion

            while(login==true){
                cout<<endl;
                cout<<"A - Mirar tabla de combos"<<endl;
                cout<<"B - Seleccionar combo"<<endl;
                cout<<"C - Salir"<<endl;
                cout<<"Su opcion es: ";
                cin>>optionUsuario; //leemos las opciones del Usuario

                if(optionUsuario=='A' or optionUsuario == 'a'){
                    cout<<"Estamos trabajando en eso"<<endl;
                }
                if(optionUsuario=='B' or optionUsuario == 'b'){
                    cout<<"Estamos trabajando en eso"<<endl;
                }
                if(optionUsuario=='C' or optionUsuario == 'c'){
                    login=false;
                }
            }
        }

    }
}


