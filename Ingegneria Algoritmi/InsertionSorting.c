#include <stdio.h>
#include <stdlib.h>


void insertion(int arr[], int size){
    int* tmp = arr;
    int save;
    //Verifico ogni elemento che non sia il primo
    for(int i = 1; i<size; i++){
    //Salvo l'elemento che sto verificando
        int key = arr[i];
    //Salvo l'elemento precedente
        int j = i-1;
    //Finchè gli elementi precedenti sono in posizione maggiore di 0 E il numero in
    // Quella posizione è maggiore della chiave, lo devo spostare avanti.
        while(j>=0 && arr[j]>key){
        //Sposto in avanti il numero precedente a quello che controllo se maggiore
            arr[j+1] = arr[j];
        //Adesso controllo se quello precedente è maggiore alla chiave
            j = j - 1;
        }
        // Quando non ho più numeri maggiori, inserisco la chiave quando essa
        // E' più grande rispetto al numero precedente.
        arr[j+1] = key;
    }
}


void printarr(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d,",arr[i]);
    }

}


int main(){
    int arr[] = {3,4,10,5,2,1};
    int size = sizeof(arr)/sizeof(int);
    insertion(arr,size);
    printarr(arr,size);
}