#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
/** \brief inicializa un comentario
 *
 * \return devuelve un eComentario inicializado
 *
 */

eComentario initComment()
{
    eComentario auxcomentario;
    auxcomentario.idComentario = 0;
    auxcomentario.meGusta = 0;
    strcpy(auxcomentario.texto, "empty"),
    auxcomentario.isEmpty = 1;

    return auxcomentario;
}
/** \brief inicializa el array de estructuras
 *
 * \param eUsuarios* pUsuario puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve [-1] si no lo pudo inicializar (pUsuario == NULL o length < 0)
 *         y [0] si esta ok
 */

int initArray(eUsuarios* pUsuario, int length)
{
    int retorno = -1;
    int i;

    if(pUsuario != NULL && length> 0)
    {
        for(i=0;i<length;i++)
        {
            pUsuario[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief crea un menu segun los parametros pasados por el usuario
 *
 * \param char textomenu[] Es la cadena que sirve como menu a ser mostrado
 * \param char min valor minimo que puede tomar el menu
 * \param char min valor maximo que puede tomar el menu
 * \return la opcion elegida por el usuario segun los parametros min y max
 *
 */



char mostrarMenu( char textomenu[], char min, char max )
{
    char opcion ='|';
    int flagPrimera = 1;


    do
    {
        if((opcion < min || opcion > max) && flagPrimera != 1)
        {
            printf("ERROR: reingrese\n");
        }
        printf("%s", textomenu);
        fflush(stdin);
        scanf("%c",&opcion);
        flagPrimera = 0;
    }while(opcion < min || opcion > max);
    return opcion;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param length la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibre(eUsuarios lista[],int length)
{
    int index = -1;
    int i;

    for(i= 0; i<length; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}


/** \brief busca en lista[] el nick pasado por parametro
 *
 * \param eUsuarios lista[]
 * \param int length
 * \param char nick[]
 * \return devuelve el indice donde lo encontro o [-1] si no lo encontro
 *
 */

int buscarPorNick(eUsuarios lista[], int length, char nick[])
{
    int i;
    int index = -1;
    for(i=0;i<length; i++)
    {
        if((strcmp(lista[i].nick, nick) == 0))
        {
            index = i;
            break;
        }
    }
    return index;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {

            strcpy(input, auxChar);
            return 0;


    }


    printf("%s", eMessage);
    return -1;
}


/**
* \brief Solicita una cadena de caracteres de solo letras y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int flagName = 1;
    int i;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        for(i= 0; i< strlen(auxChar); i ++)
        {
            auxChar[i] = tolower(auxChar[i]);
            if(auxChar[i] < 'a' || auxChar[i] >'z')
            {
                flagName = 0;
                break;
            }
        }
    }
    else
    {
        flagName = 0;
    }
    if(flagName)
    {
        auxChar[0] = toupper(auxChar[0]);
        strcpy(input, auxChar);
        return 0;
    }

    system("cls");
    printf("%s", eMessage);
    return -1;
}


/**
* \brief Solicita email y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getEmail(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int i;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        for(i = 0; i<strlen(auxChar); i++)
        {
            if(auxChar[i] == '@')
            {
                strcpy(input, auxChar);
                return 0;
            }
        }
    }
    printf("%s", eMessage);
    return -1;
}


/** \brief le solicita datos al usuario
 *
 * \param lista[] lugar donde recorre los indices
 * \param int lenght tamaño del array
 * \param char* nombre dato pedido al usuario
 * \param char* nick dato pedido al usuario
 * \param char* claveAcceso dato pedido al usuario
 * \param char* email dato pedido al usuario
 * \param int pedirNick si es [1] le pide el nick al usuariom si es [0] no se lo pide
 * \return
 *
 */



void pedirDatos(eUsuarios lista[], int length, char* nombre,char* nick, char* claveAcceso,char* email, int pedirNick)
{
    char auxNombre[30];
    char auxNick[30];
    char auxClaveAcceso[30];
    char auxEmail[50];
    int auxInt;
    int auxIndice;

    do
    {
        auxInt = getName(auxNombre, "Ingrese su nombre: ", "ERROR: Maximo 30 caracteres y solo letras\n", 2, 30);
    }while(auxInt!=0);
    strcpy(nombre, auxNombre);
    system("cls");

    if(pedirNick)
    {

        do
        {
            auxInt = getString(auxNick,"Ingrese su nick: ", "ERROR: solo se permiten hasta 30 caracteres\n", 1,30);
            auxIndice = buscarPorNick(lista, length, auxNick);
            if(auxIndice == -1)
            {
                strcpy(nick, auxNick);
            }
            else
            {
                printf("Ya existe alguien con ese nick!\n");
                auxInt = -1;
            }

        }while(auxInt!=0);

        system("cls");
    }

    do
    {
        auxInt = getString(auxClaveAcceso, "Ingrese su clave: ", "ERROR: Maximo 30 caracteres \n", 2, 30);
    }while(auxInt!=0);
    strcpy(claveAcceso, auxClaveAcceso);
    system("cls");

    do
    {
        auxInt = getEmail(auxEmail, "Ingrese su email: ", "ERROR: Maximo 30 caracteres \n", 2, 30);
    }while(auxInt!=0);
    strcpy(email, auxEmail);
    system("cls");

}

/** \brief carga los datos del usuario ena variable eUsuarios
 *
 * \param char nombre[] dato solicitado al usuairo
 * \param char nick[] dato solicitado al usuario
 * \param char claveAcceso dato solicitado al usuario
 * \param char email dato solicitado al usuario
 * \return devuelve una variable eUsuario cargada
 *
 */


eUsuarios cargarUsuario(char nombre[], char nick[], char claveAcceso[], char email[])
{
    eUsuarios auxUsuario;

    strcpy(auxUsuario.nombre, nombre);
    strcpy(auxUsuario.nick, nick);
    strcpy(auxUsuario.claveAcceso, claveAcceso);
    strcpy(auxUsuario.email, email);
    auxUsuario.isEmpty = 0;

    return auxUsuario;
}


/** \brief Carga un usuario al array de estructuras
 *
 * \param eUsuario lista[] lugar donde carga el usuario
 * \param int length tamaño del array
 * \param int indice lugar donde se carga el usuario nuevo
 * \return
 *
 */

void agregarUsuario(eUsuarios lista[],int length, int indice, int lengthComment)
{

    char nombre[30];
    char nick[30];
    char claveAcceso[30];
    char email[30];
    int i;
    eComentario auxComentario;
    if(indice != -1)
        {
            pedirDatos(lista, length, nombre, nick, claveAcceso, email, 1);
            lista[indice] = cargarUsuario(nombre, nick,claveAcceso,email);
            auxComentario = initComment();
            for(i= 0;i<lengthComment; i++)
            {
                lista[indice].misComentarios[i] = auxComentario;
            }
            printf("Usuario Cargado!\n");
        }
        else
        {
            printf("No hay mas lugar\n");
        }
}


/** \brief Indica si existe algun producto cargado
 *
 * \param puntero lista[] lugar donde va a iterar la funcion
 * \param int length tamaño maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun producto cargado o
 *         [0] si esta cargado con aunque sea un producto
 */
int isEmpty(eUsuarios lista[], int length)
{
    int i;
    int retorno = 1;
    for(i= 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

/** \brief modifica a un usuario segun su nick
 *
 * \param eUsuarios lista[] lugar donde busca al usuario
 * \param int length tamaño total del array de estructuras
 * \return nada, modifica un usuario
 *
 */
void modificar(eUsuarios lista[],int length)
{
    char nombre[30];
    char nick[30];
    char claveAcceso[30];
    char email[30];
    int indice;
    int auxInt;
    auxInt = getString(nick, "Ingrese su nick: ", "ERROR: solo se permite 30 caracteres", 1, 30);
    if(auxInt == 0)
    {
        indice = buscarPorNick(lista, length, nick);
        if(indice!= -1)
        {
                pedirDatos(lista, length, nombre, nick,claveAcceso,email, 0);
                lista[indice] = cargarUsuario(nombre,nick,claveAcceso, email);
                printf("Usuario modificado!\n");
        }
        else
        {
            printf("No existe ningun usuario con ese nick!\n");
        }
    }
}

/** \brief borra a un usuario segun su nick
 *
 * \param eUsuarios lista[] lugar donde busca al usuario
 * \param int length tamaño total del array de estructuras
 * \return nada, borra un usuario
 *
 */


void borrar(eUsuarios lista[], int length)
{
    char auxNick[30];
    int auxInt;
    int indice;
    auxInt = getString(auxNick, "Ingrese el nick del usuario a borrar: ", "ERROR: Maximo 30 caracteres\n", 1, 30);
    if(auxInt== 0)
    {
        indice = buscarPorNick(lista, length, auxNick);
        if(indice != -1)
        {
            lista[indice].isEmpty = 1;
        }
        else
        {
            printf("No existe ningun producto con ese codigo\n!");
        }
    }
}

int ultimoComentario(eUsuarios lista[], int length, int lengthComment)
{
    int i,j;
    int idUltimoComentario= 0;

    for(i=0;i<length;i++)
    {
        if(lista[i].isEmpty == 0)
        {
            for(j=0;j<lengthComment;j++)
            {
                if(lista[i].misComentarios[j].idComentario >idUltimoComentario)
                {
                    idUltimoComentario = lista[i].misComentarios[j].idComentario ;
                }
            }
        }
    }
    return idUltimoComentario;
}


int buscarPorClaveAcceso(eUsuarios lista[], int length, char claveAcceso[])
{
    int i;
    int index = -1;
    for(i=0;i<length; i++)
    {
        if((strcmp(lista[i].claveAcceso, claveAcceso) == 0))
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief loguea al usuario
 *
 * \param eUsuarios lista[] estructura donde valida al usuario y contraseña
 * \param puntero nick del usuario
 * \param int length tamaño del array de estructura
 * \return [1] si se pudo loguear el usuario [0], si no se pudo loguear
 *
 */

int ingresar(eUsuarios lista[], char *nick, int length) // OK
{
    int auxInt[2];
    char auxNick[30];
    char auxClaveAcceso[30];
    int indiceNick;
    int login = 0;
    int intentos = 3;
    do
    {

        auxInt[0] = getString(auxNick, "Ingrese su nick: ", "ERROR: Maximo 30 caracteres", 1, 30);
        if(auxInt[0] ==0)
        {
            auxInt[1] = getString(auxClaveAcceso, "Ingrese su clave: ","ERROR: Maximo 30 caracteres", 1, 30);
            if(auxInt[1]==0)
            {
                indiceNick = buscarPorNick(lista, length, auxNick);
                if(lista[indiceNick].claveAcceso == auxClaveAcceso)
                {
                    login = 1;
                }

            }
        }
        intentos = intentos -1;

    }while(login != 0 && intentos != 0);

    if(intentos == 0)
    {
        return 0;
    }
    else
    {
        strcpy(nick, auxNick);
        return 1;
    }

}


/**
 * Obtiene el primer indice libre del array de estructura anidada
 * @param lista el array se pasa como parametro.
 * @param int obtenerEspacioLibreComentario(eUsuarios lista[],int lengthComment, char nick[])length la cantidad total de items
 * @param char nick[] el nick donde se busca el primer comentario libre
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibreComentario(eUsuarios lista[],int length,int lengthComment, char nick[])
{
    int index = -1;
    int i;
    int indice;

    indice = buscarPorNick(lista,length,nick);
    printf("Indice: %d", indice);

    for(i= 0; i<lengthComment; i++)
    {
        printf("isEmpty: %d\n",lista[indice].misComentarios[i].isEmpty);
        if(lista[indice].misComentarios[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}



/** \brief carga los datos de un comentario
 *
 * \param int idUltimoComentario el id del ultimo comentario
 * \return una variable eComentario cargada
 *
 */


eComentario cargarComentario(int idUltimoComentario)
{
    int auxInt;
    char comentarioTexto[30];
    eComentario unComentario;
    do
    {
        auxInt = getString(comentarioTexto, "Ingrese su comentario:\n\t", "ERROR: Maximo 50 caracteres", 1, 50);
    }while(auxInt!=0);

    unComentario.idComentario = idUltimoComentario +1;
    unComentario.meGusta = 0;
    unComentario.isEmpty = 0;
    strcpy(unComentario.texto, comentarioTexto);

    return unComentario;
}

/** \brief solicita un usuario, su clave y un comentario para agregar
 *
 * \param eUsuarios lista[] array donde busca al usuario y su clave
 * \param int length tamaño total del array
 * \param int lengthComment tamaño total del array comentarios
* \return
 *
 */


void agregarComentario(eUsuarios lista[], int length, int lengthComment)
{
    int idUltimoComentario;
    char auxNick[30];
    int auxInt;
    int indiceNick;
    int indiceComentario;
    eComentario auxComentario;

    idUltimoComentario = ultimoComentario(lista, length, lengthComment);
    auxInt = ingresar(lista, auxNick, length);
    if(auxInt)
    {
        indiceNick =buscarPorNick(lista, length, auxNick);
        indiceComentario = obtenerEspacioLibreComentario(lista,length, lengthComment, auxNick);
        if(indiceComentario!=-1)
        {
            auxComentario = cargarComentario(idUltimoComentario);
            lista[indiceNick].misComentarios[indiceComentario] = auxComentario;
            printf("Comentarios agregado!\n");
        }
        else
        {
            printf("No hay mas lugar para comentarios!\n");
        }
    }
}

