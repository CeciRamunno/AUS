# define MAX_LINE = 11 // max caract por linea (voto + legislador)

typedef struct nodo
{
    char voto;
    char nombre[10];
}legislador;

void insertar();

void suprimir(legislador, char);

int esMiembro(legislador, char);

void mostrar(FILE*);
