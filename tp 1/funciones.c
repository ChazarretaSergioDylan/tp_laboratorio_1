#include "funciones.h"
#include <stdlib.h>
int sumar(int num1,int num2)
{
    int suma;
    suma=num1+num2;
    return suma;
}
void refrescarPantalla()
{
    system("pause");
    system("cls");

}
int restar(int num1, int num2)
{
    int resta;
    resta=num1-num2;
    return resta;
}
float dividir(int num1,int num2)
{
    float division;
    division=(float)num1/num2;
    return division;
}
int multiplicar(int num1,int num2)
{
    int multiplicacion;
    multiplicacion=num1*num2;
    return multiplicacion;
}
