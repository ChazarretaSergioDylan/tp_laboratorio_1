#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"



eIndividuo crearIndividuo(char nombre[],int edad,int dni)
{
    eIndividuo persona;
    persona.dni=dni;
    persona.edad=edad;
    strcpy(persona.nombre,nombre);
    persona.estado=1;
    return persona;
}



void inicializarIndiv(eIndividuo indiv[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        indiv[i].estado=0;
        indiv[i].edad=-1;
    }

}



void ordenarPersona(eIndividuo indiv[],int tam )
{
    int i,j;
    eIndividuo auxiliarIndiv;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(indiv[i].nombre,indiv[j].nombre)>0)
            {
                auxiliarIndiv=indiv[i];
                indiv[i]=indiv[j];
                indiv[j]=auxiliarIndiv;
            }
        }
    }
}



void mostrarPersona(eIndividuo individuos[],int tam )
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(individuos[i].estado!=0)
        {
            mostrarGente(individuos[i]);
        }
    }
}

/** \brief muestra los datos: dni,nombre,edad de un eIndividuo
 *
 * \param valor de tipo eIndividuo
 * \return sin retorno
 *
 */

void mostrarGente(eIndividuo indiv)
{
    printf("\n dni: %d\tnombre: %s\tedad:%d\n",indiv.dni,indiv.nombre,indiv.edad);
}



int  buscarEspacio(eIndividuo indiv[],int tam)
{
    int lugar=-1;
    int i;
    for(i=0; i<tam; i++)
    {
        if(indiv[i].estado==0)
        {
            lugar=i;
            break;
        }
    }
    return lugar;
}




void grafico(eIndividuo indiv[], int tam)
{
    int i,mayor,flag=0;
    int contador_menor=0;
    int contador_adulto=0;
    int contador_anciano=0;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    for(i=0; i<tam; i++)
    {
        if(indiv[i].edad!=-1)
        {

            if(indiv[i].edad<19)
            {
                contador_menor++;
            }
            else
            {
                if(indiv[i].edad<36)
                {
                    contador_adulto++;
                }
                else
                {
                    contador_anciano++;
                }
            }
        }



    }
    if(contador_menor==0 && contador_adulto==0 && contador_anciano==0)
    {
        printf("\nNo se han ingresado personas.\n");
    }
    else
    {
        if(contador_menor >= contador_adulto && contador_menor >= contador_anciano)
        {
            mayor=contador_menor;
        }
        else
        {
            if(contador_adulto >= contador_menor && contador_adulto >= contador_anciano)
            {
                mayor=contador_adulto;
            }
            else
            {
                mayor=contador_anciano;
            }
        }
        for(i=mayor; i>0; i--)
        {
            if(i<=contador_menor)
            {
                printf("*");
            }
            if(i<=contador_adulto)
            {
                printf("\t*");
                flag=1;
            }
            if(i<=contador_anciano)
            {
                if(flag==0)
                {
                    printf("\t\t*");
                }
                else
                {
                    printf("\t*");
                }
            }
            printf("\n");
        }
        printf("<19\t19-35\t>35\n");

    }
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


}



int pedirEnteroConRango(char textoMenu[],int opcionMenor, int opcionMayor)
{
    int opcion,auxilarVerificacion;
    char textoIngresado[30];
    do
    {
        printf("%s", textoMenu);

        scanf("%s", textoIngresado);

        auxilarVerificacion=verificar_numero(textoIngresado);
       if(auxilarVerificacion!=1)
       {
           printf("\nError!\n");
       }
       else
       {
           opcion=convertirCharEntero(textoIngresado);
           if(rango_valido(opcionMenor,opcionMayor,opcion) ==1)
           {
               auxilarVerificacion=0;
           }
       }


    }
    while(auxilarVerificacion!=1);



    return opcion;
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



int convertirCharEntero(char enteroValidado[])
{
    int numero;
    numero=atoi(enteroValidado);
    return numero;
}



int rango_valido (int menor ,int mayor ,int numero)
{
    if(numero<menor || numero> mayor)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



