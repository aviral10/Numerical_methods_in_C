#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float f(float x, float y){
    return x+y;
}


int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    float x0,y0;
    scanf("%f%f",&x0,&y0);
    float h,xn;
    scanf("%f%f",&h,&xn);
    float x=x0;
    float y=y0;
    float k,k1,k2,k3,k4;
    while (fabs(x-xn) > 0.00001)
    {
        k1 = h*fun(x,y);
        k2 = h*fun(x+h/2,y+k1/2);
        k3 = h*fun(x+h/2,y+k2/2);
        k4 = h*fun(x+h,y+k3);
        k = (k1+2*k2+2*k3+k4)/6;
        y+=k;
        x+=h;
    }
    printf("x: %f\ty: %f",x,y);

    
    return 0;
}