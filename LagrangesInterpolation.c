#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    printf("Enter n(Number of values to enter): \n");
    scanf("%d", &n);
    float arr[2][n];
    
    printf("Enter x and fx n times: \n");
    for(int i=0;i<n;i++){
        scanf("%f%f", &arr[0][i], &arr[1][i]);
    }
    float value;
    printf("Enter the value to be interpolated: \n");
    scanf("%f", &value);
    float ans = 0;
    for(int i=0;i<n;i++){
        float val = 1;
        for(int j=0;j<n;j++){
            if(j != i){
                val *= ((value - arr[0][j])/(arr[0][i]-arr[0][j]));
            }
        }
        val *= arr[1][i];
        ans += val;
    }
    printf("f(%.4f): %f\n", value, ans);

    return 0;
}