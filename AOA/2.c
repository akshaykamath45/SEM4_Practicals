#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 15000
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[MAX];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            i++;
        }
        else
        {
            B[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partiton(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partiton(arr, low, high);
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}
int main()
{
    int n, arr[15000], ch;
    clock_t start_t, end_t;
    double total_t;
    printf("Enter size of array : ");
    scanf("%d", &n);
    do
    {
        printf("Enter 1 for Quick Sort,2 for Merge Sort,3 For Exiting Program : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nQuick Sort \n\n");
            printf("Best Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }
            quickSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Best Case is : %f \n\n", total_t);

            printf("Average Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n + 1;
            }
            quickSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Average Case is : %f \n\n", total_t);

            printf("Worst Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = n - i;
            }
            quickSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Worst Case is : %f \n\n", total_t);

            break;
        case 2:
            printf("\nMerge Sort \n\n");
            printf("Best Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }
            mergeSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Best Case is : %f \n\n", total_t);

            printf("Average Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand() % n + 1;
            }
            mergeSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Average Case is : %f \n\n", total_t);

            printf("Worst Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = n - i;
            }
            mergeSort(arr, 0, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Worst Case is : %f \n\n", total_t);

            break;
        case 3:
            printf("Exiting program,Thank you.\n");
            return 0;
            break;
        }
    } while (ch != 3);
}