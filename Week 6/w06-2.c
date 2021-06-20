/*Aman Sharma
  20EC10007*/
#include <stdio.h>

int power(int k, int j){//power calculator
    int x=1;
    for (int i=0; i<j; i++){
        x*=k;
    }
    return x;
    }


void printpermutation(int arr[], int size)//prints arr with proper formatting
{
    int sum=0;
    for (int i=0; i< size; i++){
        sum+=arr[i]*power(10,i);
    }
    printf("%*d ", size, sum);
}

void exchange(int arr[], int x, int y)//Helper function to swap two values in an arr
{
  int tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

void permutearray(int arr[], int l, int r)//Calls recursion by fixing one digit and permuting the others
{
    if(l == r)
    {
        if (arr[r]%10 == 0){
            printf("\n");
        }
      printpermutation(arr, r);
      arr[r]++;//increment the count when we print the arr
      return;
    }
        for(int i=r-1; i>=l; i--)
    {
        exchange(arr, r, i);
        permutearray(arr,l,r-1);
        exchange(arr, r, i);
    }
    
}


int main()
{
  printf("Enter the no of digits : ");
  int n;
  scanf("%d", &n);
  int arr[n+1];
  arr[n] = 0;
  printf("Enter the numbers : ");
  for (int i = 0; i< n; i++)
  {
      scanf("%d",&arr[i]);
  }
  printf("Numbers:");
  permutearray(arr,0,n);
  printf("\nCount = %d.", arr[n]);//we add an extra element to the arr and use it to store the count
  return 0;
}
