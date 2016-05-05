#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 100
int main()
{
    int init;
    char opcion;
    int indice;
    int resultIsEmpty;
    int auxInt;
    char auxNick[30];
    eUsuarios misUsuarios[100];


    init = initArray(misUsuarios, MAX);
    if(init == 0)
    {
        do
        {
            opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-NUEVO COMENTARIO\n5-NUEVO ME GUSTA\n6-INFORMAR\n7-LISTAR\n8-SALIR", '1', '8');
            system("cls");
            switch(opcion)
            {
                case '1':
                    indice = obtenerEspacioLibre(misUsuarios, MAX);
                    if(indice!= -1)
                    {
                        agregarUsuario(misUsuarios, MAX, indice);
                    }
                    system("pause");
                    system("cls");
                    break;
                case '2':
                    resultIsEmpty = isEmpty(misUsuarios, MAX);
                    if(resultIsEmpty == 0)
                    {
                       modificar(misUsuarios, MAX);
                    }
                    else
                    {
                        printf("no hay ningun usuario cargado\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '3':
                    resultIsEmpty = isEmpty(misUsuarios, MAX);
                    if(resultIsEmpty == 0)
                    {
                        borrar(misUsuarios, MAX);
                    }
                    else
                    {
                        printf("no hay ningun usuario cargado\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '4':
                    resultIsEmpty = isEmpty(misUsuarios, MAX);
                    if(resultIsEmpty == 0)
                    {
                        auxInt = ingresar(misUsuarios, MAX, auxNick);
                        if(auxInt)
                        {
                            printf("ADENTRO!");
                            printf("%s", auxNick);
                        }
                        else
                        {
                            printf("NO ENTRO!");
                        }
                    }
                    else
                    {
                        printf("No hay nada cargado!");
                    }
                    break;
                case '5':
                    resultIsEmpty = isEmpty(misUsuarios, MAX);
                    if(resultIsEmpty == 0)
                    {
                        printf("ACA TAMPOCO");
                    }
                    break;
                case '6':
                    break;
                case '7':
                    break;
                case '8':
                    break;
            }
        }while(opcion != '8');
    }
    return 0;
}
