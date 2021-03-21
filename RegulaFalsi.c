/*
    Author: Aviral
    Title: REgula Falsi Method
*/

#include<stdio.h>
#include<math.h>
#define E 2.71828
#define PI 3.14159265
#define corr_till 1
float f(float x){
    return x*x-3;   //[1,2]
}


int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    float a,b;
    int n, places, count;
    //Input
    printf("Enter the interval a,b: ");
    scanf("%f%f", &a, &b);
    if(f(a)*f(b) > 0 || f(a)*f(b) == 0){
        printf("Invalid intervals");
        return 0;
    }

    #if(corr_till)
        float prev = f(a);
        printf("Enter the decimal places: \n");
        scanf("%d", &places);
        float till = 0.5 * pow(10.0, -places);
    #else
        printf("Enter the number of iterations: \n");
        scanf("%d", &n);
    #endif
    //Iterations
    while(1){
        float c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        float fc = f(c);
        if(fc == 0){
            printf("Solution found at iteration %d: %f", count+1, c);
            break;
        }else if(f(a)*fc < 0){
            b = c;
        }else{
            a = c;
        }
        printf("iteration %d: root: %f\t Value: %f\n", count+1, c, fc);
        #if(corr_till)
            if(fabs(c - prev) < till){
                printf("Solution correct till %d decimal places\nroot: %f\n", places, c);
                break;
            }
            prev = fc;
        #endif
        count++;
        #if(corr_till == 0)
            if(count >= n){
                break;
            }
        #endif
        
    }
    
}





