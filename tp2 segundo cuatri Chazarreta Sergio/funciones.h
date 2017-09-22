
typedef struct
{
    char nombre[40];
    int estado;
    int edad;
    int dni;
} eIndividuo;
/** \brief inicializa estado y edad a valores ilogicos
 *
 * \param array de tipo eIndividuo a inicializar
 * \param tamaño del array de tipo eIndividuo
 * \return sin retorno
 *
 */
void inicializarIndiv(eIndividuo[],int);
/** \brief  crea una estructura de tipo eIndividuo
 *
 * \param valor de tipo char[] para nombre
 * \param valor de tipo int para edad
 * \param valor de tipo int para dni
 * \return estructura de tipo eIndividuo
 *
 */
eIndividuo crearIndividuo(char[],int,int);
/** \brief muestra los individuos actualmente cargados y en alta
 *
 * \param array de eIndividuo
 * \param tamaño del array de tipo eIndividuo
 * \return sin retorno
 *
 */
void mostrarPersona(eIndividuo[],int);
/** \brief muestra los datos: dni,nombre,edad de un eIndividuo
 *
 * \param valor de tipo eIndividuo
 * \return sin retorno
 *
 */
void mostrarGente(eIndividuo);
/** \brief ordena el array de tipo eIndividuo alfabeticamente
 *
 * \param array de tipo eIndividuo
 * \param tamaño del array de tipo eIndividuo
 * \return sin retorno
 *
 */
void ordenarPersona(eIndividuo[],int);
/** \brief busca lugar en el array de tipo eIndividuo
 *
 * \param array de tipo eIndividuo
 * \param tamaño del array de tipo eIndividuo
 * \return vaor de tipo int siendo -1 si no encuentra lugar,
           o la primer posicion disponible comenzando en 0 hasta tamaño-1
 *
 */
int buscarEspacio(eIndividuo[],int);
/** \brief imprime un grafico de edades para <19;19-35;35<
 *
 * \param array de tipo eIndividuo
 * \param tamaño del array de tipo eIndividuo
 * \return sin retorno
 *
 */
void grafico(eIndividuo [], int );
/** \brief pide un valor de tipo entero entre un maximo y un minimo
 *
 * \param valor de tipo char[] en el que se da el mensaje sobre que se pide
 * \param valor de tipo int asignado como menor numero valido
 * \param valor de tipo int asignado como mayor numero valido
 * \return valor de tipo int validado.
 *
 */
int pedirEnteroConRango(char [],int, int);
/** \brief convierte un char[] a entero(previamente verificado si es posible la conversion)
 *
 * \param valor de tipo char[] a convertir a int
 * \return valor de tipo int con el contenido del char[] cargado
 *
 */
int convertirCharEntero(char[]);
/** \brief verifica si lo ingresado es int, float o char[](ni float ni int)
 *
 * \param valor de tipo char con el numero ingresado
 * \return valor de tipo int siendo 1 para int, 2 para float, 0 para char[](ni float ni int)
 *
 */
int verificar_numero(char numero[]);
/** \brief verifica si un int esta dentro del rango deseado
 *
 * \param valor de tipo int siendo el menor numero valido
 * \param valor de tipo int siendo el mayor numero valido
 * \param valor de tipo int siendo el numero a verificar
 * \return valor de tipo int siendo 1 si no esta dentro del rango y 0 si esta dentro del rango.
 *
 */
int rango_valido (int ,int ,int );

