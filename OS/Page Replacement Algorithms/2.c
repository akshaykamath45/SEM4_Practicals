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

    for (int k = 0; k < n_frames; k++)
        frames[k] = -1;
    int index, farthest, next_occurence;
    for (int i = 0; i < n_pages; i++)
    {
        check = 'F';
        for (int j = 0; j < n_frames; j++)
        {
            if (pg_stream[i] == frames[j])
            {
                hit_count++;
                check = 'H';
            }
        }
        if (check != 'H')
        {
            index = -1;
            farthest = 0;
            for (int j = 0; j < n_frames; j++)
            {
                next_occurence = -1;
                for (int k = i + 1; k < n_pages; k++)
                {
                    if (frames[j] == pg_stream[k])
                    {
                        next_occurence = k;
                        break;
                    }
                }
                if (next_occurence == -1)
                {
                    index = j;
                    break;
                }
                if (next_occurence > farthest)
                {
                    farthest = next_occurence;
                    index = j;
                }
            }
            frames[index] = pg_stream[i];
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