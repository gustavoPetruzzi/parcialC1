#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAX 100
int main()
{
    int init;
    char opcion;
    int indice;
    eUsuarios misUsuarios[100];


    init = initArray(misUsuarios, MAX);
    if(init == 0)
    {
        do
        {
            opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-NUEVO COMENTARIO\n5-NUEVO ME GUSTA\n6-INFORMAR\n7-LISTAR\n8-SALIR", '1', '8');
            switch(opcion)
            {
                case '1':
                    indice = obtenerEspacioLibre(misUsuarios, MAX);
                    if(indice!= -1)
                    {
                        agregarProducto(misUsuarios, MAX, indice);
                    }
                    system("pause");
                    system("cls");
                    break;
                case '2':
                    break;
                case '3':
                    break;
                case '4':
                    break;
                case '5':
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
