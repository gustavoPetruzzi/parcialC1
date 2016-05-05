typedef struct{
    int idComentario;
    char texto[50];
    int meGusta;
}eComentario;
typedef struct{
    char nombre[30];
    char nick[30];
    char claveAcceso[30];
    char email[30];
    eComentario misComentarios[50];
    int isEmpty;
}eUsuarios;

int initArray(eUsuarios* pUsuario, int length);
char mostrarMenu( char textomenu[], char min, char max );
int obtenerEspacioLibre(eUsuarios lista[],int length);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
void pedirDatos(eUsuarios lista[], int length, char* nombre,char* nick, char* claveAcceso,char* email, int pedirNick);
int buscarPorNick(eUsuarios lista[], int length, char nick[]);
void agregarProducto(eUsuarios lista[],int length, int indice);
