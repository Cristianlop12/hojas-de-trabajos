#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct concierto{
	string vip;
	string platea;
	string popular;
	float precio = 0;
};
void mp(); //definicion de la funcion 
void inventario();
void leer_archivo();
int main(){	
	mp();	
	
}
void mp(){ 
	
	int resp;
	string nombrearchivo;
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombrearchivo);
	
	do{
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar tipo de compra "<<"\n";
		cout<<" 2 - Mostrar cantidad de entradas compradas "<<"\n";
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
	string vip_v;
	string platea_v;
	string popular_v;
	float precio_v;
	ofstream archivo; //grabar archivo
	fflush(stdin);
	cout<<"Ingrese identificacion: "<<endl;
	getline(cin,vip_v);
	fflush(stdin);
	cout<<"Ingrese si es socio: "<<endl;
	getline(cin,platea_v);
	fflush(stdin);
	cout<<"Ingrese entradas a comprar: "<<endl;
	getline(cin,popular_v);	
	cout<<"Ingrese Precio por entrada: "<<endl;
	cin>>precio_v;
	
	precio_v=precio_v + precio_v;
	
	archivo.open("concierto.txt",ios::app); //abrir archivo append
	archivo<<vip_v<<"\t"<<platea_v<<"\t"<<popular_v<<"\t"<<precio_v<<endl;
	archivo.close();	
}
void leer_archivo(){
	ifstream archivo;  
	archivo.open("concierto.txt",ios::in); 
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	concierto recordset[lineas];
	
	archivo.open("concierto.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].vip>>recordset[i].platea>>recordset[i].popular>>recordset[i].precio;
    }
    archivo.close(); 
    for(int i = 0; i <lineas; i++){
    	cout<<recordset[i].vip<<" "<<recordset[i].platea<<" "<<recordset[i].popular<<" "<<recordset[i].precio<<endl;
	}
	system("Pause");
	

}
