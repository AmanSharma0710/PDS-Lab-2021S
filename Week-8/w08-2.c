//Aman Sharma
//20EC10007
#include <stdio.h>

int main(){
    char *x = "Aman";
    char *y = "Sharma";
    int i;


    printf("32 bytes starting from x[0]:\n");
    for (i=0; i<32; i++){//We print upto 32 as name size=4
        printf("x[%03d]: %p --> ", i, (void *)(x+i));
        if (*(x+i)=='\n'||*(x+i)=='\0'){//If null or newline is present, we print #
        //We could have also used ((x+i)=='\n'||(x+i)=='\0')? '#':(x+i), but this is more readable
            printf("# = %d\n", (int)*(x+i));
        }
        else {
            printf("%c = %d\n", *(x+i), (int)*(x+i));
        }
    }    


    printf("\n32 bytes starting from y[0]:\n");//Printing from y
    for (i=0; i<32; i++){
        printf("y[%03d]: %p --> ", i, (void *)(y+i));
        if (*(y+i)=='\n'||*(y+i)=='\0'){
            printf("# = %d\n", (int)*(y+i));
        }
        else {
            printf("%c = %d\n", *(y+i), (int)*(y+i));
        }
    }

    x=y;//Changing value of x to now point to &y
    printf("\nAfter x is modified to y: \n");
    printf("\n144 bytes starting from x[0]:\n");//printing 4k values from x[0]
    for (i=0; i<144; i++){
        printf("x[%03d]: %p --> ", i, (void *)(x+i));
        if (*(x+i)=='\n'||*(x+i)=='\0'){
            printf("# = %d\n", (int)*(x+i));
        }
        else {
            printf("%c = %d\n", *(x+i), (int)*(x+i));
        }
    } 

    return 0;
}