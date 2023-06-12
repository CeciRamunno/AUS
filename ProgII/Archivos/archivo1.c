// archivo1.c

#include<stdio.h>

int main()
{
    FILE *pArch;
    int contador;

    pArch = fopen("./nros.1", "w"); // Crea el archivo, si ya existe lo pisa.
    if(pArch != NULL)
    {
        for(contador = 1; contador <= 100; contador++)
            fprintf(pArch,"Nro: %d\n", contador);

        if(!fclose(pArch))
            printf("El archivo se ha cerrado.\n");
        else
            printf("Error al cerrar el archivo.\n");
    }
    else
        printf("Error al crear el archivo.\n");

    return 0;
}
