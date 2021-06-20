/*Name: Aman Sharma
  Roll no.: 20EC10007*/
//The code uses only the 6 variables entered and 7 comparisons.
#include <stdio.h>

int main(){
    int a, b, c, d, e, f;
    printf("Enter 6 integers:");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    //Purpose of each if statement: IF condition is true, it swaps the numbers.
    /*The program can be made much more efficient by defining a function
    void swap(int x, int y) {
    x = x + y;
    y = x - y;
    x = x - y;
    }*/

    if (b > a)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (d > c)
    {
        d = d + c;
        c = d - c;
        d = d - c;
    }
    if (f > e)
        {
        f = f + e;
        e = f - e;
        f = f - e;
    }
    //The above three if statements sort the values such that now a>b, c>d and e>f
    //That means the max value is in a, c or e and min value is in b, d or f
    if (c > a)
    {
        a = a + c;
        c = a - c;
        a = a - c;
    }
    //Now a>c, we need to check only for e and then store maximum value in a
    if (e > a)
    {
        a = a + e;
        e = a - e;
        a = a - e;
    }
    //Now a has the max value
    if (b < d)
    {
        b = b + d;
        d = b - d;
        b = b - d;
    }
    if (d < f)
    {
        d = d + f;
        f = d - f;
        d = d - f;
    }
    //After these two swaps f has the minimum value
    printf("Min, Max = %d, %d", f, a);
    return 0;
}
