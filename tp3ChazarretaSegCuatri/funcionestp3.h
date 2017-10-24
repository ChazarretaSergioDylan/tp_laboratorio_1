#define T 50

typedef struct{

    char    titulo[20];
    char    genero[20];
    int     duracion;
    char    descripcion[50];
    int     puntaje;
    char    link[200];
    int     estado;

}eMovie;

eMovie movies[T];

/**
 *  Iniciar peliculas
 *  @param Recorre el array de estructura eMovie inicializando a 0 el estado
 *  @return sin retorno
 */
void iniciar_Pelis();

/**
 *  Menu de opciones
 *  @param Imprime el menu de opciones, solamente el menu, por si hay que usarlo en otra funcion
 *  @return vacio
 */
void only_Menu();

/**
 *  Agregar pelicula
 *  @param Toma datos del usuario y lo envia a la estructura, la posicion depende del contador_dePelis
 *  @return vacio
 */
void agregar_Pelicula(contador_dePelis);

/**
 *  Borra peliculas
 *  @param Recorre el array de estructura buscando coincidencia, cuando lo encuentra cambia el estado a 0
 *  @return vacio
 */
void borrar_Pelicula(contador_dePelis);

/**
 *  Listar peliculas
 *  @param Lista las peliculas por nombre, recorriendo con un for la estructura
 *  @return vacio
 */
void lista_dePelis(contador_dePelis);

/**
 *  Modificar pelicula
 *  @param Lista las peliculas por nombre, busca coincidencia, si la encuentra, pide confirmacion, y modifica los datos
 *  @return vacio
 */
void modificar_Pelicula(contador_dePelis);

/**
 *  Generar peliculas
 *  @param Genera el html con las peliculas cargadas
 *  @return vacio
 */
void generar_Peliculas(contador_dePelis);

/**
 *  Validar que el usuario ingrese solo numeros
 *  @param Recibe un auxiliar string, con atoi comprueba que sea un numero
 *  @return el valor del auxiliar
 */
int validarNumero(auxiliar);

