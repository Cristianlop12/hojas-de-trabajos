#include <iostream>



using namespace std;



int main()

{

    int compra, ganancia, impuesto;

    float CCG, PV;



    cout<<"Dame el Precio Real del Producto: "<<endl;

    cin>>compra;



    cout<<"Dame el Porcentaje de la Ganancia que deseas: "<<endl;

    cin>>ganancia;



    cout<<"Dame el porcentaje del Impuesto:  "<<endl;

    cin>>impuesto;



    CCG=(compra*ganancia/100)+compra;



    PV=(CCG*impuesto)/100+CCG;



    cout<<"\n\nPrecio para la Venta es de:  "<<PV<<" pesos \n\n";

    return 0;

}
