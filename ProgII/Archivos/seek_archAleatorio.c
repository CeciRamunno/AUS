#include<stdio.h>

int main()
{
    char* path = "./letras.txt";
    FILE *pArch = fopen(path, "w+");
    int letra;

    if(pArch == NULL)
    {
        perror("Error!\n");
        return 1;
    }
    else
    {
        // letras en codigo ascii
        for(letra = 65; letra <= 90; letra++)
            putc(letra, pArch);

        fseek(pArch, 0L, SEEK_SET);
        printf("Letra en el 0Byte (0L): '%c'.\n", getc(pArch));

        // posiciona puntero en 8vo byte.
        fseek(pArch, 8L, SEEK_SET);
        letra = getc(pArch);
        printf("Letra en el 8Byte (8L): '%c'.\n", letra);

        // posiciona puntero en 17vo byte.
        fseek(pArch, 17L, SEEK_SET);
        letra = getc(pArch);
        printf("Letra en el 17Byte (17L): '%c'.\n", letra);

        fseek(pArch, 26L, SEEK_SET);
        letra = getc(pArch);
        printf("Letra en el 26Byte (26L): '%c'.\n", letra);

        if(fclose(pArch))
            perror("Error al cerrar el archivo.\n");
        else
            printf("Archivo cerrado correctamente '%s'.\n", path);

        return 0;
    }
}
