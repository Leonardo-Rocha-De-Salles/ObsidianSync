#include <stdio.h>
#include <stdlib.h>


void printArr(int **v, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            //v+i mi dice quale puntatore(riga) sto prendendo, poi
            // *(v+i)+j mi dice quale elemento di quella riga, infine
            //il puntatore davanti al numero mi prende il valore di quella
            //Regione di memoria.
            printf("%d, ", *(*(v+i)+j));
        }
        printf("\n");
    }
}

void insertNumbers(int **v, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("Enter number for position (%d, %d): ", i, j);
            scanf("%d", *(v+i)+j);
        }
    }
}

int main(){
    //array 5 righe, 10 colonne
    int rows = 3; int columns = 2;
    int **v = (int **)malloc(sizeof(int)*rows*columns);
    if (v == NULL){
        printf("Malloc Error;\n");
        return 0;
    }

    for (int i = 0; i< rows; i++){
        v[i] = (int *)malloc(columns * sizeof(int));
        if (v[i] == NULL){
            printf("Mallor Error;\n");
        }
    }


    printArr(v,rows,columns);
    insertNumbers(v, rows, columns);
    printArr(v,rows,columns);
    return 0;
}