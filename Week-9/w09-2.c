//Aman Sharma
//20EC10007
#include <stdio.h>
#include <stdlib.h>

typedef struct {//Declaring structure
    int x;
    int y;
    int x1;
    int y1;
} rectangle;

int checker(rectangle* a, int n, int x_coord, int y_coord){//Checks if point is inside any of the rectangles, if it is returns 1, else returns 0
    for (int i=0; i<n; i++){
        if ((x_coord>=a[i].x) && (x_coord<=a[i].x1) && (y_coord>a[i].y) && (y_coord<=a[i].y1)){//Checking for each rectangle
            return 1;
        }
    }
    return 0;
}


//With r = 07, M = 0 + 7 + 40 = 47
int main(){
    int n;
    printf("Enter #rectangles: ");                 //Input size of array
    scanf("%d", &n);
    rectangle* a = (rectangle*)malloc(n * sizeof(rectangle));  //Allocating memory for array of rectangles
    printf("Enter BOTTOM-LEFT and TOP-RIGHT coordinates (value: 1 to 47):\n"); 
    for (int i=0; i<n; i++){
        scanf("%d%d%d%d", &(a[i].x), &(a[i].y), &(a[i].x1), &(a[i].y1));//Taking input of coordinates for all the rectangles
    }
    printf("\n\n");
    for (int k=46; k>=0; k--){
        for (int j=0; j<47; j++){
            if (checker(a, n, j, k)) printf(" ");//If point lies inside rectangles, we print space
            else printf("%c", (char)47);//Else we print character with ASCII = 47
        }
        printf("\n");
    }
    return 0;
}