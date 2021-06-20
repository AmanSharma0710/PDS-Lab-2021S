/*Aman Sharma
  20EC10007*/

#include <stdio.h>

typedef struct {int x, y, z;} vector;
//We define both dot and cross product as required
int dot_product(vector a, vector b){
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector cross_product(vector a, vector b){
    vector temp;
    temp.x = a.y * b.z - a.z * b.y;
    temp.y = a.z * b.x - a.x * b.z;
    temp.z = a.x * b.y - a.y * b.x;
    return temp;
}

int main(){
    vector a, b, c;
    //Read vectors a and b
    printf("Enter vector a: ");
    scanf("%d %d %d", &a.x, &a.y, &a.z);
    printf("Enter vector b: ");
    scanf("%d %d %d", &b.x, &b.y, &b.z);
    //Calculate and print dot product
    printf("Dot product = %d.", dot_product(a, b));
    //Calculate and print cross product
    c = cross_product(a, b);
    printf("\nCross product = (%d, %d, %d).", c.x, c.y, c.z);
    return 0;
}
