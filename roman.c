#include<stdio.h>
#include<string.h>
#include "help.h"
int main()
{
    while(1)
    {
        int choice;
        printf("Select a choice: \n 1.Addition \n 2.Multiplication \n 3.Exit \n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            char romannum1[1000],romannum2[1000];
            printf("Enter two roman numeral: ");
            scanf("%s %s", romannum1,romannum2);
            long int decimalnum1=romantodeci(romannum1);
            long int decimalnum2=romantodeci(romannum2);
            if(decimalnum1==-1 || decimalnum2==-1)
            {
                break;
            }
            else
            {
                long int sum=decimalnum1+decimalnum2;
                printf("Sum is: ");
                decitoroman(sum);
                printf("\n");
            }
        }
        else if(choice==2)
        {
            char romannum1[1000],romannum2[1000];
            printf("Enter two roman numeral: ");
            scanf("%s %s",romannum1,romannum2);
            long int decimalnum1=romantodeci(romannum1);
            long int decimalnum2=romantodeci(romannum2);
            if(decimalnum1==-1 || decimalnum2==-1)
            {
                break;
            }
            else
            {
                long int product=decimalnum1*decimalnum2;
                printf("Product is: ");
                decitoroman(product);
                printf("\n");
            }
        }
        else
        {
            printf("Exiting..");
            break;
        }
    }
    return 0;
}
