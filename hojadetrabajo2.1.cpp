#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct ventas {
	string categoria;
	string a;	
	string b;
	string c;	
};
void mp(); 
void ingresardatos(string na);
void leer_archivo(string na);
int main(){
	mp();	
}
void mp(){
	int resp;
	string nombrearchivo;
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar categorias "<<"\n";
		cout<<" 2 - Reportes de ventas "<<"\n";		
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			ingresardatos(nombrearchivo);			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo(nombrearchivo);
		}					
		else if (resp==4)
			break;
		else 
			break;
		
	} while(resp!=4);	
}

void ingresardatos(string na){
	string a_est;
	string categoria_est;
	string b_est;
	string c_est;
	
	cout<<"Ingrese categoria comercial o residencial: "<<endl;
	cin>>categoria_est;
	fflush(stdin);
	cout<<"Ingrese zona a o b: "<<endl;
	getline(cin,a_est);
	cout<<"Ingrese tipo: "<<endl;
	cin>>b_est;
	cout<<"Ingrese precio: "<<endl;
	cin>>c_est;
	
	ofstream archivo; //grabar en archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open(na.c_str(),ios::app); //append
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	archivo<<categoria_est<<"\t"<<a_est<<"\t"<<b_est<<"\t"<<c_est<<endl;
	archivo.close();
}

void leer_archivo(string na){
	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("ventas.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" 1 No se pudo abrir el archivo";
		exit(1);
	}
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
    
    ventas recordset[lineas];
	archivo.open(na.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break;
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].categoria>>recordset[i].a>>recordset[i].b>>recordset[i].c;
    	//cout<<s;
	}
    archivo.close();
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].a<<recordset[i].categoria<<recordset[i].b<<recordset[i].c<<endl;
	}
	system("Pause");
}

