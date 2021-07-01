/*Aman Sharma
  20EC10007*/

#include <stdio.h>

int main(){
    int p, q, r;
    printf("Enter #rows & #columns of 1st matrix: ");
    scanf("%d %d", &p, &q);
    printf("Enter #columns of 2nd matrix: ");
    scanf("%d", &r);
    int a[p][q], b[q][r], c[p][r];
//The nested for loops first go to each row, and then columnwise, access each element.

    printf("Enter matrix A:\n");//Take inputs
    for (int i=0; i<p; i++){
        for (int j=0; j<q; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter matrix B:\n");
    for (int i=0; i<q; i++){
        for (int j=0; j<r; j++){
            scanf("%d", &b[i][j]);
        }
    }


    for (int i=0; i<p; i++){//We calculate the elements of the resultant matrix
        for (int j=0; j<r; j++){
            c[i][j]=0;
            for (int k=0; k<q; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }


    printf("Output matrix: ");//Printing the result
    for (int i=0; i<p; i++){
        printf("\n");
        for (int j=0; j<r; j++){
            printf(" %4d ", c[i][j]);
        }
    }
    return 0;
}
