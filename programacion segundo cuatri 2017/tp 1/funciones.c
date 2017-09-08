#include "funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
float sumar(float num1,float num2)
{
    float suma;
    suma=num1+num2;
    return suma;
}

float restar(float num1, float num2)
{
    float resta;
    resta=num1-num2;
    return resta;
}
float dividir(float num1,float num2)
{
    float division;
    division=num1/num2;
    return division;
}
float multiplicar(float num1,float num2)
{
    float multiplicacion;
    multiplicacion=num1*num2;
    return multiplicacion;
}
int verificar_numero(char numero[])
{
    int i;
    int contadorComaPunto=0;
    int contadorSigno=0;
    for (i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            if(numero[i]==',' && strlen(numero)==1)
            {
                printf("Error!\n");
                return 0;
            }
            else
            {

                if(numero[i]=='.' && strlen(numero)==1)
                {
                    printf("Error!\n");
                    return 0;
                }
            }
            if(numero[i]==','|| numero[i]=='.')
            {
                contadorComaPunto++;
            }
            else
            {
                if(numero[i]=='-' && i==0)
                {
                    contadorSigno++;
                }
                else
                {
                    if(numero[i]=='+' && i==0)
                    {
                        contadorSigno++;
                    }
                    else
                    {
                        printf("\nError!\n");
                        return 0;
                    }
                }
            }

            if(contadorComaPunto>1)
            {
                printf("\nIngrese solo numeros: \n");
                getch();
                return 0;
            }
            if(contadorSigno>1)
            {
                printf("\nIngrese solo numeros: \n");
                getch();
                return 0;
            }

        }


    }
    if (contadorComaPunto==1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

long long int factorialEntero(int vericacionEntero,float numero)
{
    int i;

    long long int resultado=1;

    if(vericacionEntero!=1)
    {
        printf("Cambie el primer numero a entero\n");
    }
    else
    {

        if(numero==0)
        {
            resultado=1;
        }
        else
        {

            for (i=(int)numero; i>0; i--)
            {
                resultado=resultado*i;
            }

        }

    }
    return resultado;

}
