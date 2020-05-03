#include<stdio.h>

int main ()
{
int i;
float ventas[10],promedio=0,mayorventa=0;

printf("Programa que calcula el promedio de 10 ventas...\n");

for(i=0;i<10;i++)
    {
    printf("ingresa total de ventas de almacen %d:  ",i+1);
    scanf("%f",&ventas[i]);
    promedio += ventas[i];
    printf("\n");
    }
    printf("El promedio es:  %.2f\n\n",promedio/10);
 

}
