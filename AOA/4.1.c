#include <stdio.h>
int main()

{
    float w[100], p[100], pw[100], kn[100], tw, max = 0, tp = 0.maxindex;
    int i, j, n, v[100];
    printf("Enter number of weights : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter profit and weight %d ", i + 1);
        scanf("%f %f", &p[i], &w[i]);
        pw[i] = p[i] / w[i];
        v[i] = 0;
    }
    printf("Enter total weight : ");
    scanf("%f", &tw);

    while (tw != 0)
    {
        max = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == 0 && pw[j] > max)
            {
                max = pw[j];
                maxIndex = j;
            }
        }
        v[maxIndex] = 1;
        if (w[maxIndex] <= tw)
        {
            tw -= w[maxIndex];
            kn[maxIndex] = 1;
        }
        else
        {
            kn[maxIndex] = tw / w[maxIndex];
            tw = 0;
        }
        tp += kn[maxIndex] * p[maxIndex];
    }
    printf("Profit\tWeight\tp/w\tKnapsack\n");
    for (i = 0; i < n; i++)
    {
        printf("%f\t%f\t%f\t%f\n", p[i], w[i], pw[i], kn[i]);
    }
    printf("Max profit is %.2f", tp);

    return 0;
}
