#include <stdio.h>
#include <stdlib.h>

//High sarebbe il valore massimo della mia partizione, Low il valore minimo.

void swap(int* a, int* b);

int partition(int arr[], int low, int high){
    //Metto il mio pivot come il valore massimo
    int pivot = arr[high];
    //Metto un indice a un punto in meno del valore minimo, in modo da poter anche mettere un elemento
    //Prima del valore minimo.
    int i = low - 1;

    //Controllo Partendo dal valore minimo fino a quello più alto, se l'indice è più piccolo del pivot.
    for (int j = low; j <= high; j++){
        //Se è più piccolo del pivot significa che il pivot deve stare in quella casella
        if(arr[j]<pivot){
            //Sommo quanti elementi sono più piccoli del pivot
            i++;
            //Sposto l'elemento più piccolo del pivot verso sinistra.
            swap(&arr[i], &arr[j]);
        }
    }
    //Adesso devo mettere il pivot nella posizione corretta.
    swap(&arr[i+1], &arr[high]);
    //Ritorno la posizione del pivot
    return i+1;
}


void quicksort(int arr[], int low, int high){
    if(low < high){
        //Faccio la prima partizione, trovo il pivot al centro
        int pi = partition(arr, low, high);
        //Prendo la parte sinistra della mia partizione precedente
        quicksort(arr, low, pi-1);
        //Prendo la parte destra della partizione precedente
        quicksort(arr, pi+1, high);
    }
}


void printarr(int arr[], int size){
    for(int i = 0; i<size;i++){
        printf("%d,", arr[i]);
    }
}

void swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int arr[] = {10,3,2,20,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,size-1);
    printarr(arr,size);
    return 0;
}