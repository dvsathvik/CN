#include <stdio.h>
#include <stdlib.h>
int w, n, *lost, *cor, a = 0, t = 0;
int *sq, si = 0, *rq, ri = 0;
void sender()
{
    ri = 0;
    if (t == n)
    {
        return;
    }
    for (int i = 0; i < w && i < si; i++)
    {
        if (sq[i] <= a)
        {
            printf("Sender : Retransmitting packet %d\n", sq[i]);
            rq[ri++] = sq[i];
        }
        else
        {
            printf("Sender : sending packet %d\n", sq[i]);
            rq[ri++] = sq[i];
            if (sq[i] > a)
            {
                a = sq[i];
            }
        }
    }
    printf("\n");
    receiver();
}

void receiver()
{
    si = 0;
    for (int i = 0; i < w && i < ri; i++)
    {
        if (t == n)
        {
            return;
        }

        if (lost[rq[i]])
        {
            lost[rq[i]] = 0;
            printf("Receiver : Packet lost %d\n", rq[i]);
            sq[si++] = rq[i];
        }
        else if (cor[rq[i]])
        {
            cor[rq[i]] = 0;
            printf("Receiver : Packet corrupted %d Sending Negative Ack\n", rq[i]);
            sq[si++] = rq[i];
        }
        else
        {
            printf("Receiver : Packet Received %d Sending Ack\n", rq[i]);
            t++;
        }
    }

    for (int i = a + 1; i < n && si < w; i++)
    {
        sq[si++] = i;
    }
    printf("\n");
    sender();
}

void main()
{
    printf("Enter the Window size and number of packets:\t");
    scanf("%d %d", &w, &n);
    lost = (int *)malloc(sizeof(int) * n);
    cor = (int *)malloc(sizeof(int) * n);
    sq = (int *)malloc(sizeof(int) * w);
    rq = (int *)malloc(sizeof(int) * w);
    for (int i = 0; i < n; i++)
    {
        lost[i] = cor[i] = 0;
    }
    printf("Enter the lost packets:\t");
    while (1)
    {
        int c;
        scanf("%d", &c);
        if (c > 0)
        {
            lost[c] = 1;
        }
        else
        {
            break;
        }
    }

    printf("Enter the corrupt packets:\t");
    while (1)
    {
        int c;
        scanf("%d", &c);
        if (c > 0)
        {
            cor[c] = 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < w; i++)
    {
        sq[si++] = i;
    }
    sender();
}