#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include <ctype.h>
#define C 20




int main()
{
    eIndividuo gente[C];
    inicializarIndiv(gente,C);
    char seguir='s',continuar;
    int opcion,posicion,flagCapacidad,auxInt,flagExiste=0;
    char nombre[30],respuesta;
    int dni, edad;

    while(seguir=='s')
    {

        opcion=pedirEnteroConRango("1.Agregar persona\n2.Borrar persona\n3.Imprimir lista ordenada por  nombre\n4.Imprimir grafico de edades\n5.Salir\nSeleccione una opcion:",1,5);


        switch(opcion)
        {
        case 1:
            flagCapacidad=0;
            posicion= buscarEspacio(gente,C);
            if(posicion!=-1)
            {
                printf("1.Agregar persona:\n");
                do//por si los datos ingresados no son correctos
                {
                    edad=pedirEnteroConRango("\nIngrese edad:",1,100);
                    printf("Ingrese nombre:\n");
                    fflush(stdin);
                    gets(nombre);
                    dni=pedirEnteroConRango("Ingrese dni:\n",10000000,100000000);
                    gente[posicion]=crearIndividuo(nombre,edad,dni);
                    do//por si no ingresa 'n' o 's'
                    {
                        mostrarGente(gente[posicion]);
                        printf("\nSon correctos estos datos?s/n\n");
                        continuar=getche();
                        continuar=tolower(continuar);
                    }
                    while(continuar!='s' && continuar!='n');

                }
                while(continuar=='n');

                system("pause");
                system("cls");
            }
            else
            {
                printf("no hay espacio para mas personas.\n");
                system("pause");
                system("cls");
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

                    flagExiste=1;
                    mostrarGente(gente[i]);

                    printf("Esta seguro de dar de baja? s/n\n");
                    respuesta = getche();
                    if(respuesta=='s'&&flagCapacidad==0)
                    {
                        gente[i].estado=0;
                        gente[i].edad=-1;
                        printf("\nDado de baja exitoso.\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("Accion cancelada por el usuario.\n");
                        system("pause");
                        system("cls");
                    }
                    flagCapacidad=1;
                    break;
                }


            }
            if(flagExiste==0)
            {
                printf("No se encontro el dni.\n");
            }
            break;
        case 3:
            ordenarPersona(gente,C);
            mostrarPersona(gente,C);
            system("pause");
            system("cls");
            break;
        case 4:
            grafico(gente,C);
            system("pause");
            system("cls");

            break;
        case 5:
            printf("Hasta luego!");
            seguir = 'n';
            break;
        }
    }
    return 0;
}

