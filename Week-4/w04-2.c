/*Name: Aman Sharma
  Roll no.: 20EC10007*/

#include <stdio.h>
int main() {
    int n, i, x, sum_last=0, sum_first=0, first;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
//We use for loop to take in n integers and
//compute the sum of last and first digits each time
    for (i=1; i<=n; i++) {
        scanf("%d", &x);
        sum_last += x%10;//Remainder with 10 gives the last digit and we add it to the sum
        first = x;//The while loop keeps removing the last digit of the number until a single digit is left. This will obviously be the first digit
        while (first>9) {
            first /= 10;
        }
        sum_first += first;//We add first digit to the sum
    }
    printf("sum = %d, %d.", sum_first, sum_last);
    return 0;
}
