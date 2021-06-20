/*Aman Sharma
  20EC10007*/

#include <stdio.h>
#include <math.h>

typedef struct {int x, y;} point;

typedef struct {
    point a[3];
} triangle;

double area(triangle t){//We calculate area of a triangle t using coordinate geometry formula
    float x1 = t.a[0].x, x2 = t.a[1].x, x3 = t.a[2].x;
    float y1 = t.a[0].y, y2 = t.a[1].y, y3 = t.a[2].y;
    return fabs(x1*( y2 - y3 ) + x2*( y3 - y1 ) + x3*( y1 - y2 ))*0.5;
}

int inside(point p, triangle t){
    double error;
    //we make 3 triangles PAB, PAC, PBC and if PAB + PAC + PBC = ABC,
    //then point lies inside the triangle and we return 1
    triangle t1 = {.a[1] = t.a[1], .a[2] = t.a[2], .a[0].x = p.x, .a[0].y = p.y};
    triangle t2 = {.a[0] = t.a[0], .a[2] = t.a[2], .a[1].x = p.x, .a[1].y = p.y};
    triangle t3 = {.a[0] = t.a[0], .a[1] = t.a[1], .a[2].x = p.x, .a[2].y = p.y};
    error = area(t) - area(t1) - area(t2) - area(t3);
    if (fabs(error)<=0.001) return 1;//Considering the error term
    else return 0;
}

int main(){
    triangle arr[9];
    int n;
    point p;
    printf("Enter #triangles: ");
    scanf("%d", &n);
    printf("Enter triangle coordinates: \n");
    for (int i=0; i<n; i++){//Read all the triangles into the array of triangles
        scanf("%d%d%d%d%d%d", &arr[i].a[0].x, &arr[i].a[0].y, &arr[i].a[1].x, &arr[i].a[1].y, &arr[i].a[2].x, &arr[i].a[2].y);
    }
    int canvas[20][40];//Create an array which we can simply print in the end
    for (int i=0; i<20; i++){
        for (int j=0; j<40; j++){
            canvas[i][j] = 0;//will initialize every point as 0
            p.x = j+1;//To get proper indexing
            p.y = i+1;
            for (int k = 0; k<n; k++){
                if (inside(p, arr[k])) {
                    canvas[i][j] = k+1;//If point lies within a triangle, we store the #of triangle in the array
                    break;//so that the smallest triangle that has the point is stored
                    }
            }
        }
    }
    for (int i=19; i>-1; i--){//Now we print the array, mirrored across the x axis as our data lies in the first quadrant
        for (int j=0; j<40; j++){
            if (canvas[i][j] == 0){
                printf(" ");//Print a blank if array element is 0, i.e., point is not inside any triangle
            }
            else printf("%d", canvas[i][j]);//Print the triangle
        }
        printf("\n");
    }
    return 0;
}
