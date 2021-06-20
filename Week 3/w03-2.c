/*Aman Sharma
  20EC10007*/
#include <stdio.h>

int main() {
    float a, b, c, d, u, v, val_u, val_v, w, val_w;
    /*Take inputs*/
    printf("Enter a, b, c, d: \n");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    printf("Enter u, v: \n");
    scanf("%f%f", &u, &v);
    /*Calculate midvalue using another variable so that program is more compact*/
    w = (u + v)/2.0;
    /*Calculate f(u) and f(v)*/
    val_u = a + b*u + c*u*u + d*u*u*u;
    val_v = a + b*v + c*v*v + d*v*v*v;
    /*First we take case when there is a root in u to v*/
    if ((val_u*val_v)<=0) {
        printf("[%f, %f]: YES\n", u, v);
        /*We calculate f((u+v)/2) and print whether there are roots in [u, (u+v)/2] and [(u+v)/2, v] or not*/
        val_w = a + b*w + c*w*w + d*w*w*w;
        if ((val_u*val_w)<=0) printf("[%f, %f]: YES\n", u, w);
        else printf("[%f, %f]: NO\n", u, w);
        if ((val_w*val_v)<=0) printf("[%f, %f]: YES\n", w, v);
        else printf("[%f, %f]: NO\n", w, v);
    }
    /*Now we take the case there is no root in u to v*/
    else printf("[%f, %f]: NO\n", u, v);
    return 0;
    }
