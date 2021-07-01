//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char n[20], s[20]; 
    float c; // name, surname, cgpa
}student;

void printer(int x){   //helper function that prints '-' x number of times
    for (int i=0; i<x; i++){
        printf("-");
    }
    return;
}

void InsertionSort (student *A, int size)    //insertion sort function
{
    int i, j;
    student item;     //Initialise a placeholder variable
    for (i=1; i<size; i++){  //Traverse throughout the array and keep sorting it until i
        item = A[i] ;        //This is the element that we will move to its proper place in 1 iteration
        for (j = i-1; j >= 0; j--){
            if (item.c < A[j].c){     //Until cgpa is greater than item value, we keep checking and carrying forward the student. when we find this value, we break the loop
                /* push elements down*/
                A[j+1] = A[j];
                A[j] = item ;
            }
            else break; /*inserted at proper place and exit loop */
            }
    }
    return;
}

int main(){
    int number;
    printf("Enter #students: ");
    scanf("%d", &number);
    student *arr = (student *)malloc(sizeof(student) * number);   //Dynamically allocating memory for array of students


    printf("Enter student name, surname, cgpa:\n");               //Taking in input for every student value
    for (int i=0; i<number; i++){
        scanf("%s %s %f", arr[i].n, arr[i].s, &arr[i].c);
    }


    printf("\n");
    printer(42);                                                  //Printing the required formatting
    printf("\nBEFORE SORTING:\n\n");


    for (int i=0; i<number; i++){
        int x = strlen(arr[i].n) + strlen(arr[i].s);              //We subtract the length of names from total length of 30 to get number of "-" we need to print for proper formatting
        printf("%2d. %s %s ", i+1, arr[i].n, arr[i].s);
        printer(30-x);
        printf("  %1.2f\n", arr[i].c);                            //Printing everything with proper formatting
    }


    InsertionSort(arr, number);                                   //Sort the student array according to cgpa


    printf("\n");
    printer(42);                                                  //Printing the required formatting
    printf("\nAFTER SORTING:\n\n");


    for (int i=0; i<number; i++){
        int x = strlen(arr[i].n) + strlen(arr[i].s);              //printing the sorted array in proper formatting
        printf("%2d. %s %s ", i+1, arr[i].n, arr[i].s);
        printer(30-x);
        printf("  %1.2f\n", arr[i].c);
    }
    return 0;
}