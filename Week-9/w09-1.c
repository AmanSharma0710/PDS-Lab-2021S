//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>

int power10(int x){             //helper function to calculate 10^(input)
    int power = 1;
    while (x>0){
        power*=10;
        x--;
    }
    return power;
}

int countDigit(int n)           //helper function that returns number of digits of input
{
    if (n/10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

int exchange(int x){            //Exchange function
    int lasttwo = x%(power10(2)), firsttwo, y;  //Declare variables and calculate last two digits
    int numberOfDigits = countDigit(x);         //Count number of digits using helper function and store it in variable
    if (numberOfDigits<4){                      //If number of digits is less than 4, we consider number still to be of 4 digits as this introduces padding with 0
        numberOfDigits=4;
    }
    firsttwo = x/(power10(numberOfDigits-2));   //Calculate the first two digits of number
    y = lasttwo*power10(numberOfDigits-2) + ((x%(power10(numberOfDigits-2)))/(power10(2)))*power10(2) + firsttwo;  //We explain each term below
    //First added term is the first two digits of the number x appropriately placed
    //Second added term is simply the number x with first and last 2 digits as 0 so that we can put their appropiate values in place
    //Third added term is the first two digits of x which now become the last two digits
    
    return y;                   //Return the new number
}


int main(){
    int n;
    printf("Enter n: ");          //Input size of array
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));//Allocating memory for array

    printf("Enter %d numbers: ", n);
    for(int i = 0 ; i < n ; i++){ //Taking Input of Array
        scanf("%d", a+i);
    }
    printf("New numbers = ");
    for(int i = 0 ; i < n ; i++){ //Applying the exchange function and printing output on each element of array
        *(a+i) = exchange(*(a+i));
        printf(" %9d", *(a+i));
    }
    printf("\nNumbers x 4 = ");   //S^2 <= 16 + 07 => S=4
    for(int i = 0 ; i < n ; i++){
        *(a+i) *= 4;              //Multiply each element by S
        printf(" %9d", *(a+i));   //Print each element
    }
    return 0;
}