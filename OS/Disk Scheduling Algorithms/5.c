#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, temp, diff, n_tracks, rw_head, n_reqs, total_tr = 0;
    int req[100], movement[100];
    printf("Enter the number of tracks : ");
    scanf("%d", &n_tracks);
    printf("Enter the number of requests : ");
    scanf("%d", &n_reqs);
    for (i = 0; i < n_reqs; i++)
    {
        printf("Enter the request track %d : ", i + 1);
        scanf("%d", &req[i]);
    }
    printf("Enter the read write head : ");
    scanf("%d", &rw_head);
    printf("The track movements are : \n");
    printf("%d -->", rw_head);

    for (int i = 0; i < n_reqs; i++)
    {
        for (int j = 0; j < n_reqs - i - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n_reqs; i++)
    {
        if (req[i] > rw_head)
        {
            temp = i;
            break;
        }
    }
    j = 0;
    for (int i = temp; i < n_reqs; i++)
    {
        diff = abs(rw_head - req[i]);
        total_tr += diff;
        movement[j] = req[i];
        j++;
        rw_head = req[i];
    }

    for (i = temp - 1; i >= 0; i--)
    {
        diff = abs(rw_head - req[i]);
        total_tr += diff;
        movement[j] = req[i];
        j++;
        rw_head = req[i];
    }

    for (i = 0; i < j; i++)
    {
        if (i < j - 1)
            printf("\t%d -->", movement[i]);
        else
            printf("\t%d", movement[i]);
    }

    printf("\nThe total track movement is %d \n", total_tr);
}
