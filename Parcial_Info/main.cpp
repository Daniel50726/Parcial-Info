#include <usuario.cpp>

int main()
{
    vector<int> idInv;
    bool login=false,proCom=false,dinCom,idCom;
    int id=0,cantidadPro,preciouPro,optionCom=1,cantCom=1,preCom,compra=0,comid=1;
    string admin="Admin.txt",guardar; //txt donde estan guardados los datos del Admin
    string usuario="Usuario.txt",usu; //txt donde estan guardados los datos de los Usuarios
    string combo="Combos.txt",ventas="Ventas.txt";
    string name, pasword, namePro,nameCom, nameUs, conUs,rend, sala, silla;
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

                Admin.cargar_inventario(); //cargamos el inventario al mapa
                Admin.imprimir_vector(); //imprimimos el mapa
                cout<<endl;

                cout<<endl;
                cout<<"A - Agregar inventario"<<endl;
                cout<<"B - Hacer combos"<<endl;
                cout<<"C - Registrar usuario"<<endl;
                cout<<"D - Reporte de ventas"<<endl;
                cout<<"E - Pedidos"<<endl;
                cout<<"F - Salir"<<endl;
                cout<<"Su opcion es: ";
                cin>>optionAdmin; //leemos las opciones del Admin

                if(optionAdmin=='A' or optionAdmin=='a'){
                    cout<<endl<<"Desea ingresar un nuevo producto? Y/N ";
                    cin>>optionid;
                    if(optionid=='N' or optionid=='n'){ //Si el producto ya existe

                        comid=Admin.tam_inv();
                        id=comid+1;

                        while(id>comid or id<=0){ //comprobamos que la id este en el rango
                            cout<<"Ingrese la id: ";
                            cin>>id;
                        }

                        cout<<"Ingresa la cantidad: ";
                        cin>>cantidadPro;
                        Admin.cambiar_mapa(id,cantidadPro); //cambiamos el mapa
                        Admin.imprimir_vector(); //Imprimimos elmapa
                        Admin.guardar_mapa(); //guardamos los cambios
                    }
                    else {
                        cin.ignore();
                        cout<<"Ingrese el nombre del Producto: ";
                        getline(cin, namePro);
                        cout<<"Ingrese la cantidad: ";
                        cin>>cantidadPro;
                        cout<<"Ingrese el precio por unidad: ";
                        cin>>preciouPro;
                        Admin.agregar_mapa(namePro,cantidadPro,preciouPro); // creamos el nuevo producto con el nombre, cantidad y precio
                        Admin.imprimir_vector(); //imprimimos el mapa
                        Admin.guardar_mapa(); //guardamos los cambios
                    }
                }
                if(optionAdmin=='B' or optionAdmin=='b'){
                    cout<<endl<<"Que combo desea hacer? "<<endl;
                    optionCom=1;
                    cantCom=1;
                    while(optionCom!=0 and cantCom!=0){
                        cout<<"Ingrese la id de los productos que va a usar (se ejecutara hasta que ingrese 0): ";
                        cin>>optionCom;
                        cout<<"Ingrese la cantidad: ";
                        cin>>cantCom;
                        if(optionCom!=0 and cantCom!=0){ //mientras no ingrese 0
                            compra=1; //Si al menos entro una primera vez
                            idInv.push_back(optionCom); //agregamos al vector las id del inventario
                            idInv.push_back(cantCom); //agregamos al vector la cantidad que se va a utilizar para el combo
                            proCom=Admin.comprobar_inv(optionCom,cantCom); //comprobamos si es posible generar el combo
                            if(proCom==false){
                                cout<<endl<<"NO SE PUEDE GENERAR EL COMBO, INVENTARIO INSUFICIENTE"<<endl;
                                idInv.clear();
                                break;
                            }
                        }
                        else if(compra==1){
                            cin.ignore();
                            cout<<"Ingrese el nombre del combo: "; //si ya entro aunque sea una vez preguntamos el nombre
                            getline(cin,nameCom);
                            cout<<"Ingrese el precio del combo: "; // y el precio del combo
                            cin>>preCom;
                            idInv.insert(idInv.begin()+0,preCom); //agregamos el precio al inicio del vector
                            Admin.guardar_combo(nameCom,idInv); //agregamos el combo al txt
                            Admin.cargar_combos(combo,0); //cargamos al mapa el txt
                            Admin.imprimir_combos(); //imprimimos el combo
                            idInv.clear(); //reiniciamos variables
                        }
                    }
                }
                if(optionAdmin=='C' or optionAdmin=='c'){
                    cin.ignore();
                    cout<<endl<<"Ingrese el nombre del usuario: ";
                    getline(cin,nameUs);
                    cout<<endl<<"Ingrese la contrasenia del usuario: ";
                    getline(cin,conUs);
                    Admin.agregar_usu(nameUs,conUs,usuario);
                    Admin.cargar_mapa(usu,0);
                }
                if(optionAdmin=='D' or optionAdmin=='d'){
                    Admin.cargar_combos(ventas,1); // cargamos el mapa de ventas
                    Admin.reporte_ventas(); // imprimimos el txt Ventas.txt
                    cout<<endl<<"Desea reiniciar el dia? Y/N "; //preguntamos si ya se acabo el dia
                    cin>>rend;
                    if(rend=="Y" or rend=="y"){
                        Admin.cargar_combos(combo,0); // Se reinicia el reporte de ventas
                        Admin.guardar_compra(); // se guardan los cambios
                        Admin.reiniciar_dia();
                        cout<<endl<<"DIA REINICIADO"<<endl;
                    }
                }
                if(optionAdmin=='E' or optionAdmin=='e'){
                    Admin.cargar_combos(combo,0);
                    Admin.cargar_pedido();
                    Admin.imprimir_pedidos();
                    cout<<"Desea reiniciar el dia? Y/N ";
                    cin>>rend;
                    if(rend=="Y" or rend=="y"){
                        Admin.reiniciar_dia();
                        Admin.guardar_compra();
                        cout<<endl<<"DIA REINICIADO"<<endl;
                    }
                }
                if(optionAdmin=='F' or optionAdmin=='f'){
                    login=false; //breakcondition
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

                Cliente.cargar_combos(combo,0); //cargamos en un mapa el txt Combos
                Cliente.imprimir_combos(); //Imprimimos en una tabla el vector

                cout<<endl;
                cout<<"A - Seleccionar combo"<<endl;
                cout<<"B - Salir"<<endl;
                cout<<"Su opcion es: ";
                cin>>optionUsuario; //leemos las opciones del Usuario

                if(optionUsuario=='A' or optionUsuario == 'a'){

                    comid=Cliente.numero_combo();
                    id=comid+1;

                    while(id>comid or id<=0){ //comprobamos que la id esta en el rango
                        cout<<endl<<"Ingrese la id del combo que desea comprar: ";
                        cin>>id;
                        if(id>comid or id<=0){
                            cout<<"ID INGRESADO NO CORRESPONDE A NINGUN COMBO"<<endl;
                        }
                    }

                    cout<<"Con cuanto va a pagar?: ";
                    cin>>preCom;
                    cout<<endl;

                    Cliente.cargar_combos(ventas,1); //agregamos el txt a un mapa
                    idCom=Cliente.compro_dis(id); //comprobamos que la id ingresada tenga disponibilidad
                    dinCom=Cliente.din_suf(id,preCom); //comprobamos si el dinero ingresado es suficiente
                    if(dinCom==true and idCom==true){
                        Cliente.efec_compra(id); //si lo es cambiamos el mapa de ventas
                        Cliente.actu_compra(); //cambiamos el txt
                        Cliente.cargar_inventario(); //cargamos el mapa de inventario
                        Cliente.mod_inventario(id); //actualizamos el inventario
                        Cliente.mayor_menor(id,preCom); //calculamos si se le debe dar devuelta al cliente y de ser asi calculamos la devuelta
                        cout<<endl<<"En que sala desea recibir su orden? "<<endl;
                        cin.ignore();
                        getline(cin,sala);
                        cout<<"En que asiento? "<<endl;
                        getline(cin,silla);
                        Cliente.guardar_ubicacion(silla,sala,id); //guardamos el la ubiacion en un txt
                        cout<<endl<<"GRACIAS POR SU COMPRA!! :)"<<endl;
                        login=false;
                    }
                    else cout<<endl<<"DINERO INSUFICIENTE O LA ID NO CORRESPONDE A NINGUN VALOR"<<endl;
                }
                if(optionUsuario=='B' or optionUsuario == 'b'){
                    login=false; //breakcondition
                }
            }
        }
    }
}


