#include <stdio.h>
#include <stdlib.h>

int size_of_generator,size_of_data;
int *generator,*data;

int XOR(int a,int b)
{
    if (a == b)
    {
        return 0;
    }
    return 1;
}

void CRC()
{
    int current_index = 0;
    while (current_index < size_of_data)
    {
        if (data[current_index] == 0)
        {
            current_index++;
            continue;
        }
        for (int i = 0; i < size_of_generator; i++)
        {
            data[current_index+i] = XOR(data[current_index+i],generator[i]);
        }
    }
    
    printf("Reaminder:\t");
    for (int i = size_of_data; i < size_of_data+size_of_generator-1; i++)
    {
        printf(" %d ",data[i]);
    }
}

void main()
{
    printf("Enter the size of Generator:\t");
    scanf("%d",&size_of_generator);
    generator = (int *)malloc(sizeof(int)*size_of_generator);
    printf("Enter Generator:\t");
    for (int i = 0; i < size_of_generator; i++)
    {
        scanf("%d",&generator[i]);
    }
    printf("Enter the size of Data:\t");
    scanf("%d",&size_of_data);
    printf("Enter Data:\t");
    data = (int *)malloc(sizeof(int)*(size_of_data + size_of_generator - 1));
    for (int i = 0; i < size_of_data; i++)
    {
        scanf("%d",&data[i]);
    }
    for (int i = size_of_data; i < size_of_data+size_of_generator-1; i++)
    {
        data[i] = 0;
    }
    

    CRC();

    free(data);
    free(generator);
    
}