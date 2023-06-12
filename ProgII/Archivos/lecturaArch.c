// lecturaArch.c

#include<stdio.h>

int main()
{
    FILE *pArch;

    char word1[25];
    char word2[25];

    pArch = fopen("./palabras.dat","rt"); // Abre archivo, actualizacion y lectura.

    if(pArch != NULL)
    {
       fscanf(pArch, "%s %s", word1, word2);

        // Como fscanf() leera en bloques hasta un espacio, tab o fin de linea nos resultara
        // imposible encontrar manualmente el fin del archivo, por eso utilizamos la funcion
        // de librerıa feof().
        // En cada lectura del archivo, el puntero del mismo avanza, esta funcion ira chequeando
        // cuando se llega al final, retornara 0.
        while(!feof(pArch)){
            printf("Las palabras son: %s - %s.\n", word1, word2);
            fscanf(pArch, "%s %s", word1, word2);
        }
        if(fclose(pArch)) // si todo va ok, devuelve 0 (false, no?)
            printf("Error al cerrar el archivo.\n");

    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }

    return 0;

}
