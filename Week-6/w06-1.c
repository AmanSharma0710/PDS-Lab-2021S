/*Aman Sharma
  20EC10007*/
#include <stdio.h>

void print_digits(int x, int i, int n){
    if (i<=n*n){//recursive case
        printf("%d", (x/n +1)%2);//maintains count and prints 0 or 1
        print_digits(x+1, i+1, n);//calls recursion
    }
    else return;//base case
}

void print_squares(int i, int n){
    if (i*i<=n){//check if square is valid or breaks loop
        printf("%d = ", i*i);
        print_digits(0, 1, i);//calls the function to print the string
        printf("\n");
        print_squares(i+1, n);
    }
    else return;
}


int main(){
    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);
    print_squares(1, n);
    return 0;
}
