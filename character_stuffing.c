#include <stdio.h>
#include <string.h>
void main()
{
    char str[25];
    printf("Enter the data:\t");
    scanf("%s",&str);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'e' || str[i] == 'f')
        {
            printf(" e ");
        }
        printf(" %c ", str[i]);
    }
}