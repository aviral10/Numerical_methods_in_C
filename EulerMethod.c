#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f(float x, float y){
    return x+y;
}


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    float x0, y0;
    printf("Enter x0 and y0: \n");
    scanf("%f%f", &x0, &y0);
    float xn,n;
    printf("Enter n and xn: \n");
    scanf("%f%f", &n,&xn);
    float h = (xn-x0)/n;
    float x=x0,y=y0, Y;
    while(fabs(x-xn) > 0.00001){
        
        y = y + h*f(x,y);
        x += h;
        
    }
    printf("x: %f, y: %f\n", x,y);

    
    return 0;
}