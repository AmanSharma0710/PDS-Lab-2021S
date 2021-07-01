/*Name: Aman Sharma
  Roll no.: 20EC10007*/

#include <stdio.h>
#define MAX_N 6//We can change the number of lines of output by changing value here

int main() {
    int n;
    unsigned long int  num = 2, den = 1, a, b, t;
    //We use for loop to calculate for increasing values of n
    for (n=2; n <= MAX_N; n++) {
        t = num;//Saves value of numerator for using in calculation of den as num itself will get altered in next line
        num = 2*den*den + num*num;
        den = 2*t*den;
        //The formula in above two lines is from changing x to num/den and considering it a fraction always
        a = num;
        b = den;
        while(a!=b){
            if(a > b) a -= b;
            else b -= a;
            }
        //This algorithm finds the gcd of num and den
        num /= a;
        den /= a;//Division by gcd to get reduced fraction
        printf("n = %d: %ld / %ld = %f\n", n, num, den, ((float)num)/den);//Prints the required output
    }
    return 0;
}
