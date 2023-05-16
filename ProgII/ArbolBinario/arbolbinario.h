# define long_max 25;

typedef struct nodo
{
    char dato;
    struct nodo *   h_izq, *h_der;
}arbol;

void insertar(arbol**, char);

int esMiembro(arbol*, char);

int suprimirMin(arbol**);

void suprimir(arbol**, char);

void listar(arbol*);

void corroborarMiembro(arbol*, char");
