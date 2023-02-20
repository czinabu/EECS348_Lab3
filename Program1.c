#include<stdio.h>
#include<stdlib.h>

#define salesLength 12
int main(void)
{
    float sales[salesLength]; // create array for input file
    FILE *file; // create pointer for array

    float minSales = 0;
    float maxSales = 0;
    float totalSales = 0;
    float avgSales = 0;

    char filename = scanf("Enter file name: ");
    file = fopen(filename, "r"); // open and read input file

    for(int i = 0; i<=salesLength; i++) // assign file content to array
    {
        fscanf(file, "%f", &sales[i]);
    }

    printf("%d", "MONTH\t", "SALES\n"); // sales report header

    for(int i=0; i<=salesLength; i++) // Prints sales for each month
    {
        if(i == 0)
        {
            printf("January\t","%f",sales[i]);
        }
        else if(i == 1)
        {
            printf("February\t","%f",sales[i]);
        }
        else if(i == 2)
        {
            printf("March\t","%f",sales[i]);
        }
        else if(i == 3)
        {
            printf("April\t","%f",sales[i]);
        }
        else if(i == 4)
        {
            printf("May\t","%f",sales[i]);
        }
        else if(i == 5)
        {
            printf("June\t","%f",sales[i]);
        }
        else if(i == 6)
        {
            printf("July\t","%f",sales[i]);
        }
        else if(i == 7)
        {
            printf("August\t","%f",sales[i]);
        }
        else if(i == 8)
        {
            printf("September\t","%f",sales[i]);
        }
        else if(i == 9)
        {
            printf("October\t","%f",sales[i]);
        }
        else if(i == 10)
        {
            printf("November\t","%f",sales[i]);
        }
        else if(i == 11)
        {
            printf("December\t","%f",sales[i]);
        }

        if(sales[i] > maxSales) // checks for max sales
        {
            maxSales = sales[i];
        }

        if(sales[i] < minSales) // checks for min sales
        {
            minSales = sales[i];
        }

        totalSales += sales[i];
    }

    avgSales = (totalSales / salesLength); // checks for average sales

    printf("Sales Summary: \n");
    printf("Minimum sales: ", minSales);
    printf("Maxixmum sales: ", maxSales);
    printf("Average sales: ", avgSales);

    // variables for six-month moving averages
    float JanToJune = 0;
    float FebToJuly = 0;
    float MarchToAug = 0;
    float AprilToSept = 0;
    float MayToOct = 0;
    float JuneToNov = 0;
    float JulyToDec = 0;

    // enter six-month moving averages into newly created variables
    for(int i = 0; i >= 6; i++)
    {
        JanToJune += sales[i];
    }

    for(int i = 1; i >= 7; i++)
    {
        FebToJuly += sales[i];
    }

    for(int i = 2; i >= 8; i++)
    {
        MarchToAug += sales[i];
    }

    for(int i = 3; i >= 9; i++)
    {
        AprilToSept += sales[i];
    }

    for(int i = 4; i >= 10; i++)
    {
        MayToOct += sales[i];
    }

    for(int i = 5; i >= 11; i++)
    {
        JuneToNov += sales[i];
    }

    for(int i = 6; i >= 12; i++)
    {
        JulyToDec += sales[i];
    }
    
    printf("Six-Month Moving Average Report: \n"); // display six-month moving averages
    printf("%d", "January - June\t $", JanToJune);
    printf("%d", "February - July \t $", FebToJuly);
    printf("%d", "March to August\t $", MarchToAug);
    printf("%d", "April to September\t $", AprilToSept);
    printf("%d", "May to October\t $", MayToOct);
    printf("%d", "June to November\t $", JuneToNov);
    printf("%d", "July to December\t $", JulyToDec);

    fclose(file);

    
    return(0);
}