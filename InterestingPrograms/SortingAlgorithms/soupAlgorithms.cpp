// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ACGT_Generator.h"

// Global variable
static int counter = 0;
int N;

// Comparison function
int compare(char *a, char *b)
{
    counter++;
    return strcmp(a, b);
}

//--------------------------------------------------
//    PARTITION
//--------------------------------------------------
/*
Given an array V with elements in any order,
choose an element to be a pivot^
and then divide the elements of V into two parts:
  `on the left: smaller than the pivot
  `on the right: greater than or equal to the pivot
*/

int Partition(char **V, int start, int end)
{
    char *pivot, *aux;
    int left, right;

    pivot = V[start]; // in this example, the pivot is the leftmost element
    left = start + 1;
    right = end;
    do
    {
        // traverse from left to right. find someone >= pivot
        while (left < end && compare(V[left], pivot) < 0)
            left++;
        // traverse from right to left. find someone < pivot
        while (start < right && compare(V[right], pivot) >= 0)
            right--;
        // if one is found on the left and the other on the right
        if (left < right)
        {
            // swap
            aux = V[left];
            V[left] = V[right];
            V[right] = aux;
        }
        // otherwise, the loop will terminate
    } while (left < right);

    // swap the pivot with the element that "divides" the subarrays
    V[start] = V[right];
    V[right] = pivot;
    // return the position of the "division"
    return right;
}

//--------------------------------------------------
//    QUICK SORT
//--------------------------------------------------

void QuickSort(char **V, int start, int end)
{
    int position; // position of the pivot
    if (start < end)
    {
        position = Partition(V, start, end);
        QuickSort(V, start, position - 1);
        QuickSort(V, position + 1, end);
    }
}

//--------------------------------------------------
//    MERGE
//--------------------------------------------------
/*
Given an array V and two positions start and end.
The left half of this segment is already sorted, and
the right half of this segment is already sorted.
Perform merging and get a sorted V.
*/

void Merge(char **V, int start, int end)
{
    int middle, i, j, k;
    middle = (start + end) / 2;

    // slightly optimized merge by using static variables (right ?)
    static char **T = (char **)malloc(N * sizeof(char *));

    i = start;
    j = start;
    k = middle + 1;

    while (j <= middle && k <= end)
    {
        if (compare(V[j], V[k]) <= 0)
        {
            T[i - start] = V[j];
            j++;
        }
        else
        {
            T[i - start] = V[k];
            k++;
        }
        i++;
    }

    while (j <= middle)
    {
        T[i - start] = V[j];
        i++;
        j++;
    }

    while (k <= end)
    {
        T[i - start] = V[k];
        i++;
        k++;
    }

    for (i = start; i <= end; i++)
    {
        V[i] = T[i - start];
    }

    // free(T);
}

//--------------------------------------------------
//    MERGE SORT
//--------------------------------------------------

void MergeSort(char **V, int start, int end)
{
    int middle;
    if (start < end)
    {
        middle = (start + end) / 2;    // divide in half
        MergeSort(V, start, middle);   // sort the left side
        MergeSort(V, middle + 1, end); // sort the right side
        Merge(V, start, end);          // merge the two halves
    }
}

//--------------------------------------------------
//    BUBBLE SORT
//--------------------------------------------------

void BubbleSort(char **V, int start, int end)
{
    char *aux;
    for (int i = 0; i < end - 1; i++)
    {
        for (int j = 0; j < end - i - 1; j++)
        {
            if (compare(V[j], V[j + 1]) > 0)
            {
                aux = V[j];
                V[j] = V[j + 1];
                V[j + 1] = aux;
            }
        }
    }
}

// function to create copies of the original array
void copyArray(char **originalArray, char **copiedArray, int n)
{
    for (int i = 0; i < n; i++)
    {
        copiedArray[i] = (char *)malloc(strlen(originalArray[i]) + 1);
        strcpy(copiedArray[i], originalArray[i]);
    }
}

// function to print the result in different files
void printResult(FILE *output, char *algorithm, int n, int comparisons, float executionTime, char **array)
{
    fprintf(output, "Algorithm: %s-Sort \n\n", algorithm);
    fprintf(output, "Input size: %d\n", n);
    fprintf(output, "Comparisons made: %d\n", comparisons);
    fprintf(output, "Execution time: %.3f seconds\n\n", executionTime);
    fprintf(output, "--------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%s\n", array[i]);
    }
}

float timer(char **array, int n, int id)
{
    clock_t start, end;

    start = clock();
    switch (id)
    {
    case 1:
        QuickSort(array, 0, n - 1);
        break;
    case 2:
        MergeSort(array, 0, n - 1);
        break;
    case 3:
        BubbleSort(array, 0, n - 1);
        break;

    default:
        break;
    }
    end = clock();

    return ((end - start) / (float)CLOCKS_PER_SEC);
}

// main function
int main()
{
    char message[50];

    // variables for time calculation
    clock_t start_t, end_t;
    float delta_t;

    generator();

    // defining input and output files
    FILE *input = fopen("input.txt", "r");
    FILE *bubbleOutput = fopen("Bubble.txt", "w");
    FILE *mergeOutput = fopen("Merge.txt", "w");
    FILE *quickOutput = fopen("Quick.txt", "w");

    fscanf(input, "%d", &N);

    // allocate memory for arrays
    char **originalArray = (char **)malloc(N * sizeof(char *));
    char **quickArray = (char **)malloc(N * sizeof(char *));
    char **mergeArray = (char **)malloc(N * sizeof(char *));
    char **bubbleArray = (char **)malloc(N * sizeof(char *));

    // write original array
    for (int i = 0; i < N; i++)
    {
        fscanf(input, "%s", message);
        // allocate memory for elements of the original array
        originalArray[i] = (char *)malloc(strlen(message) + 1);
        strcpy(originalArray[i], message);
    }

    fclose(input);

    // copy original to 3 different arrays
    copyArray(originalArray, quickArray, N);
    copyArray(originalArray, mergeArray, N);
    copyArray(originalArray, bubbleArray, N);

    // free original array (no longer needed after copying)
    for (int i = 0; i < N; i++)
    {
        free(originalArray[i]);
    }
    free(originalArray);

    // sort and print quicksort
    delta_t = timer(quickArray, N, 1);
    printResult(quickOutput, "Quick", N, counter, delta_t, quickArray);
    counter = 0;
    fclose(quickOutput);

    // sort and print mergesort
    delta_t = timer(mergeArray, N, 2);
    printResult(mergeOutput, "Merge", N, counter, delta_t, mergeArray);
    counter = 0;
    fclose(mergeOutput);

    // sort and print bubblesort
    delta_t = timer(bubbleArray, N, 3);
    printResult(bubbleOutput, "Bubble", N, counter, delta_t, bubbleArray);
    counter = 0;
    fclose(bubbleOutput);

    return 0;
}
