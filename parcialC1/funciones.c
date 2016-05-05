
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"


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
    printf("%s", message);
    fflush(stdin);
    gets(auxChar);
    if(strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit )
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
                printf("Ya existe alguien con ese nick!");
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
        auxInt = getString(auxEmail, "Ingrese su email: ", "ERROR: Maximo 30 caracteres \n", 2, 30);
    }while(auxInt!=0);
    strcpy(email, auxEmail);
    system("cls");

}


eUsuarios cargarProducto(char nombre[], char nick[], char claveAcceso[], char email[])
{
    eUsuarios auxUsuario;

    strcpy(auxUsuario.nombre, nombre);
    strcpy(auxUsuario.nick, nick);
    strcpy(auxUsuario.claveAcceso, claveAcceso);
    strcpy(auxUsuario.email, email);
    auxUsuario.isEmpty = 0;

    return auxUsuario;
}

void agregarProducto(eUsuarios lista[],int length, int indice)
{

    char nombre[30];
    char nick[30];
    char claveAcceso[30];
    char email[30];
    if(indice != -1)
        {
            pedirDatos(lista, length, nombre, nick, claveAcceso, email, 1);
            lista[indice] = cargarProducto(nombre, nick,claveAcceso,email);
            printf("Usuario Cargado!");
        }
        else
        {
            printf("No hay mas lugar\n");
        }
}
