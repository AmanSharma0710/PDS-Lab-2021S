/*Aman Sharma
  20EC10007*/
#include <stdio.h>
/*Function that takes a positive integer as input and gives reverses the digits*/
int reverse(int n){
    int reverse_number=0; //Initialize the reverse number
    //This loop keeps removing the last digit of n and adds it to reverse no.
    //while simultaneously multiplying by 10 to put numbers at proper place values
    while (n>0){
        reverse_number = 10*reverse_number + n%10; //n%10 adds last digit of n to reverse number
        n/=10; //reduces original n so next digit can be added to reverse no.
    }
    return reverse_number;
}
int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Reverse number = %d.", reverse(n));//Outputs the reverse number
    return 0;
}
