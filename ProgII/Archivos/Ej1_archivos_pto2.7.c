// Ej1_archivos_pto2.7.c
//Realizar un programa en C que realice la lectura del archivo del ejemplo
//utilizando la funcion getc().

#include<stdio.h>
#define MAX_LINE_LENGTH 35

int main()
{
    char *path = "./palabras.dat";
    FILE *pArch = fopen(path, "r");
    char line[MAX_LINE_LENGTH]; // long de la linea que lee
    int nroline = 1;

    if(pArch != NULL)
    {
        while(fgets(line, MAX_LINE_LENGTH, pArch))
        {
            printf("line[%03d]: %s", nroline++, line);

            if(line[strlen(line) - 1] != '\n') // para que no quede todo pegado en la misma linea
                printf("\n");
        }

        if (fclose(pArch))
        {
            printf("Error al cerrar el archivo.\n");
            perror(path);
        }
        else
            printf("Archivo '%s' cerrado ok.\n", path);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
        perror(path);
    }
}
