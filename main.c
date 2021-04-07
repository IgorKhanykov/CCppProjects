#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * pFile;
    char * cpBuffer=0;
    long lLenght;
    // 1.Read data from file into buffer
    pFile = fopen("input.txt", "r");
    if (pFile==NULL)
    {
        perror("Error opening file!");
        getchar();
        exit(1);
    }
    else
    {
        fseek (pFile, 0, SEEK_END);
        lLenght = ftell (pFile);
        fseek (pFile, 0, SEEK_SET);
        cpBuffer = malloc (lLenght);
        if (cpBuffer)
        {
           fread (cpBuffer, 1, lLenght, pFile);
        }
        fclose(pFile);
    }

    //2.Parse integers in buffer
    char *cpPtr;
    long int liRet1, liRet2;
    liRet1=strtol(cpBuffer, &cpPtr, 10);
    printf("\nFirst integer number is %ld.", liRet1);
    liRet2=strtol(cpPtr, &cpPtr, 10);
    printf("\nSecond integer number is %ld.", liRet2);

    //3. Sum of integers
    long int liSum=liRet1+liRet2;
    printf("\nSum is %ld.",liSum);

    //4. Write data to file
    pFile=fopen("output.txt","w");
    if(pFile)
    {
        fprintf(pFile, "%ld",liSum);
    }
    else
    {
        perror("Output file error");
        exit(1);
    }

    return 0;
}
