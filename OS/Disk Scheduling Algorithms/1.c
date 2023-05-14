#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_tracks, n_reqs, diff, total_tr = 0, rw_head;
    int req[30], movements[30];

    printf("Enter total number of tracks : ");
    scanf("%d", &n_tracks);

    printf("Enter  number of requests to be placed on track : ");
    scanf("%d", &n_reqs);

    for (int i = 0; i < n_reqs; i++)
    {
        printf("Enter request %d ", i + 1);
        scanf("%d", &req[i]);
    }
    printf("\n");
    printf("Enter the position of Read Write Head : ");
    scanf("%d", &rw_head);

    printf("Track Movements are : \n");
    printf("%d-->", rw_head);

    for (int i = 0; i < n_reqs; i++)
    {
        diff = abs(rw_head - req[i]);
        total_tr = total_tr + diff;
        movements[i] = req[i];
        rw_head = req[i];
    }
    for (int i = 0; i < n_reqs; i++)
    {
        if (i < n_reqs - 1)
        {
            printf("%d-->", movements[i]);
        }
        else
        {
            printf("%d", movements[i]);
        }
    }
    printf("\nTotal Track Movements is: %d", total_tr);
}
