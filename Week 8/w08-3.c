//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>

void shiftRight(int* a, int n)
{
    int temp = a[n-1];//Store the last element, then shift everything else right by 1 index
    for(int i = n-1 ; i >= 1 ; i--){
        a[i] = a[i-1];
    }
    a[0] = temp;//Replace the first element with the last element
}

void print_array(int *a, int n){//Function to print elements of an array, right-aligned
    for(int i = 0 ; i < n ; i++){
        if (*(a+i) >=0){
           printf("  %d", *(a+i));
        }
        else {
           printf(" %d", *(a+i));
        }
    }
}

int main(){
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));//Alloting memory

    printf("Enter %d integers: ", n);
    for(int i = 0 ; i < n ; i++){//Taking Input
        scanf("%d", a+i);
    }
    printf("\nInput elements:");
    print_array(a, n);
    for(int i = 1 ; i <= n ; i++){//Right shifting and printing the arrays
        printf("\nAfter shift %d: ", i);
        shiftRight(a, n);
        print_array(a, n);
        }
    return 0;
}
