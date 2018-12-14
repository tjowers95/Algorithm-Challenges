/*This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?*/
#include <stdio.h>

int testSum(int* a, int k)
{
    int i = 0, j = 0;
    while(a[i])
    {
        j = i + 1;
       while(a[i+j])
       {
           if (a[i+j] + a[i] == k)
           {
               return 1;
           }
           j++;
       } 
       i++;
    }
    return 0;
}

int main(void)
{
    int a[5] = {10,15,3,7};
    printf("%d\n",testSum(a,13));
}
//Returns 1 for true and 0 for false
