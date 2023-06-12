#include<stdio.h>

int main()
{
    FILE* pFile;
    char cadena[] = "Hola mundo!\n";

    pFile = fopen("./HM.txt", "w+");

    if(pFile == NULL)
        perror("Error!\n");
    else
        fwrite(cadena, sizeof(char), sizeof(cadena), pFile);

    if(fclose(pFile))
        perror("Error al cerrar el archivo.\n");
    else
        printf("Archivo cerrado correctamente.\n");

    return 0;
}
