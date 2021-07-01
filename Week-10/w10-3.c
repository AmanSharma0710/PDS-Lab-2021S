//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char n[20], s[20]; 
    float c; // name, surname, cgpa
}student;

int binary_search(student *arr, int l, int r, float x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;        //We find the mid value
  
        // If x is present at the middle
        // itself
        if (arr[mid].c == x)
            return mid;
  
        // If x is smaller than mid value, then
        // it can only be present in left subarray
        if (arr[mid].c > x)
            return binary_search(arr, l, mid - 1, x);
  
        // Else x can only be present
        // in right subarray
        return binary_search(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    if (arr[l].c>x){  //Case when element at index l is greater than l. We return l as we want all values from l to have cg > x
        return l;
    }
    else return l+1;  //If value at l is less than x, we return l+1. Since the l value will end up near the elements that contain x in the middle in this case, arr[l+1].c will be greater than x and thats what we want to print so we return l+
}

void printer(int x){         //helper function that prints '-' x number of times
    for (int i=0; i<x; i++){
        printf("-");
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


    printf("\nEnter the cut-off cgpa: ");                         //Taking input of cutoff
    float cg;
    scanf("%f", &cg);


    printf("Students with cgpa >= cut-off:\n");
    int index = binary_search(arr, 0, number, cg);                //function returns index from which values greater than cutoff cg start


    if (index>=number){                                           //Case when cutoff is > last element of array. in this case function will return index of last element +1
        printf("Empty!");                                         //Since this is not inside array bounds, we handle this case seperately
        return 0;
    }

    for (int i=index; i<number; i++){
        int x = strlen(arr[i].n) + strlen(arr[i].s);              //We subtract the length of names from total length of 30 to get number of "-" we need to print for proper formatting
        printf("%2d. %s %s ", i+1, arr[i].n, arr[i].s);
        printer(30-x);                                             
        printf("  %1.2f\n", arr[i].c);                            //Printing everything in required formatting
    }
    return 0;
}