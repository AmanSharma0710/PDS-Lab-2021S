/*Aman Sharma
  20EC10007*/
#include <stdio.h>

int main()
{
  int d, m, y;
  /*We take input*/
  printf("Enter the day, month, year: \n");
  scanf("%d%d%d", &d, &m, &y);
  /*Now depending on the month, we print the required outcome*/
  switch (m)
  {
  case 1:
  case 2:
    printf("It's Winter!");
    break;
  case 3:
  case 4:
  case 5:
    printf("It's Summer!");
    break;
  case 6:
  case 7:
  case 8:
  case 9:
    printf("It's Monsoon!");
    break;
  case 10:
  case 11:
    printf("It's Autumn!");
    break;
  case 12:
    printf("It's Winter!");
    break;
  }
  return 0;
}
