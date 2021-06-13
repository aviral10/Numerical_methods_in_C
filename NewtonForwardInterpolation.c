#include<stdio.h>
#include<stdlib.h>

long long fact(int n){
    if(n <= 1) return 1;
    return n*fact(n-1);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    printf("Enter n(Number of values to enter): \n");
    scanf("%d", &n);
    float arr[n][n+1];
    memset(arr, 0, sizeof(arr));
    printf("Enter x and fx n times: \n");
    for(int i=0;i<n;i++){
        scanf("%f%f", &arr[i][0], &arr[i][1]);
    }
    // Forward difference table:
    for(int j=2;j<n+1;j++){
        
        for(int i=0;i<n+1-j;i++){
            arr[i][j] = arr[i+1][j-1] - arr[i][j-1];
        }
    }
    printf("Difference Table: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }

    float value;
    printf("Enter the value to be interpolated: ");
    scanf("%f", &value);

    float h = arr[1][0] - arr[0][0];
    float u = (value - arr[0][0])/h;
    float ans = arr[0][1];
    for(int j=2;j<n+1;j++){
        float val = 1;

        for(int k=0;k<j-1;k++){
            val *= (u-k);
        }

        val *= arr[0][j]/fact(j-1);
        ans += val;
    }

    printf("f(%.4f): %f\n", value,  ans);

    return 0;
}