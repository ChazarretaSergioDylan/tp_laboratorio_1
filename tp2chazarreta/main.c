#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funcionestp2.h"
#define C 20
int main()
{
    eIndividuo gente[C];
    eGrafico grafico[C];
    inicializarIndiv(gente,C);
    char seguir='s';
    int opcion,posicion,flagCapacidad,auxInt;
    char nombre[30],respuesta;
    int dni, edad;




    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            flagCapacidad=0;
            posicion= buscarEspacio(gente,C);
            if(posicion!=-1)
            {
                printf("1.Agregar persona:\n");
             printf("Ingrese DNI: \n");
             scanf("%d",&dni);
             printf("Ingrese nombre\n");
           fflush(stdin);
           gets(nombre);
            printf("Ingrese edad: \n");
            scanf("%d",&edad);

            gente[posicion]=crearIndividuo(nombre,edad,dni);
            mostrarGente(gente[posicion]);
            refrescarPantalla();
             }
             else
                {
                printf("no hay espacio para mas personas.\n");
                refrescarPantalla();
                }
             break;
            case 2:
                flagCapacidad=0;
                printf("ingrese dni de la persona que desea dar de baja: \n");
                scanf("%d",&auxInt);
                int i;
                for(i=0; i<C; i++)
            {
                if(gente[i].estado==1 &&auxInt == gente[i].dni)
                {

                    mostrarGente(gente[i]);

                    printf("Esta seguro de dar de baja? s/n\n");
                    respuesta = getche();
                    if(respuesta=='s'&&flagCapacidad==0)
                    {
                        gente[i].estado=0;
                        printf("dado de baja exitoso.\n");
                        refrescarPantalla();
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario.\n");
                        refrescarPantalla();
                    }
                   flagCapacidad=1;
                break;
                }
            }
                break;
            case 3:
            ordenarPersona(gente,C);
            mostrarPersona(gente,C);
                break;
            case 4:
               /* grafico[posicion]=crearGraf(edad);
                grafico(grafico[posicion],C);
                *///no funciona.
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
