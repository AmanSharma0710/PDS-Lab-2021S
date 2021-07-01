//Aman Sharma
//20EC10007
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[20], unit[10];
    float price;
} item;

int main(){
    item s[] = {
        {"BUTTER COOKIES", "PACK", 25},
        {"CASHEW COOKIES", "PACK", 30},
        {"CREAM CAKE", "SLICE", 22},
        {"LEMON JUICE", "LITRE", 35},
        {"VEG CASHEW CAKE", "SLICE", 18},
        {"MANGO JUICE", "LITRE", 78},
        {"COOKIES (PLAIN)", "PACK", 15},
        {"ORANGE JUICE", "LITRE", 72},
        {"MILK BISCUITS", "PACK", 12},
        {"PLAIN VEG CAKE", "SLICE", 20},
        {"BUTTER FRUIT CAKE", "SLICE", 25},
        {"PINEAPPLE JUICE", "LITRE", 65}
    };
    char search[20], *ret;//Initialise placeholders for input substring and for checking if it is a substring
    int i=0, count=0;
    printf("Enter a keyword: ");
    scanf("%s", search);
    while (search[i]!='\0'){
        search[i] = toupper(search[i]);//Convert substring to upper as all strings are in uppercase
        i++;
    }
    printf("\n Items found matching with your keyword:\n");
    for (int j=0; j<12; j++){
        ret = NULL;
        ret = strstr(s[j].name, search);
        if (ret!=NULL){//If substring is found, we print the details in the required format
            printf("%2d: %s", j+1, s[j].name);
            int spaces = 20 - strlen(s[j].name);
            while (spaces-- >=0) printf(" ");
            printf("--- Rs.%.2f per %s\n", s[j].price, s[j].unit);
            count++;
        }
    }
    if (count==0){//If substring is not found, we print accordingly
        printf("Sorry, no such item is found...");
        return 0;
    }
    count=0, i=0;//Reusing count to hold choice number and i to hold quantity
    printf("\nEnter your choice: ");
    scanf("%d", &count);
    printf("Enter the quantity: ");
    scanf("%d", &i);
    printf("To pay (with GST) = Rs. %d.", (int)(1.1*(i*s[count-1].price)+0.5));//Printing the value rounded off
    return 0;
}