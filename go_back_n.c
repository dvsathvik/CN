#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int w, n, ss, cur = 0;
bool *l;

void sender()
{
    if (ss > cur)
    {
        printf("Sender: Timeout occurred for Packet %d (Seq: %d) - Retransmitting Packets from %d\n\n", cur, cur, cur);
    }
    for (int i = cur; i < cur + w && i < n; i++)
    {
        printf("Sender: Sending packet %d (seq: %d)\n", i, i);
    }
}

void reciever()
{
    bool lost = false, k;
    for (int i = cur; i < cur + w && i < n; i++)
    {
        if (lost)
        {
            printf("Receiver: Packet %d Discarded (seq: %d) - No ACK sent\n", i, i);
        }
        else if (l[i] == true)
        {
            l[i] = false;
            lost = true;
            printf("Receiver: Packet %d lost (Seq: %d) - No ACK sent\n", i, i);
            k = i;
            continue;
        }
        else
        {
            printf("Receiver: Received Packet %d (Seq: %d) - Sending ACK %d\n", i, i, i);
        }
    }
    if (!lost)
    {
        cur = cur + w;
    }
    else
    {
        cur = k;
    }
}
void main()
{
    printf("Enter the window Size and number of packets to be transmitted: \t");
    scanf("%d %d", &w, &n);

    l = (bool *)malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++)
    {
        l[i] = false;
    }

    printf("Enter the packets Lost and -1 to exit:\t");

    int i = 0;
    while (i != -1)
    {
        scanf("%d", &i);
        if (i != -1)
        {
            l[i] = true;
        }
    }

    while (cur < n)
    {
        sender();
        reciever();
    }
    free(l);
}