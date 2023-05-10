
#include <stdio.h>

// sum of subset

void printSolution(int w[], int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", x[i]);
    }
    printf("\n");
    printf("[");
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
        {
            printf("%d ", w[i]);
        }
    }
    printf("]");
    printf("\n");
}
void sumOfSubset(int w[], int x[], int s, int k, int r, int m, int n)
{
    static int count = 0;
    x[k] = 1;
    if (s + w[k] == m)
    {
        count++;
        printf("\nSolution : %d \n", count);
        for (int ct = k + 1; ct < n; ct++)
        {
            x[ct] = 0;
        }
        printSolution(w, x, n);
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumOfSubset(w, x, s + w[k], k + 1, r - w[k], m, n);
    }
    if ((s + w[k + 1]) <= m && (s + r - w[k] >= m))
    {
        x[k] = 0;
        sumOfSubset(w, x, s, k + 1, r - w[k], m, n);
    }
}
int main()
{
    int sum = 0, k = 0, rem = 0;
    int m, n;
    int w[20], x[20];

    printf("Enter number of weights \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter Weight %d : ", i + 1);
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        rem += w[i];
        x[i] = 0;
    }

    printf("Enter the needed sum to be matched \n");
    scanf("%d", &m);

    sumOfSubset(w, x, sum, k, rem, m, n);

    return 0;
}
