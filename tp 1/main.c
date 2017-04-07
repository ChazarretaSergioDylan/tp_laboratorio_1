#include <stdio.h>
#include "funciones.h"
#include <stdlib.h>

int main()
{
    char seguir='s';
    int opcion=0;
    int num1;
    int num2;

    int sumatoria;
    int resta;
    float division;
    int multiplicacion;
    int i;
    int resultFactorial=1;
    int flagA=0;
    int flagB=0;
    while(seguir=='s')
    {
        if(flagA==0)
        {
        printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
        printf("1- Ingresar 1er operando (A=%d)\n",num1);
        }
        if(flagB==0)
        {
        printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n",num2);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("ingrese el primer numero: \n");
            scanf("%d",&num1);
            printf("el numero es %d \n",num1);
            flagA=1;
            refrescarPantalla();
            break;
        case 2:
            printf("ingrese el segundo numero: \n");
            scanf("%d",&num2);
            printf("el numero es %d \n",num2);
            flagB=1;
            refrescarPantalla();
            break;
        case 3:
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la suma puesto que no se ha ingresado los numeros \n");
            }
            else
            {
            sumatoria=sumar(num1,num2);
            printf("la suma es: %d \n",sumatoria);
            }
            refrescarPantalla();
            break;
        case 4:
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la resta puesto que no se ha ingresado los numeros \n");
            }
            else
            {
            resta=restar(num1,num2);
            printf("la resta es: %d \n",resta);
            }
            refrescarPantalla();
            break;
        case 5:
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la division puesto que no se ha ingresado los numeros \n");
            }
            else
            {
            if(num2==0)
            {
                printf("no se puede dividir por cero.\n");
            }
            else
            {
            division=dividir(num1,num2);
            printf("la division es: %f \n",division);
            }
            }
            refrescarPantalla();
            break;
        case 6:
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la multiplicacion puesto que no se ha ingresado los numeros \n");
            }
            else
            {
            multiplicacion=multiplicar(num1,num2);
            printf("la multiplicacion es: %d \n",multiplicacion);
            }
            refrescarPantalla();
            break;
        case 7:
            if (flagA==0)
                {
                    printf("no se puede obtener el factorial puesto que no ingreso un numero.");
                }
            else
            {
            if(num1<0||num1>12)
            {
             printf("no se puede sacar el factorial.\nIngrese un numero entre 0 y 12\n");
            }
            else
            {
                for(i=num1;i>0;i--)
            {
                resultFactorial=resultFactorial*i;
            }
            printf("el factorial de %d es: %d \n",num1,resultFactorial);
            resultFactorial=1;
            }
            }
            refrescarPantalla();
            break;
        case 8:
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la suma puesto que no se ha ingresado los numeros \n");
            }
            else
            {
            sumatoria=sumar(num1,num2);
            printf("la suma es: %d \n",sumatoria);
            }
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la resta puesto que no se ha ingresado los numeros\n");
            }
            else
            {
            resta=restar(num1,num2);
            printf("la resta es: %d \n",resta);
            }
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la division puesto que no se ha ingresado los numeros\n");
            }
            else
            {
            if(num2==0)
            {
                printf("no se puede dividir por cero.\n");
            }
            else
            {
            division=dividir(num1,num2);
            printf("la division es: %f \n",division);
            }
            }
            if(flagA==0||flagB==0)
            {
            printf("no se puede realizar la multiplicacion puesto que no se ha ingresado los numeros\n");
            }
            else
            {
            multiplicacion=multiplicar(num1,num2);
            printf("la multiplicacion es: %d \n",multiplicacion);
            }
            if (flagA==0)
                {
                    printf("no se puede obtener el factorial puesto que no ingreso un numero.");
                }
            else
            {
            if(num1<0||num1>12)
            {
             printf("no se puede sacar %d !.\nIngrese un numero entre 0 y 12\n",num1);
            }
            else
            {
                for(i=num1;i>0;i--)
            {
                resultFactorial=resultFactorial*i;
            }
            printf("el factorial de %d es: %d \n",num1,resultFactorial);
            resultFactorial=1;
            }
            }

            break;
        case 9:
            printf("Hasta luego!\n");
            seguir = 'n';
            break;
        }


    }
    return 0;
}
