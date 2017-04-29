#include<conio.h>
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include "funcionestp2.h"

void refrescarPantalla()
{
    system("pause");
    system("cls");

}


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
    for(i=0;i<tam;i++)
    {
        indiv[i].estado=0;
    }

}
void ordenarPersona(eIndividuo indiv[],int tam )
{
    int i,j;
    eIndividuo auxiliarIndiv;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
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
    for(i=0;i<tam;i++)
    {
        if(individuos[i].estado!=0)
        {
            mostrarGente(individuos[i]);
        }
    }
}
void mostrarGente(eIndividuo indiv)
{
    printf("\n dni: %d\tnombre: %s\tedad:%d\n",indiv.dni,indiv.nombre,indiv.edad);
}
int  buscarEspacio(eIndividuo indiv[],int tam)
{
    int lugar=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(indiv[i].estado==0)
        {
            lugar=i;
            break;
        }
    }
    return lugar;
}
eGrafico crearGraf(int edad)
{
    eGrafico graf;
    graf.edad=edad;
}
void grafico(eGrafico graf[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(graf[i].edad<19)
        {
            printf("*\t \t \n");
        }
        else
        {
           if(graf[i].edad>35)
           {
               printf(" \t \t*\n");
           }
           else
           {
               printf(" \t*\t \n");
           }

        }
    }
}
