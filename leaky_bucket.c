#include <stdio.h>
void main()
{
    int bucket_size,output_rate,current = 0,ind;
    printf("Enter the Bucket Size and output rate:\t");
    scanf("%d %d",&bucket_size,&output_rate);
    for (int i = 1; i < 100; i++)
    {
        printf("Enter the Inflow of the Data(-1 to exit):\t");
        scanf("%d",&ind);
        if (ind == -1)
        {
            break;
        }
        current += ind;
        current -= output_rate;
        if (current < 0)
        {
            current = 0;
        }
        if (current > bucket_size)
        {
            printf("Buffer Oveloaded   packets Droped\n");
            current = bucket_size;
        }
        printf("Current Buffer Size :- \t%d\n",current);
    }
}