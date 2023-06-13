#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atun.h"

#define pathBuenos "C:\\Temp\\chicos_buenos.txt"
#define pathMalos "C:\\Temp\\chicos_malos.txt"

int main()
{
    // Apertura archivos.
    FILE *pArchBuenos = fopen(pathBuenos, "w+");
    FILE *pArchMalos = fopen(pathMalos, "w+");

    if(pArchBuenos == NULL || pArchMalos == NULL)
    {
        perror("Error en abrir los archivos.\n");
        return 1;
    }

    char opc;
    printf("Que desea realizar?\n'I'-Ingresar legislador\n'S'-Suprimir legislador\n'C'-Consultar por legislador\n'L'-Listar legisladores\n");
    scanf("%c", &opc);

    if(opc == 'I')
        insertar();

//    if(opc == "S")
//        //suprimir();
//    if(opc == "C")
//       // miembro()
//    if(opc == "L")
//        mostrar();
//    //printf("opc %c", opc);

    return 0;
}

void insertar()
{
    legislador* leg = NULL;
    leg = (legislador*)malloc(sizeof(legislador));

    printf("\tInserte nombre de legislador: ");
    scanf("%s", leg->nombre); // TODO: validar cant caracteres.

    char voto;
    printf("\tInserte el voto: ");
    scanf("%c", &voto);
    printf("el voto: %c", voto);

}

    // suprimir(legislador, conj q corresp)
    // bool miembro(legislador, conj)
    // mostrar() lee arch y muestra pantalla
