/*Aman Sharma
  20EC10007*/
#include <stdio.h>

int main() {
    unsigned int n, m = 0, i, pow = 1;
    printf("Enter n: \n");
    scanf("%d", &n);
    /*We run the below program 4 times for max 4 digits of n*/
    for (i=1; i<=4; i++) {
        /*If digit is prime, let's say 2, we convert it to 23 i.e. convert x to 10x + (x+1) = 11x + 1 and add it to m at appropriate position*/
        /*Before adding to m, it is multiplied by pow which ensures the digits and the further digits are added at proper place values*/
        if ((n%10==2)||(n%10==3)||(n%10==5)||(n%10==7)) {
            m += ((n%10)*11 + 1)*pow;
            pow *= 100;
        }
        /*If not prime, we simply add the digit to m at appropriate place(using counter variable pow)*/
        else {
            m += (n%10)*pow;
            pow *= 10;
        }
    /*We use integer division after every iteration to reduce n by 1 digit i.e. is n is 123, after one iteration it will become 12*/
    n /= 10;
    }
    /*We print the required output*/
    printf("m = %d.", m);
    return 0;
    }
