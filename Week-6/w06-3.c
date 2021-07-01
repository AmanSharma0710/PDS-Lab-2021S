/*Aman Sharma
  20EC10007*/
#include <stdio.h>

//Function to check if a number is in an array
int check_array(int arr[], int number, int upper){
    for (int i=0; i<upper; i++){
        if (arr[i]==number) {
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, i=0;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d distinct numbers:\n", n);
    scanf("%d", &arr[i++]);

    while (i<n){
        scanf("%d", &arr[i]);
        if (!check_array(arr, arr[i], i)){//If number is not in array, loop moves on to getting the next number
            i++;
        }
        else {
            printf("Number already exists; please enter a different number.\n");//If number already exists in array, loop will ask for number again
        }
    }
    //Printing the entered array
    printf("Numbers in the array:\n");
    for (int j=0; j<n; j++){
        printf("%d ", arr[j]);
    }

    int m;
    printf("\nEnter m: ");
    scanf("%d", &m);

    for (int i=0; i<m; i++){//We do bubble sort, but only m times since we just need the m smallest numbers
        for (int k=i+1; k<n; k++){
            if (arr[k]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
    //Printing the smallest m numbers in order
    printf("Smallest %d numbers in order:\n", m);
    for (int i=0; i<m; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
