#include <iostream>
#include <iomanip>
using namespace std;
// Define el numero maximo de horas semanales
#define MAX_HORAS_SEMANALES 40
void imprimir_cabecera() {
 cout << "*********************************" << endl;
 cout << "* Salario Por Horas Trabajadas *" << endl;
 cout << "*********************************" << endl;
 cout << " "<<endl;
}
int entrada_usuario (char* cadena) {
 int valor_a_devolver;
 cout << cadena;
 cin >> valor_a_devolver;
 return (valor_a_devolver);
}
void imprimir (char* cadena, int valor) {
 cout << cadena << valor << endl;
}
int calcular_sueldo_base (int horas, int coste) {
 if (horas > MAX_HORAS_SEMANALES)
 return (MAX_HORAS_SEMANALES * coste);
 else
 return (horas * coste);
}
int calcular_horas_extras (int horas) {
 if (horas > MAX_HORAS_SEMANALES)
 return (horas - MAX_HORAS_SEMANALES);
 else
 return (0);
}
int main ()
{
 int horas_trabajadas, coste_hora, horas_extras, sueldo_neto,sueldo_base, incremento_horas_extras, coste_hora_extra;
 imprimir_cabecera();
 horas_trabajadas = entrada_usuario ("Ingrese horas trabajadas: ");
 coste_hora = entrada_usuario ("Ingrese el coste por hora: ");
 sueldo_base = calcular_sueldo_base (horas_trabajadas, coste_hora);
 horas_extras = calcular_horas_extras (horas_trabajadas);
 incremento_horas_extras = horas_extras * coste_hora * 3;
 sueldo_neto = sueldo_base + incremento_horas_extras;
 imprimir ("Las horas extras son: ", horas_extras);
 imprimir ("El sueldo base es: ", sueldo_base);
 imprimir ("El sueldo neto es: ", sueldo_neto);
 return 0;
}
