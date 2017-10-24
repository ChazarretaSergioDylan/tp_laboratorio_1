#include "funcionestp3.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 50

void only_Menu()
{
    printf("\n[1] Agregar pelicula\n");
    printf("[2] Borrar pelicula\n");
    printf("[3] Modificar pelicula\n");
    printf("[4] Generar pagina web\n");
    printf("[5] Salir\n\n");
}

void iniciar_Pelis()
{
    int i;
    for(i=0; i<T; i++)
    {
        movies[i].estado=0;
    }
}


void agregar_Pelicula(contador_dePelis)
{
    char    auxiliar[60];

    printf("Ingrese el titulo\n");
    fflush(stdin);
    scanf("%s",movies[contador_dePelis].titulo);

    printf("Ingrese el genero\n");
    fflush(stdin);
    scanf("%s",movies[contador_dePelis].genero);

    printf("Ingrese duracion\n");
    fflush(stdin);
    scanf("%s",auxiliar);
    movies[contador_dePelis].duracion = validarNumero(auxiliar);

    printf("Ingrese la descripcion:\n");
    fflush(stdin);
    scanf("%s",movies[contador_dePelis].descripcion);

    printf("Ingrese puntaje\n");
    fflush(stdin);
    scanf("%s",auxiliar);
    movies[contador_dePelis].puntaje = validarNumero(auxiliar);

    printf("Ingrese link de la imagen\n");
    fflush(stdin);
    scanf("%s",movies[contador_dePelis].link);

    movies[contador_dePelis].estado = 1;

    printf("La peli se guardo en la posicion: %d\n\n",contador_dePelis);

}

void borrar_Pelicula(contador_dePelis)
{
    char auxiliar[20], respuesta;
    int i, flag_antiRepeticiones=0;

    system("cls");

    lista_dePelis(contador_dePelis);

    printf("\n\nIngrese el titulo de la pelicula a borrar: (Respete mayusculas y minusculas)\n");
    fflush(stdin);
    scanf("%s",auxiliar);

    for(i=0; i<contador_dePelis; i++)
    {

        if(strcmp(auxiliar,movies[i].titulo)==0)
        {
            flag_antiRepeticiones=1;
            printf("Esta seguro de borrar la pelicula %s ? (s/n) \n",auxiliar);
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {
                movies[i].estado=0;
            }
            else
            {
                break;
            }
        }
    }

    if(flag_antiRepeticiones==0)
    {
        printf("No se encontraron coincidencias\n");
    }
}

void modificar_Pelicula(contador_dePelis)
{

    char auxiliar_title[60], respuesta;
    char    auxiliar[60];
    int i, flag_antiRepeticiones=0;

    system("cls");

    lista_dePelis(contador_dePelis);

    printf("\n\nIngrese el titulo de la pelicula a modificar: (Respete mayusculas y minusculas)\n");
    fflush(stdin);
    scanf("%s",auxiliar_title);

    for(i=0; i<contador_dePelis; i++)
    {

        if(strcmp(auxiliar_title,movies[i].titulo)==0)
        {
            flag_antiRepeticiones=1;
            printf("Esta seguro de borrar la pelicula %s ? (s/n) \n",auxiliar_title);
            fflush(stdin);
            scanf("%c",&respuesta);

            if(respuesta=='s')
            {

                printf("Ingrese el titulo\n");
                fflush(stdin);
                scanf("%s",movies[i].titulo);

                printf("Ingrese el genero\n");
                fflush(stdin);
                scanf("%s",movies[i].genero);

                printf("Ingrese duracion\n");
                fflush(stdin);
                scanf("%s",auxiliar);
                movies[i].duracion = validarNumero(auxiliar);

                printf("Ingrese la descripcion:\n");
                fflush(stdin);
                scanf("%s",movies[i].descripcion);

                printf("Ingrese puntaje\n");
                fflush(stdin);
                scanf("%s",auxiliar);
                movies[i].puntaje = validarNumero(auxiliar);

                printf("Ingrese link de la imagen\n");
                fflush(stdin);
                scanf("%s",movies[i].link);

                printf("La peli se modifico en la posicion: %d\n\n",i);

            }
            else
            {
                break;
            }
        }
    }

    if(flag_antiRepeticiones==0)
    {
        printf("No se encontraron coincidencias\n");
    }
}


void generar_Peliculas(contador_dePelis)
{

    int i;

    FILE* miarchivo=NULL;
    char* peliculas = "web//test1.html";

    miarchivo= fopen(peliculas, "w");
    if(miarchivo == NULL)return-1;

    fprintf(miarchivo,"<!DOCTYPE html><html lang='es'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='header'>Netflix economico v0.04</div><div class='container'><div class='row'>");

    for(i=0; i<contador_dePelis; i++)
    {

        if(movies[i].estado==1)
        {
            fprintf(miarchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>",movies[i].link);

            fprintf(miarchivo, "<h3><a href='#'>%s</a></h3>",movies[i].titulo);

            fprintf(miarchivo,"<ul><li>Género: %s</li>",movies[i].genero);

            fprintf(miarchivo,"<li>Puntaje: %d</li>",movies[i].puntaje);

            fprintf(miarchivo,"<li>Duración: %d</li></ul>",movies[i].duracion);

            fprintf(miarchivo,"<p>%s</p></article>",movies[i].descripcion);
        }

    }

    fprintf(miarchivo,"</div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fclose(miarchivo);

}


int validarNumero(auxiliar)
{
    int auxiliarEntero, datoFinal;

    auxiliarEntero=atoi(auxiliar);

    while(auxiliarEntero==0)
    {
        printf("Lo ingresado no es un numero!, intente nuevamente por favor.\n",auxiliarEntero);
        scanf("%s",auxiliar);
        auxiliarEntero=atoi(auxiliar);
    }

    return datoFinal = auxiliarEntero;
}

void lista_dePelis(contador_dePelis)
{
    int i;

    for(i=0; i<contador_dePelis; i++)
    {
        if(movies[i].estado==1)
        {
            printf("Titulo:\t\t %s\n",&movies[i].titulo);
        }
    }

}
