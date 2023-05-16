#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    clock_t start_t, end_t;
    double total_t;
    int n = 150000;
    int arr[n];

    printf("Insertion Sort\n\n");
    // Best Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    start_t = clock();
    printf("\nBest Case\n");
    printf("Starting time : %ld\n", start_t);
    insertionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    // Average Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    start_t = clock();
    printf("\nAverage Case\n");
    printf("Starting time : %ld\n", start_t);
    insertionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    // Worst Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
    start_t = clock();
    printf("\nWorst Case\n");
    printf("Starting time : %ld\n", start_t);
    insertionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    printf("\nSelection Sort\n\n");
    // Best Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    start_t = clock();
    printf("\nBest Case\n");
    printf("Starting time : %ld\n", start_t);
    selectionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    // Average Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
    start_t = clock();
    printf("\nAverage Case\n");
    printf("Starting time : %ld\n", start_t);
    selectionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    // Worst Case
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
    start_t = clock();
    printf("\nWorst Case\n");
    printf("Starting time : %ld\n", start_t);
    selectionSort(arr, n);
    end_t = clock();
    printf("Ending Time : %ld\n", end_t);
    total_t = (double)end_t - (double)start_t;
    printf("Total Time : %f\n", total_t);

    return 0;
}