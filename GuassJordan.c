/*
    Author: Aviral
    Title: Guass Jordan
*/

#include<stdio.h>
#include<math.h>
int main(){
    // freopen("in.txt", "r", stdin);
    int n,i,j,k;
    printf("Enter n: ");
    scanf("%d", &n);
    float arr[n][n+1];
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            scanf("%f", &arr[i][j]);
        }
    }
    printf("Matrix Before: \n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++)
            printf("%.2f ", arr[i][j]);
        printf("\n");
    }

    //Partial Pivoting
    for(i=0;i<n;i++){
        int swp_ind = i;
        for(j=i+1;j<n;j++){
            if(arr[j][i] > arr[swp_ind][i]){
                swp_ind = j;               
            }
        }
        if(swp_ind != i){
            float temp;
            for(k=0;k<=n;k++){
                temp = arr[i][k];
                arr[i][k]=arr[swp_ind][k];
                arr[swp_ind][k] = temp;
            }
        }
        
    }

    //Upper Triangular
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(fabs(arr[i][i]) < 0.000001){
                printf("Cannot Solve since a diagonal entry becomes 0\n");
                return 0;
            }
            float want = (float)arr[j][i]/arr[i][i];
            for(k=i;k<=n;k++){
                arr[j][k] -= want*arr[i][k];
            }
        }
    }
    //Lower Triangular
    for(i=n-1;i>0;i--){
        for(j=i-1;j>=0;j--){
            if(fabs(arr[i][i]) < 0.000001){
                printf("Cannot Solve since a diagonal entry becomes 0\n");
                return 0;
            }
            float want = (float)arr[j][i]/arr[i][i];
            for(k=i;k<=n;k++){
                arr[j][k] -= want*arr[i][k];
            }
        }
    }

    printf("Matrix After: \n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++)
            printf("%.2f ", arr[i][j]);
        printf("\n");
    }

    //Back Substitution
    float ans[n];
    for(i=n-1;i>=0;i--){
        float fin = arr[i][n];
        ans[i] = fin/arr[i][i];
    }
    printf("Values: ");
    for(i=0;i<n;i++){
        printf("%.2f ", ans[i]);
    }
    printf("\n");
}
