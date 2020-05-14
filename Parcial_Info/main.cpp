#include <usuario.cpp>

int main()
{
    vector<int> idInv;
    bool login=false,proCom=false,costCom=false,dinCom;
    int id=0,cantidadPro,preciouPro,optionCom=1,cantCom=1,preCom,compra=0;
    string admin="Admin.txt",guardar; //txt donde estan guardados los datos del Admin
    string usuario="Usuario.txt",usu; //txt donde estan guardados los datos de los Usuarios
    string combo="Combos.txt",ventas="Ventas.txt";
    string name, pasword, namePro,nameCom, nameUs, conUs;
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
                    if(optionid=='N' or optionid=='n'){
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
                        cin.ignore();
                        cout<<"Ingrese el nombre del Producto: ";
                        getline(cin, namePro);
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
                    cout<<endl<<"Que combo desea hacer? "<<endl;
                    optionCom=1;
                    cantCom=1;
                    while(optionCom!=0 and cantCom!=0){
                        cout<<"Ingrese la id de los productos que va a usar (se ejecutara hasta que ingrese 0): ";
                        cin>>optionCom;
                        cout<<"Ingrese la cantidad: ";
                        cin>>cantCom;
                        if(optionCom!=0 and cantCom!=0){
                            compra=1;
                            idInv.push_back(optionCom);
                            idInv.push_back(cantCom);
                            Admin.cargar_inventario();
                            proCom=Admin.comprobar_inv(optionCom,cantCom);
                            if(proCom==false){
                                cout<<endl<<"NO SE PUEDE GENERAR EL COMBO, INVENTARIO INSUFICIENTE"<<endl;
                                idInv.clear();
                                break;
                            }
                        }
                        else if(compra==1){
                            cin.ignore();
                            cout<<"Ingrese el nombre del combo: ";
                            getline(cin,nameCom);
                            cout<<"Ingrese el precio del combo: ";
                            cin>>preCom;
                            idInv.insert(idInv.begin()+0,preCom);
                            Admin.guardar_combo(nameCom,idInv);
                            Admin.cargar_combos(combo,0);
                            Admin.imprimir_combos();
                            idInv.clear();
                        }
                    }
                }
                if(optionAdmin=='D' or optionAdmin=='d'){
                    cin.ignore();
                    cout<<endl<<"Ingrese el nombre del usuario: ";
                    getline(cin,nameUs);
                    cout<<endl<<"Ingrese la contrasenia del usuario: ";
                    getline(cin,conUs);
                    Admin.agregar_usu(nameUs,conUs,usuario);
                    Admin.cargar_mapa(usu,0);
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
                    Cliente.cargar_combos(combo,0);
                    Cliente.imprimir_combos();
                }
                if(optionUsuario=='B' or optionUsuario == 'b'){
                    cout<<endl<<"Ingrese la id del combo que desea comprar: ";
                    cin>>id;
                    cout<<"Con cuanto va a pagar?: ";
                    cin>>preCom;
                    cout<<endl;
                    Cliente.cargar_combos(combo,0);
                    //Cliente.guardar_compra();
                    Cliente.cargar_combos(ventas,1);
                    costCom=Cliente.compro_dis(id);
                    dinCom=Cliente.din_suf(id,preCom);
                    if(costCom==true and dinCom==true){
                        Cliente.efec_compra(id);
                        Cliente.actu_compra();
                        Cliente.cargar_inventario();
                        Cliente.mod_inventario(id);
                        Cliente.mayor_menor(id,preCom);
                        cout<<endl<<"En que sala desea recibir su orden? "<<endl;
                        cout<<"En que asiento? "<<endl;
                    }
                }
                if(optionUsuario=='C' or optionUsuario == 'c'){
                    login=false;
                }
            }
        }

    }
}


