typedef struct{
    int idComentario;
    char texto[50];
    int meGusta;
    int isEmpty;
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
eUsuarios cargarUsuario(char nombre[], char nick[], char claveAcceso[], char email[]);
void agregarUsuario(eUsuarios lista[],int length, int indice);
int isEmpty(eUsuarios lista[], int length);
void modificar(eUsuarios lista[],int length);
void borrar(eUsuarios lista[], int length);
int buscarPorClaveAcceso(eUsuarios lista[], int length, char claveAcceso[]);
int ingresar(eUsuarios lista[], int length, char* nick);
int UltimoComentario(eUsuarios lista[], int length);
