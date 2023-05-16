#include <stdio.h>
#include <stdlib.h>
#include "arbolbinario.h "

int main ()
{
    arbol *raiz;
    raiz = NULL;

    /* Armado código para probar el arbol */

    insertar(&raiz, "Hola");
    insertar(&raiz, "BuenasNoches")
    insertar(&raiz, "SoyCeci");
    insertar(&raiz, "Practicando");

    corroborarMiembro(raiz, "Chau");
    corroborarMiembro(raiz, "SoyCeci");

    return 0;
}

void insertar(arbol **A, char txt)
{
    if (*A == NULL)
    {
        *A = (arbol*)malloc(sizeof(arbol));
        (*A) -> dato = txt;
        (*A) -> h_izq = NULL;
        (*A) -> h_der = NULL;
    }
    else // si ya hay un nodo:
    {
        if(strcmp(txt < (*A) -> dato) < 0)
            insertar(&((*A) -> h_izq), txt);
        else if(strcmp(txt > (*A) -> dato) > 0) // si es igual, es el mismo nodo.
            insertar(&((*A) -> h_der), txt);
    }
}

int esMiembro(arbol *A, char txt)
{
    if(A == NULL)
        return -1;
    else if(A -> dato == txt)
        return 1;
    else if(A -> dato > txt)
        return esMiembro(A -> h_izq, txt);
    else
        return esMiembro(A -> h_der, txt);
}

void corroborarMiembro(arbol *A, char txt)
{
    if(esMiembro(A, txt) == 1)
        printf("Elemento existe en el árbol.\n");
    else
        printf("No existe elemento en el árbol.\n");
}

char suprimirMin(arbol **A)
{
    char v_ref;
    if((*A) -> h_izq == NULL)
    {
        v_ref = (*A) -> dato;
        arbol *tmp = *A;
        *A = (*A) -> h_der;
        free(tmp);
        return v_ref;
    }
    else
    {
        return suprimirMin(&((*A) -> h_izq));
    }
}

void suprimir(arbol **A, char txt)
{
    if(*A != NULL)
    {
        if(txt < (*A) -> dato)
            suprimir(&((*A) -> h_izq), txt);
        else if(txt > (*A) -> dato)
            suprimir(&((*A) -> h_der), txt);
        // Lo encontre
        else if((*A) -> h_izq == NULL && (*A) -> h_der == NULL)
        {
            arbol *tmp = *A;
            *A = NULL;
            free(tmp);
        }
        else if((*A) -> h_izq == NULL)
        {
            arbol *tmp = *A;
            *A = (*A) -> h_der;
            free(tmp);
        }
        else if((*A) -> h_der == NULL)
        {
            arbol *tmp = *A;
            *A = (*A) -> h_izq;
            free(tmp);
        }
        else
        { // ambos hijos ´aestn presentes
            (*A) -> dato = suprimirMin(&((*A) -> h_der));
        }
    }
}
