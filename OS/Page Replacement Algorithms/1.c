#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_pages, n_frames;
    int hit_count = 0;
    int fault_count = 0;
    int frames[50], pg_stream[50];
    float hit_ratio, miss_ratio;
    printf("Enter number of frames : ");
    scanf("%d", &n_frames);

    printf("Enter number of pages in the stream : ");
    scanf("%d", &n_pages);

    printf("Enter the stream : \n");

    for (int i = 0; i < n_pages; i++)
    {
        scanf("%d", &pg_stream[i]);
    }
    char check = 'F';
    int j = 0;
    for (int k = 0; k < n_frames; k++)
        frames[k] = -1;

    for (int i = 0; i < n_pages; i++)
    {
        check = 'F';
        for (int k = 0; k < n_frames; k++)
        {
            if (pg_stream[i] == frames[k])
            {
                hit_count++;
                check = 'H';
            }
        }
        if (j < n_frames && check != 'H')
        {
            frames[j] = pg_stream[i];
            j++;
            fault_count++;
        }
        else if (j >= n_frames && check != 'H')
        {
            j = 0;
            frames[j] = pg_stream[i];
            j++;
            fault_count++;
        }
        printf("%d \t\t\t", pg_stream[i]);
        for (int k = 0; k < n_frames; k++)
        {
            if (frames[k] != -1)
            {
                printf("%d\t", frames[k]);
            }
            else
                printf("\t");
        }
        printf("%c\n", check);
    }
    hit_ratio = hit_count / (float)n_pages;
    miss_ratio = fault_count / (float)n_pages;

    printf("The total number of hits are %d \n", hit_count);
    printf("The total number of faults are %d \n", fault_count);
    printf("The hit ratio is %.2f \n", hit_ratio);
    printf("The miss ratio is %.2f \n", miss_ratio);
}
