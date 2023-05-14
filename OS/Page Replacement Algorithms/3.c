#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_pages, n_frames;
    int hit_count = 0;
    int fault_count = 0;
    int frames[50], pg_stream[50];
    float hit_ratio, miss_ratio;
    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages in the stream: ");
    scanf("%d", &n_pages);

    printf("Enter the stream:\n");

    for (int i = 0; i < n_pages; i++)
    {
        scanf("%d", &pg_stream[i]);
    }

    for (int k = 0; k < n_frames; k++)
        frames[k] = -1;

    int index, farthest, recent_count = 0;
    int recent[50];

    for (int i = 0; i < n_pages; i++)
    {
        char check = 'F';
        int page = pg_stream[i];

        for (int j = 0; j < n_frames; j++)
        {
            if (frames[j] == page)
            {
                hit_count++;
                check = 'H';
                recent[j] = recent_count;
                recent_count++;
                break;
            }
        }

        if (check != 'H')
        {
            int min_recent = recent[0];
            index = 0;

            for (int j = 1; j < n_frames; j++)
            {
                if (recent[j] < min_recent)
                {
                    min_recent = recent[j];
                    index = j;
                }
            }

            frames[index] = page;
            recent[index] = recent_count;
            recent_count++;
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

    printf("The total number of hits is %d\n", hit_count);
    printf("The total number of faults is %d\n", fault_count);
    printf("The hit ratio is %.2f\n", hit_ratio);
    printf("The miss ratio is %.2f\n", miss_ratio);

    return 0;
}