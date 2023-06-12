#include<stdio.h>

int main()
{
    int letra;
    int i;

    char* path = "./letras.txt";
    FILE *pArch = fopen(path, "r");


    if(pArch == NULL)
    {
        perror("Error!\n");
        return 1;
    }
    else
    {
        fseek(pArch, 1L, SEEK_END);
        for(i = 0; i <= 25; i++) // letras en codigo ascii
        {
            fseek(pArch, -2L, SEEK_CUR); // el programa retrocede de a 2bytes, dsd pos puntero actual.
            letra = getc(pArch);
            printf("Letra leida: '%c'.\n", letra);
        }

        if(fclose(pArch))
            perror("Error al cerrar el archivo.\n");
        else
            printf("Archivo cerrado correctamente '%s'.\n", path);

        return 0;
    }
}
