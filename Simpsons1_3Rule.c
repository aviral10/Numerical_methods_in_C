#include<stdio.h>
#include<stdlib.h>

float f(float x){
    return 1.0/(1+x*x);
}


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int u,l;
    printf("Enter lower limit and upper limit: ");
    scanf("%d %d", &l, &u);
    printf("u: %f, l: %f\n", u,l);
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    float h = (u-l)/(float)n;
    
    float arr[2][n+1];
    arr[0][0] = l;
    arr[1][0] = f(l);
    for(int i=1;i<=n;i++){
        arr[0][i] = arr[0][i-1]+h;
        arr[1][i] = f(arr[0][i]);
    }
    for(int i=0;i<=n;i++){
        printf("%f\t%f\n", arr[0][i], arr[1][i]);
    }
    float ans = 0;
    for(int i=0;i<=n;i++){
        if(i == 0 || i == n){
            ans += arr[1][i]/3.0;
        }else if(i&1){
            ans += arr[1][i]*(4/3.0);
        }else{
            ans += arr[1][i]*(2/3.0);
        }
    }
    ans *= h;
    printf("Ans: %f\n", ans);
    return 0;
}