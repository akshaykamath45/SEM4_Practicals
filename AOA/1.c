#include <stdio.h>
#include <conio.h>
#include <time.h>
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
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
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[j] > min)
            {
                min = arr[j];
            }
        }
        if (arr[min] != arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = arr[temp];
        }
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
        printf("Enter 1 for Insertion Sort,2 for Selection Sort,3 For Exiting Program : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nInsertion Sort \n\n");
            printf("Best Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }
            insertionSort(arr, n);
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
            insertionSort(arr, n);
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
            insertionSort(arr, n);
            end_t = clock();
            printf("End Time is  : %ld \n", end_t);
            total_t = (double)end_t - (double)start_t;
            printf("Total Time taken in Worst Case is : %f \n\n", total_t);

            break;
        case 2:
            printf("\nSelection Sort \n\n");
            printf("Best Case : \n");
            start_t = clock();
            printf("Start Time is : %ld \n", start_t);
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }
            selectionSort(arr, n);
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
            selectionSort(arr, n);
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
            selectionSort(arr, n);
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