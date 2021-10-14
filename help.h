#include<stdio.h>
#include<string.h>
typedef long int li;
int digit(char ch)
{
    int val=0;
    switch (ch)
    {
    case 'I':
        val=1;
        break;
    case 'V':
        val=5;
        break;
    case 'X':
        val=10;
        break;
    case 'L':
        val=50;
        break;
    case 'C':
        val=100;
        break;
    case 'D':
        val=500;
        break;
    case 'M':
        val=1000;
        break;
    case '\0':
        val=0;
        break;
    default:
        val=-1;
    }
    return val;
}
li romantodeci(char roman[])
{
    int i=0;
    li num=0;
    while(roman[i])
    {
        if(digit(roman[i])<0)
        {
            printf("Invalid roman literal");
            return -1;
        }
        if((strlen(roman)-1)>2)
        {
            if(digit(roman[i])<digit(roman[i+2]))
            {
                printf("Invalid roman literal");
                return -1;
            }
        }
        if(digit(roman[i])>=digit(roman[i+1]))
        {
            num+=digit(roman[i]);
        }
        else
        {
            num+=digit(roman[i+1])-digit(roman[i]);
            i++;
        }
        i++;
    }
    return num;
}
int decitoroman(li num)
{
    if(num<=0)
    {
        return -1;
    }
    while(num!=0)
    {
        if(num>=1000)
        {
            printf("M");
            num-=1000;
        }
        else if(num>=900)
        {
            printf("CM");
            num-=900;
        }
        else if(num>=500)
        {
            printf("D");
            num-=500;
        }
        else if(num>=400)
        {
            printf("CD");
            num-=400;
        }
        else if(num>=100)
        {
            printf("C");
            num-=100;
        }
        else if(num>=90)
        {
            printf("XC");
            num-=90;
        }
        else if(num>=50)
        {
            printf("L");
            num-=50;
        }
        else if(num>=40)
        {
            printf("XL");
            num-=40;
        }
        else if(num>=10)
        {
            printf("X");
            num-=10;
        }
        else if(num>=9)
        {
            printf("IX");
            num-=9;
        }
        else if(num>=5)
        {
            printf("V");
            num-=5;
        }
        else if(num>=4)
        {
            printf("IV");
            num-=4;
        }
        else if(num>=1)
        {
            printf("I");
            num-=1;
        }
    }
    return 1;
}
int validunary(char unary[])
{
    int i=0;
    while(unary[i])
    {
        if(unary[i]!='1')
        {
            return -1;
        }
        i++;
    }
    return 1;
}
li binaryproduct(li binary1,li binary2)
{
    int i=0,reminder=0,sum[20];
    li binaryprod=0;
    while(binary1!=0 || binary2!=0)
    {
        sum[i++]=(binary1%10 + binary2%10 + reminder)%2;
        reminder=(binary1%10 + binary2%10 + reminder)/2;
        binary1=binary1/10;
        binary2=binary2/10;
    }
    if(reminder!=0)
    {
        sum[i++]=reminder;
        i--;
    }
    while(i>=0)
    {
        binaryprod=binaryprod*10 + sum[i--];
    }
    return binaryprod;
}
