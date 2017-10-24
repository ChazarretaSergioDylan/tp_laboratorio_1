#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funcionestp3.h"
#define T 50

int main()
{
    int     opcion, salir=0, contador_dePelis=0, flag=0;
    iniciar_Pelis();

    do
    {
        only_Menu();

        printf("\nSeleccione una opcion porfavor...\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("[1] Agregar pelicula:\n");

            if(T>contador_dePelis)
            {

                printf("Espacio libre para añadir una pelicula\n");

                agregar_Pelicula(contador_dePelis);

                contador_dePelis++;

                flag=1;

            }
            else
            {
                printf("Lo sentimos, pero no hay mas espacio disponible\n");
            }

            break;

        case 2:
            if(!(flag!=1))
            {
                system("cls");
                printf("Borrar pelicula\n");
                borrar_Pelicula(contador_dePelis);
            }
            else
            {
                system("cls");
                printf("Ups, no podemos borrar si no hay nada agregado\n");
            }
            break;

        case 3:
            if(!(flag!=1))
            {
                system("cls");
                printf("Modificar pelicula\n");
                modificar_Pelicula(contador_dePelis);
            }
            else
            {
                system("cls");
                printf("Ups, no podemos modificar si no hay nada agregado\n");
            }
            break;

        case 4:
            generar_Peliculas(contador_dePelis);

            if(!(flag!=1))
            {
                system("cls");
                printf("Generar web\n");
            }
            else
            {
                system("cls");
                printf("No hay datos para generar la pagina web\n");
            }
            break;

        case 5:
            system("cls");
            salir=1;
            printf("Hasta luego \n");
            break;

        default:
            system("cls");
            printf("Opcion incorrecta, vuelva a intentar\n");
            break;
        }

    }
    while(salir==0);


    return 0;
}
