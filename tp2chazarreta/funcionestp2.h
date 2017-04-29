void refrescarPantalla();

 typedef struct
 {
    char nombre[40];
    int estado;
    int edad;
    int dni;
 }eIndividuo;
void inicializarIndiv(eIndividuo[],int);
eIndividuo crearIndividuo(char[],int,int);
void mostrarPersona(eIndividuo[],int);
void mostrarGente(eIndividuo);
void ordenarPersona(eIndividuo[],int);
int buscarEspacio(eIndividuo[],int);
typedef struct
{
    int edad;
}eGrafico;
eGrafico crearGraf(int);
void grafico(eGrafico[],int);
