#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h> 
#include <time.h>


void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio + 1, comAux = 0, tam = fim - comeco + 1;
    int* vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while (com1 <= meio && com2 <= fim) {
        if (vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while (com1 <= meio) {  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while (com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for (comAux = comeco; comAux <= fim; comAux++) {    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux - comeco];
    }

    free(vetAux);
}
void mergeSort(int vetor[], int comeco, int fim) {
    if (comeco < fim) {
        int meio = (fim + comeco) / 2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place   
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
int partition(int arr[], int low, int high)

{

    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)

    {

        if (arr[j] <= pivot)

        {

            i++;

            swap(&arr[i], &arr[j]);

        }

    }

    swap(&arr[i + 1], &arr[high]);

    return (i + 1);

}
void quickSort(int arr[], int low, int high)

{

    if (low < high)

    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);

    }

}

int main()
{
    int selec1,selec2;
    clock_t starttime, endtime;// data type for calculating time
    double totaltime;// variable for calculating total time of execution
    int i = 0, j, n = 0, min, index;
    int arr[100000];// declaring array to store data from file 
    FILE* fptr;// declaring file pointer

    printf("\n\n+---------[Tamanho]---------+\n");
    printf("|\033[0;32m  1 - Pequeno          \033[0m    |\n");
    printf("|\033[0;33m  2 - Medio             \033[0m   |\n");
    printf("|\033[0;34m  3 - Grande         \033[0m      |\n");
    printf("|\033[0;31m  4 - Sair           \033[0m      |\n");
    printf("+---------------------------+\n");
    printf("\n\033[0;36 IIndique qual o tamanho de deseja usar:\033[0m");
    scanf_s("%d", &selec1);
    switch (selec1)
    {
    case 1:
        fptr = fopen("file_min.txt", "r");// opening the integer file.
        while (fscanf(fptr, "%d", &arr[i]) == 1)// scanning integer from file to array
        {
            n++; // for counting the number of elements  
            i++; // for incrementing the array index
        }
        break;
    case 2:
        fptr = fopen("file_mid.txt", "r");// opening the integer file.
        while (fscanf(fptr, "%d", &arr[i]) == 1)// scanning integer from file to array
        {
            n++; // for counting the number of elements  
            i++; // for incrementing the array index
        }
        break;
    case 3:
        fptr = fopen("file_max.txt", "r");// opening the integer file.
        while (fscanf(fptr, "%d", &arr[i]) == 1)// scanning integer from file to array
        {
            n++; // for counting the number of elements  
            i++; // for incrementing the array index
        }
        break;
    case 4:
        exit(0);
    default:
        break;
    }

    printf("\n\n+---------[Sorting]---------+\n");
    printf("|\033[0;32m  1 - Merge sort       \033[0m    |\n");
    printf("|\033[0;33m  2 - Bubble Sort       \033[0m   |\n");
    printf("|\033[0;34m  3 - Selection Sort \033[0m      |\n");
    printf("|\033[0;35m  4 - QuickSort      \033[0m      |\n");
    printf("|\033[0;31m  5 - sair           \033[0m      |\n");
    printf("+---------------------------+\n");
    printf("\n\033[0;36 IIndique que sorting systems deseja usar:\033[0m");
    scanf("%d", &selec2);

switch (selec2)
{
case 1://merge sort  
    starttime = clock();
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    endtime = clock();// calculating clock when sorting  ends
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("\n\ntotal time of execution = %f\n", totaltime);
    break;

case 2://Bubble Sort
    starttime = clock();
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    endtime = clock();// calculating clock when sorting  ends
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("\n\ntotal time of execution = %f\n", totaltime);
    break;

case 3://Selection Sort
    starttime = clock();
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    endtime = clock();// calculating clock when sorting  ends
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("\n\ntotal time of execution = %f\n", totaltime);
    break;
case 4://QuickSort
    starttime = clock();
    quickSort(arr, 0, n - 1);
    printf("The sorted array is:\n");
    printArray(arr, n);
    endtime = clock();// calculating clock when sorting  ends
    totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
    printf("\n\ntotal time of execution = %f\n", totaltime);
case 5:
    
    exit(0);
default:
    printf("Essao opcao nao existe");
    break;
   
}
return 0;
}