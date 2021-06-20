/*Aman Sharma
  20EC10007*/
#include <stdio.h>
//recursive function that calculates and returns nCr
int nCr(int n, int r){
    if (r==0 || r==n){
        return 1;//base case
    }
    else return nCr(n-1, r-1) + nCr(n-1, r);//recursive case
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Result:");
    for (int i=0; i<=n; i++){
        printf(" %d", nCr(n, i));//Loop that prints value of nCr for all r from 0 to n
    }
    return 0;
}
