#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct ventas{
	int tipoprod;
	float descuento;
	float precio;
	int unidades;
	float totalvta;
};
void venta();
void reporte();
int main(){
//	venta();
	reporte();
}
	
void venta(){
	int tipoprod;
	float precio;
	int unidades;
	float descuento;
	float totalvta;
	string s;
	
	cout<<"----- Cuchumatanes <<Compa�ia exterminio s.a>> -----"<<endl;
	cout<<" Ingrese tipo de servicio: "<<endl;
	cout<<" mala hierva    (Q10.00) -> 1  - Descuento 10%"<<endl;
	cout<<" langostas      (Q20.00) -> 2  - Descuento 15%"<<endl;
	cout<<" gusanos        (Q30.00) -> 3  - Descuento 20%"<<endl;
	cout<<" todos los anteriores(Q50.00) -> 4 "<<endl;
	cin>>tipoprod;
	cout<<"Indique el numero de unidades a comprar: "<<endl;
	cin>>unidades;	
	if (tipoprod ==1){
		descuento = 0.10;
		precio = 10.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	else if (tipoprod ==2){
		descuento = 0.20;
		precio = 20.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	} else if (tipoprod ==3){
		descuento = 0.10;
		precio = 30.00;
		totalvta = (precio - (descuento * precio) )* unidades; 
	}
	else if (tipoprod ==4){
		descuento = 0.0;
		precio = 50.00;
		totalvta = (precio - (descuento * precio) )* unidades; 
	}

	cout<<"Tipo Prod: "<<tipoprod<<"Descuento: "<<descuento<<"Precio: "<<precio<<"Unidades: "<<unidades<<"Total de la venta: "<<totalvta;
	ofstream grabararchivo;
	try {
		grabararchivo.open("cuchumatanes.txt",ios::app);
		grabararchivo<<tipoprod<<"\t"<<descuento<<"\t"<<precio<<"\t"<<unidades<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"Tipo Prod  Descuento  Precio  Unidades  TotalVenta"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("cuchumatanes.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}

void reporte(){
//mostrar el total global de la venta del dia y
//determinar el total de lo vendido por producto, mostrando tambien el porcentaje
//con relacion al total.
	ifstream db;
	float tp,d,p,u,tv=0;
	float sumatotal=0;
	float tp1=0;
	float tp2=0;
	float tp3=0;
	float tp4=0;	
	try{	
		db.open("cuchumatanes.txt",ios::in);
		
		while (db >>tp >> d >>p>> u>>tv){
			sumatotal = tv + sumatotal;	
			if (tp==1)
				tp1+=tv;
			else if (tp==2)
				tp2+=tv;
			else if (tp==3)
				tp3+=tv;
			else if (tp==4)
				tp4+=tv;
		}	
		db.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumatotal<<endl;
		cout<<"Desgloce por producto:  "<<endl;
		cout<<setprecision(5)<<" mala hierva   "<<tp1<<" - % sobre el total: "<<setprecision(3)<<tp1*100/sumatotal<<endl;
		cout<<setprecision(5)<<" langostas     "<<tp2<<" - % sobre el total: "<<setprecision(3)<<tp2*100/sumatotal<<endl;
		cout<<setprecision(5)<<" gusanos       "<<tp3<<" - % sobre el total: "<<setprecision(3)<<tp3*100/sumatotal<<endl;
		cout<<setprecision(5)<<" todos los anteriores"<<tp3<<" - % sobre el total: "<<setprecision(3)<<tp4*100/sumatotal<<endl;
		
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}
