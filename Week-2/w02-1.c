/*Name: Aman Sharma
  Roll no.: 20EC10007*/
#include <stdio.h>
int main() {
    long long int a, b;
    printf("Enter a and b: ");
    scanf("%lld%lld", &a, &b);
    printf("a+b = %lld\na-b = %lld\na*b = %lld\na/b = %.6f", a+b, a-b, a*b, ((double)a)/b);
    return 0;
}
