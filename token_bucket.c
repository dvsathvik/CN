#include <stdio.h>

void main()
{
    int Bucket_size,Token_generation_rate,inflow,Tokens=0;

    printf("Enter the Bucket size and  Token Generation Rate: \t");
    scanf("%d %d",&Bucket_size,&Token_generation_rate);

    for (int i = 0; i < 15; i++)
    {
        printf("Enter the Data Inflow(-1 to exit):\t");
        scanf("%d",&inflow);
        Tokens = Tokens + Token_generation_rate;

        if (inflow == -1)
        {
            break;
        }

        if (Tokens >= inflow)
        {
            Tokens -= inflow;
        }
        else
        {
            printf("Packets OverLoaded.Packets Not Accepted\n");
        }

        printf("Remaining Token: \t%d\n",Tokens);
    }
}