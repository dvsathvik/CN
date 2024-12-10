#include<stdio.h>
#include <math.h>
void main()
{
    int header,Packet_size,MTU;
    printf("Enter the Header size, Packet Size , MTU :\t");
    scanf("%d %d %d",&header,&Packet_size,&MTU);

    int n = ceil((float)(Packet_size-header)/(MTU-header));

    printf("Fragment-Number  DF     MF      \toffset\t\tSize\n");
    for (int i = 1; i <= n; i++)
    {
        if (i < n)
        {
            printf("%d\t\t1\t 1\t\t%d\t\t%d\n",i,(i-1)*(MTU-header),MTU);
        }
        else
        {
            printf("%d\t\t1\t0\t\t%d\t\t%d\n",i,(i-1)*(MTU-header),(Packet_size - (i-1)*(MTU-header) ));
        }
    }
}