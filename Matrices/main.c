#include <stdio.h>
#include <stdlib.h>

#define COL 5
#define COMUN 2
#define FIL 3

int * multiplicar(int m1[][COMUN], int fm1, int cm1, int m2[][COL], int fm2, int cm2);
void mostrarMatriz(int * m, int f, int c);

int main()
{
    int m1[FIL][COMUN]={{4,2},{1,-2},{1,2}};
    int m2[COMUN][COL]={{2,1,0,-1,6},{3,7,0,4,1}};
    printf("Matriz A:");
    mostrarMatriz(m1, FIL, COMUN);
    printf("\n\nMatriz B:");
    mostrarMatriz(m2, COMUN, COL);
    printf("\n____________________________________\n\nMatriz AxB:");
    mostrarMatriz(multiplicar(m1,FIL,COMUN,m2,COMUN,COL),FIL,COL);
    return 0;
}


int * multiplicar(int m1[][COMUN], int fm1, int cm1, int m2[][COL], int fm2, int cm2)
{
    int i, j, k, nro;
    int * mres;

    if(cm1!=fm2)
    {
        printf("\n\nNo se pueden multiplicar las matrices.\nLa cantidad de columnas de la matriz A tiene que ser igual a la cantidad de filas de la matriz B.");
        return m1;
    }

    mres = (int *)malloc(sizeof(int)*fm1*cm2);

    for(i=0;i<fm1;i++)
        for(j=0;j<cm2;j++)
        {
            nro = 0;
            for(k=0;k<cm1;k++) //cm1 = fm2
                nro+=(m1[i][k]*m2[k][j]);
            *(mres+i*cm2+j) = nro;
        }


    return mres;
}

void mostrarMatriz(int * m, int f, int c)
{
    int i, j;
    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("%d\t", *m);
            m++;
        }
    }
}
