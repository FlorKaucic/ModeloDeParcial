#include <stdio.h>
#include <stdlib.h>

#define TAM 101

#define esBlanco(X) ((X)==' '||(X)=='\t')
#define aMayus(X) ((X)>='a'&&(X)<='z')?(X)-32:(X)
#define aMinus(X) ((X)>='A'&&(X)<='Z')?(X)+32:(X)

char * normalizar(char *);
int str_len(char *);


int main()
{
    char cadena[TAM];
    char cadena2[] = "    hOlA       bIENVENIDO a   NARnia   ";

    // Ejemplo
    printf("Ejemplo:\n\nCadena original:\n%s\nLongitud: %d", cadena2, str_len(cadena2));
    printf("\n\nCadena normalizada:\n%s", normalizar(cadena2));
    printf("\nLongitud: %d", str_len(cadena2));


    // Ingresada por el usuario
    printf("\n\nIngrese la cadena a normalizar: ");
    gets(cadena);
    printf("\n\nCadena original:\n%s\nLongitud: %d", cadena, str_len(cadena));
    printf("\n\nCadena normalizada:\n%s", normalizar(cadena));
    printf("\nLongitud: %d", str_len(cadena));


    return 0;
}

char * normalizar(char * pc)
{
    char * prichr = pc;
    char * aux = pc;

    while(*pc)
    {
        while(esBlanco(*pc))
            pc++;

        if(*pc)
        {
            *aux=aMayus(*pc);
            aux++;
            pc++;

            while(*pc&&!esBlanco(*pc))
            {
                *aux=aMinus(*pc);
                aux++;
                pc++;
            }

            if(esBlanco(*pc))
            {
                *aux=' ';
                aux++;
                pc++;
            }
        }
    }

    if(aux>prichr&&esBlanco(*(aux-1)))
        aux--;

    *aux='\0';

    return prichr; º
}

int str_len(char * c)
{
    int i = 0;
    while(*c)
    {
        i++;
        c++;
    }
    return i;
}
