#include<stdio.h>
#include "help.h"

int main()
{
    while(1)
    {
        int choice;
        printf("Select a choice: \n 1. Addition \n 2. Multiplication \n 3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            long b1,b2;
            printf("Enter two binary no.s: ");
            scanf("%ld %ld",&b1,&b2);
            int i=0,rem=0,sum[20];
            while(b1!=0 || b2!=0)
            {
                sum[i++]=(b1%10 + b2%10 + rem)%2;
                rem=(b1%10 + b2%10 + rem)/2;
                b1=b1/10;
                b2=b2/10;
            }
            if(rem!=0)
            {
                sum[i++]=rem;
                i--;
                printf("Sum is: ");
                while(i>=0)
                { 
                    printf("%d\n",sum[i--]);
                }
            }
        }
        else if(choice==2)
        {
            long b1,b2,multiply=0;
            printf("Enter two binary no.s: ");
            scanf("%ld %ld",&b1,&b2);
            int digit,factor=1;
            while(b2!=0)
            {
                digit=b2%10;
                if(digit==1)
                {
                    b1=b1*factor;
                    multiply=binaryproduct(b1,multiply);
                }
                else
                {
                    b1=b1*factor;
                    b2=b2/10;
                    factor=10;
                }
            }
            printf("Product is: %ld\n",multiply);
        }
        else
        {
            printf("Exiting..");
            break;
        }
    }
    return 0;
}
