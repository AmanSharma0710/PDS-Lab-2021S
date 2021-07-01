//Aman Sharma
//20EC10007
#include <stdio.h>
//r = 07, 7%11 + 7%13 + 17 = 31
//p=31
int main(){
    printf("Enter a string of at most 100 characters: ");  //Taking the input string
    char s[101],stringconsidered[32];  //Declare array for input and string to be used, size+1 to accomodate null character
    scanf("%s",s);
    int length=0;
    while(s[length]!='\0'){ //Copy string into stringconsidered until either full string is copied or max length is reached
        if(length==31){
            break;
        }
        stringconsidered[length]=s[length];
        length++;
    }
    stringconsidered[length]='\0';   //Terminate the new string so it can be printed
    printf("String under consideration = %s , length = %d ",stringconsidered,length);
    printf("\nSplitted string = ");
    //stringconsidered is called as original string henceforth
    int j=0;         //Value that traverses through the original string
    while(j<length){ //looping through the whole string     
        char sub[length];  //an array that contains the current subarray 
        int k=0;           //Value for traversing through the subarray
        for(int l=0;l<length;l++){    //We make the whole subarray null and then replace values from starting as proper values so that while printing we dont have to worry about length of substring 
            sub[l]='\0';
        }
        sub[k]=stringconsidered[j];   //Take the first element of the substring from the original string
        j++;k++;
        while(stringconsidered[j]==sub[0]){   //Copy elements until they are same; like if original string is aaaaaabbb, it has already taken the first a above code and will now copy the remaining a's
            sub[k]=stringconsidered[j];
            j++;k++;
        }
        int substrlength=k;                   //Declare and assign length of substring 
        while(1){
            if(stringconsidered[j]==stringconsidered[j-1]){break;}   //If element of subarray of substring is same as last, that means substring cannot be entended further
            char x[substrlength];             //We declare a new array of length of substring and keep adding elements and checking if all of them are same and if they are, we print it else we print current subarray
            int b=0,a=j;
            char key=stringconsidered[j];
            while(stringconsidered[a]==key&&b<substrlength){
                x[b]=stringconsidered[a];
                a++;b++;
            }
            if(b==substrlength){
                j+=substrlength;
                for(int r=0;r<substrlength;r++){
                    sub[k]=x[r];
                    k++;
                }
            }
            else{break;}
        }
        if(j>=length){
            printf("%s\n",sub);//We print without '-' if it continues the pattern
        }
        else{printf("%s-",sub);}//else we print with - if it breaks the pattern
    }
    return 0;
}