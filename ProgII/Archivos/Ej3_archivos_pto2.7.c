// Ej2_archivos_pto2.7.c
// Haga una copia exacta del archivo NOMBRES.DAT pero el nuevo que sea binario.

#include<stdio.h>
#define MAX_LINE_LENGTH 50

int main()
{
    char* pathNombre = "./nombres.dat";
    FILE* pArchNombre = fopen(pathNombre ,"r");
    char line[MAX_LINE_LENGTH];

    if(pArchNombre != NULL)
    {
        printf("** Reading '%s' **\n", pathNombre);
        char* pathNombreBin = "./nombres.bin";
        FILE* pArchNombreBin = fopen(pathNombreBin, "wb");

        if(pArchNombreBin != NULL)
        {
            printf("** Writing '%s' **\n", pathNombreBin);
            while(fgets(line, MAX_LINE_LENGTH, pArchNombre))
            {
                printf("Linea: %s", line);
                fprintf(pArchNombreBin, "%s", line);
            }

            if(fclose(pArchNombreBin))
            {
                printf("Error al cerrar archivo '%s'.\n", pathNombreBin);
                perror(pathNombreBin);
            }
            else
                printf("\nArchivo '%s' cerrado correctamente.\n", pathNombreBin);
        }
        else
        {
            printf("\nError al abrir el archivo '%s'.\n", pathNombreBin);
            perror(pathNombreBin);
        }

        if(fclose(pArchNombre))
        {
            printf("Error al cerrar archivo '%s'.\n", pathNombre);
            perror(pathNombre);
        }
        else
            printf("Archivo '%s' cerrado correctamente.\n", pathNombre);
    }
    else
    {
        printf("\nError al abrir el archivo '%s'.\n", pathNombre);
        perror(pathNombre);
    }
}
