// Ej2_archivos_pto2.7.c
// Realice un programa en C que leyendo el archivo NOMBRES.DAT cree uno
// nuevo llamado APELLIDOS.DAT y se escriba apellido y nombre en vez de
// nombre y apellido como estaba en el original.

#include<stdio.h>
#define MAX_LINE_LENGTH 50

int main()
{
    char* pathNombre = "./nombres.dat";
    FILE* pArchNombre = fopen(pathNombre ,"r");

    if(pArchNombre != NULL)
    {
        char* pathApellidos = "./apellidos.dat";
        FILE* pArchApellidos = fopen(pathApellidos, "w");

        int linea = 1;
        char line[MAX_LINE_LENGTH];

        if(pArchApellidos != NULL)
        {
            char* strLine;

            while(fgets(line, MAX_LINE_LENGTH, pArchNombre))
            {
                printf("linea[%02d] leida: %s", linea++, line);
                strLine = strtok(line, " "); // nombre
                strLine = strtok(NULL, " "); // apellido

                fprintf(pArchApellidos,"%s", strLine);
            }

            if (fclose(pArchApellidos))
            {
                printf("\nError al cerrar el archivo.\n");
                perror(pathApellidos);
            }
            else
            {
                printf("\nArchivo '%s' cerrado ok.\n", pathApellidos);
            }
        }
        else
        {
            printf("\nError al abrir el archivo '%s'.\n", pathApellidos);
            perror(pathApellidos);
        }

        if (fclose(pArchNombre))
        {
            printf("\nError al cerrar el archivo '%s'.\n", pathNombre);
            perror(pathNombre);
        }
        else
            printf("Archivo '%s' cerrado ok.\n", pathNombre);
    }
    else
    {
        printf("\nError al abrir el archivo '%s'.\n", pathNombre);
        perror(pathNombre);
    }
}
