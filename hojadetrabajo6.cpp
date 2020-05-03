#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct modelo{
	string modelo1;
	string modelo2;
	string modelo3;
	string modelo4;
};
void mp();  
void inventario();
void leer_archivo();
int main(){	
	mp();	
	
}
void mp(){ 
	
	int resp;
	
	
	do{
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar modelos de cuadernos "<<"\n";
		cout<<" 2 - Mostrar los modelos "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opción: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			inventario();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void inventario(){
	string modelo1_v;
	string modelo2_v;
	string modelo3_v;
	string modelo4_v;
	ofstream archivo; 
	fflush(stdin);
	cout<<"Ingrese cantidad vendida de modelo1: "<<endl;
	getline(cin,modelo1_v);
	fflush(stdin);
	cout<<"Ingrese cantidad vendida de modelo2: "<<endl;
	getline(cin,modelo2_v);
	cout<<"Ingrese cantidad vendida de modelo3: "<<endl;
	cin>>modelo3_v;	
	cout<<"Ingrese cantidad vendida de modelo4: "<<endl;
	cin>>modelo4_v;
	
	archivo.open("libreria.txt",ios::app); 
	archivo<<modelo1_v<<"\t"<<modelo2_v<<"\t"<<modelo3_v<<"\t"<<modelo4_v<<endl;
	archivo.close();	
}
void leer_archivo(){
	ifstream archivo;  
	archivo.open("modelo.txt",ios::in); 
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
    libreria recordset.[lineas];
	
	archivo.open("libreria.txt",ios::in);
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
        }
        archivo>>recordset[i].modelo1>>recordset[i].modelo2>>recordset[i].modelo3>>recordset[i].modelo4;
    }
    archivo.close(); 
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].modelo1<<" "<<recordset[i].modelo2<<" "<<recordset[i].modelo3<<" "<<recordset[i].modelo4<<endl;
    
	}
	system("Pause");
	

}
