#include <stdio.h>

int main() {
    int a[200][3], b[200][3], c[400][3];
    int i, j, k;
    int rows, cols;
    int na, nb;

    printf("Enter dimensions of the matrices (rows columns): ");
    scanf("%d%d", &rows, &cols);

    printf("Enter the number of non-zero elements in Matrix A: ");
    scanf("%d", &na);

    
    a[0][0] = rows;
    a[0][1] = cols;
    a[0][2] = na;

    printf("Enter the row, column, value for non-zero elements of Matrix A (1-based index):\n");
    for (i = 1; i <= na; i++) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    printf("\nSparse Matrix A (row col val):\n");
    for (i = 0; i <= na; i++) {
        printf("%3d %3d %3d\n", a[i][0], a[i][1], a[i][2]);
    }

    printf("\nEnter the number of non-zero elements in Matrix B: ");
    scanf("%d", &nb);

    b[0][0] = rows;
    b[0][1] = cols;
    b[0][2] = nb;

    printf("Enter the row, column, value for non-zero elements of Matrix B (1-based index):\n");
    for (i = 1; i <= nb; i++) {
        scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
    }

    printf("\nSparse Matrix B (row col val):\n");
    for (i = 0; i <= nb; i++) {
        printf("%3d %3d %3d\n", b[i][0], b[i][1], b[i][2]);
    }

    
    i = 1;
    j = 1;
    k = 1;
    c[0][0] = rows;
    c[0][1] = cols;

    while (i <= na && j <= nb) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        } else if (a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        } else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
            } else {
                k--; 
            }
            i++;
            j++;
        }
        k++;
    }

    
    while (i <= na) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= nb) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

   
    c[0][2] = k - 1;

    
    printf("\nResultant sparse Matrix(row col val):\n");
    for (i = 0; i <= c[0][2]; i++) {
        printf("%3d %3d %3d\n", c[i][0], c[i][1], c[i][2]);
    }
       
    int trans[400][3];
    trans[0][0] = c[0][1];
    trans[0][1] = c[0][0];
    trans[0][2] = c[0][2];

    int tk = 1;
    for (int col = 1; col <= c[0][1]; col++) {
        for (int t = 1; t <= c[0][2]; t++) {
            if (c[t][1] == col) {
                trans[tk][0] = c[t][1];
                trans[tk][1] = c[t][0];
                trans[tk][2] = c[t][2];
                tk++;
            }
        }
    }

    printf("\nTranspose of the Resultant sparse Matrix (row col val):\n");
    for (i = 0; i <= trans[0][2]; i++) {
        printf("%3d %3d %3d\n", trans[i][0], trans[i][1], trans[i][2]);
    }


    return 0;
}
