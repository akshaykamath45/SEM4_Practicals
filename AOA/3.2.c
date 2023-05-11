#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[100];
    int n;
    int key;

    printf("Enter number of elements to be inserted inside the array : \n");
    scanf("%d", &n);

    printf("Please enter %d elements in sorted order !! \n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched : ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);

    if (index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element %d is present at index %d", key, index);
    }
}