#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "arbolbinario.h"

int main ()
{
    arbol* raiz;
    raiz = NULL;

    printf("Armado codigo para probar el arbol.\n");
    insertar(&raiz, 'H');
    insertar(&raiz, 'B');
    insertar(&raiz, 'C');
    insertar(&raiz, 'P');
    insertar(&raiz, 'T');
    insertar(&raiz, 'O');
    insertar(&raiz, 'Q');
    insertar(&raiz, 'M');
    insertar(&raiz, 'Z');

    printf("Listado PRE ORDEN.\n");
    listarPreOrden(raiz);

    corroborarMiembro(raiz, 'A'); // Elemento no existe.
    corroborarMiembro(raiz, 'B'); // Elemento existe.

    return 0;
}

void insertar(arbol **A, char txt)
{
    if (*A == NULL)
    {
        *A = (arbol*)malloc(sizeof(arbol));
        (*A) -> dato = txt;
        printf("Nodo raiz: %c.\n", (*A) -> dato);
        (*A) -> hijoIzq = NULL;
        (*A) -> hijoDer = NULL;
    }
    else // si ya hay un nodo raíz:
    {
        if(txt < (*A)->dato)
        {
            //printf("Se inserta %c a la izquierda de %c.\n", txt, (*A)->dato);
            insertar(&((*A)->hijoIzq), txt);
            printf("Raiz %c - Izq %c\n", (*A)->dato, txt);
        }
        else if(txt > (*A)->dato) // si es igual, es el mismo nodo, no inserto nada.
        {
            //printf("Se inserta %c a la derecha de %c.\n", txt, (*A) -> dato);
            insertar(&((*A) -> hijoDer), txt);
            printf("Raiz %c - Der %c\n", (*A)->dato, txt);
        }
    }
}

int esMiembro(arbol* A, char txt)
{
    if(A == NULL)
        return -1;
    else if(A -> dato == txt)
        return 1;
    else if(A -> dato > txt)
        return esMiembro(A -> hijoIzq, txt);
    else
        return esMiembro(A -> hijoDer, txt);
}

void corroborarMiembro(arbol* A, char txt)
{
    if(esMiembro(A, txt) == 1)
        printf("Elemento %c existe en el arbol.\n", txt);
    else
        printf("No existe elemento %c en el arbol.\n", txt);
}

char suprimirMin(arbol** A)
{
    char valorRef;
    if((*A) -> hijoIzq == NULL)
    {
        valorRef = (*A) -> dato;
        arbol *tmp = *A;
        *A = (*A) -> hijoDer;
        free(tmp);
        return valorRef;
    }
    else
    {
        return suprimirMin(&((*A) -> hijoIzq));
    }
}

void suprimir(arbol** A, char txt)
{
    if(*A != NULL)
    {
        if(txt < (*A) -> dato)
            suprimir(&((*A) -> hijoIzq), txt);
        else if(txt > (*A) -> dato)
            suprimir(&((*A) -> hijoDer), txt);
        // Lo encontre
        else if((*A) -> hijoIzq == NULL && (*A) -> hijoDer == NULL)
        {
            arbol *tmp = *A;
            *A = NULL;
            free(tmp);
        }
        else if((*A) -> hijoIzq == NULL)
        {
            arbol *tmp = *A;
            *A = (*A) -> hijoDer;
            free(tmp);
        }
        else if((*A) -> hijoDer == NULL)
        {
            arbol *tmp = *A;
            *A = (*A) -> hijoIzq;
            free(tmp);
        }
        else
        { // ambos hijos estan presentes
            (*A) -> dato = suprimirMin(&((*A) -> hijoDer));
        }
    }
}

void listarPreOrden(arbol* r)
{
    if(r == NULL)
        printf("El arbol no posee elementos.\n");
    else
    {
        printf("%c \n", r->dato);
        listarPreOrden(r->hijoIzq);
        listarPreOrden(r->hijoDer);
    }
}
