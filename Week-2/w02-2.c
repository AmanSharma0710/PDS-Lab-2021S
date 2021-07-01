/*Name: Aman Sharma
  Roll no.: 20EC10007*/
#include <stdio.h>
int main() {
    float x, Answer;
    printf("Enter x: ");
    scanf("%f", &x);
    Answer = (1 - x*x*x*x*x*x*x*x)/(1-x);
    printf("Answer = %.10f", Answer);
    return 0;
}
