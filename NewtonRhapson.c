/*
    Author: Aviral
    Title: Newton Rhapson Method
*/
#include<stdio.h>
#include<math.h>
#define E 2.71828
#define PI 3.14159265
#define corr_till 1

float f(float x){
    return x*x-3;   //[1,2]
}

float df(float x){
    return 2*x;   //[1,2]
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    float xp;
    int n, places, count=0;
    //Input
    printf("Enter initial approximation: ");
    scanf("%f", &xp);
    
    #if(corr_till)
        printf("Enter the decimal places: \n");
        scanf("%d", &places);
        float till = 0.5*pow(10.0, -places);
    #else
        printf("Enter the number of iterations: \n");
        scanf("%d", &n);
    #endif
    //Iterations
    while(1){
        float xn = xp - f(xp)/df(xp);

        if(xn == 0){
            printf("Solution found at iteration %d: %f", count+1, xp);
            break;
        }
        printf("x%d: %f\n",count+1, xn);
        #if(corr_till)
            if(fabs(xn-xp) < till){
                printf("Solution correct till %d decimal places\nroot: %f\n", places, xn);
                break;
            }
        #endif
        xp = xn;
        count++; 
        #if(corr_till == 0)
            if(count >= n){
                break;
            }
        #endif
        
    }
    
}

