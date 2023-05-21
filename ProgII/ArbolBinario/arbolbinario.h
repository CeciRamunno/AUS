# define long_max 25;

typedef struct nodo
{
    char dato;
    struct nodo *hijoIzq, *hijoDer;
}arbol;

void insertar(arbol**, char);

int esMiembro(arbol*, char);

char suprimirMin(arbol**);

void suprimir(arbol**, char);

void listar(arbol*);

void corroborarMiembro(arbol*, char);
