#include <stdio.h>
#include <stdlib.h>
//scrivi una funzione che dato due array ne calcoli la somma in un terzo array. Nel main stampa il terzo array
//la funzione ritorna un puntatore all'array creato
int *array(int arr1[],int arr2[],int n){
    int *arr3;
    arr3 = (int *)malloc(n*sizeof(arr1[0]));
    for(int i = 0; i < n;i++){
        arr3[i] = arr1[i]+arr2[i];
    }
    return arr3;
}

int main(){
    int n = 5;
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5};
    int *a;
    a = array(arr1,arr2,n);
    for(int i = 0; i < n;i++){
        printf("%d\n",*(a+i));
    }   
    return 0;
}