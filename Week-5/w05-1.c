/*Aman Sharma
  20EC10007*/
#include <stdio.h>

int main() {
    //We can rewrite f(n) as f(n-1) + n*(f(n-1) - f(n-2))
    //So if we have value of f(1) and f(2), we can compute all others using this recursive form of the function

    //Creating the array
    int arr[12];
    arr[0] = 1;
    arr[1] = 3;
    //Filling up the array using loop and recursive function, i.e.
    //taking previous values from array and using them to calculate new values
    for(int j=2; j<12; j++){
        arr[j] = arr[j-1] + (j+1)*(arr[j-1]-arr[j-2]);//Uses multiplication only once
    }
    //Printing the array
    for (int i=0; i<12; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
