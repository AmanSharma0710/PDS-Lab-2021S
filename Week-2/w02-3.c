/*Name: Aman Sharma
  Roll no.: 20EC10007*/
#include <stdio.h>
int main() {
    int n, n1;
    printf("Enter n: ");
    scanf("%d", &n);
    n1 = 1000*(n%10) + n/10;
    printf("%d\n", n1);
    n1 = 1000*(n1%10) + n1/10;
    printf("%d\n", n1);
    n1 = 1000*(n1%10) + n1/10;
    printf("%d\n", n1);
    n1 = 1000*(n1%10) + n1/10;
    printf("%d\n", n1);
    return 0;
}
