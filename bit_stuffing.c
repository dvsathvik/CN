#include <stdio.h>

void main()
{
    int n;
    printf("Enter the size of Unstuffed Data:\t");
    scanf("%d",&n);
    int data[n];
    printf("Enter the data:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data[i]);
    }
    printf("Stuffed Data:\t");
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        printf(" %d ",data[i]);
        if (data[i] == 1)
        {
            c++;
        }
        else
        {
            c = 0;
        }

        if (c == 5)
        {
            printf(" 0 ");
            c = 0;
        }
    }
}