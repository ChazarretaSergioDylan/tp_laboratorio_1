#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char seguir='s';
    char numero[15];
    int opcion=0,multiplicacion,sumatoria,resta;
    float division,numero1,numero2;
    long long int resultFactorial;
    int i,flag2=0,flag1=0,auxVerificacion=0,num1EsEntero=0;
    while(seguir=='s')
    {
        printf("\t\t\t\tBienvenido!\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Ingrese una opcion:\n");
        if(flag1==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {

            printf("1- Ingresar 1er operando (A=%f)\n",numero1);


        }
        if(flag2==0)
        {
            printf("2- Ingresar 2do operando (B=x)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%f)\n",numero2);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        do
        {
            scanf("%s",numero);
            auxVerificacion=verificar_numero(numero);
        }
        while(auxVerificacion!=1);
        if(auxVerificacion==1)
        {
            opcion=atoi(numero);
        }

        switch(opcion)
        {
        case 1:


            do
            {
                printf("Ingrese el primer numero:\n");
                scanf("%s",numero);
                auxVerificacion=verificar_numero(numero);
            }
            while(auxVerificacion==0);


                if(auxVerificacion==1)
        {
            num1EsEntero=1;
        }

                numero1=atof(numero);
                printf("numero ingresado: %f\n",numero1);



            flag1=1;

            system("pause");
            system("cls");
            break;
        case 2:
            do
            {
                printf("Ingrese el segundo numero:\n");
                scanf("%s",numero);
                auxVerificacion=verificar_numero(numero);
            }
            while(auxVerificacion==0);

                numero2=atof(numero);
            if(auxVerificacion==1)
        {
            num1EsEntero=1;
        }

            flag2=1;

            system("pause");
            system("cls");

            break;
        case 3:
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la suma puesto que no se ha ingresado los dos numeros \n");
            }
            else
            {
                sumatoria=sumar(numero1,numero2);
                printf("la suma es: %d \n",sumatoria);
            }

            system("pause");
            system("cls");

            break;
        case 4:
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la resta puesto que no se ha ingresado los dos numeros \n");
            }
            else
            {
                resta=restar(numero1,numero2);
                printf("la resta es: %d \n",resta);
            }

            system("pause");
            system("cls");

            break;
        case 5:
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la division puesto que no se ha ingresado los dos numeros \n");
            }
            else
            {
                if(numero2==0)
                {
                    printf("no se puede dividir por cero.\n");
                }
                else
                {
                    division=dividir(numero1,numero2);
                    printf("la division es: %f \n",division);
                }
            }

            system("pause");
            system("cls");

            break;
        case 6:
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la multiplicacion puesto que no se ha ingresado los dos numeros \n");
            }
            else
            {
                multiplicacion=multiplicar(numero1,numero2);
                printf("la multiplicacion es: %d \n",multiplicacion);
            }

            system("pause");
            system("cls");

            break;
        case 7:
            if (flag1==0)
            {
                printf("no se puede obtener el factorial puesto que no ingreso un numero.\n");
            }
            else
            {
               resultFactorial=factorialEntero(num1EsEntero,numero1);
               printf("\nEl factorial  de %f es: %lld \n",numero1,resultFactorial);

            }

            system("pause");
            system("cls");

            break;
        case 8:
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la suma puesto que no se ha ingresado los numeros \n");
            }
            else
            {
                sumatoria=sumar(numero1,numero2);
                printf("la suma es: %d \n",sumatoria);
            }
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la resta puesto que no se ha ingresado los numeros\n");
            }
            else
            {
                resta=restar(numero1,numero2);
                printf("la resta es: %d \n",resta);
            }
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la division puesto que no se ha ingresado los numeros\n");
            }
            else
            {
                if(numero2==0)
                {
                    printf("no se puede dividir por cero.\n");
                }
                else
                {
                    division=dividir(numero1,numero2);
                    printf("la division es: %f \n",division);
                }
            }
            if(flag1==0||flag2==0)
            {
                printf("no se puede realizar la multiplicacion puesto que no se ha ingresado los numeros\n");
            }
            else
            {
                multiplicacion=multiplicar(numero1,numero2);
                printf("la multiplicacion es: %d \n",multiplicacion);
            }
            if (flag1==0)
            {
                printf("no se puede obtener el factorial puesto que no ingreso un numero.\n");
            }
            else
            {
               resultFactorial=factorialEntero(num1EsEntero,numero1);
               printf("\nEl factorial  de %f es: %lld \n",numero1,resultFactorial);

            }

            system("pause");
            system("cls");

            break;
        case 9:
            printf("Hasta luego!\n");
            seguir = 'n';
            break;
        }


    }
    return 0;
}
