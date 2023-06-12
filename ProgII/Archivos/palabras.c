// palabras.c

#include<stdio.h>

int main()
{
    FILE *pArch;
    pArch = fopen("./palabras.dat", "a"); // Abre archivo y añade datos al final.

    if(pArch != NULL)
    {
        fputs("otra tres\n", pArch);
        fputs("nunca c4\n", pArch);
        fputs("porSiempre! 5cinco\n", pArch);

        if(!fclose(pArch))
            printf("El archivo se ha cerrado.\n");
        else
            printf("Error al cerrar el archivo.\n");
    }
    else
        printf("Error al crear el archivo.\n");

    return 0;
}
