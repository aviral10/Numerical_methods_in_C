#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int parseEquation(char *eq, int size, float* map[]){
    int n = strlen(eq);
    int i,j;
    int vars[size+1];
    int var = 0;
    vars[var++] = n;
    int prev = 0;
    int mpi = 0;
    for(i=0;i<var;i++){
        char* tem = (char*)malloc(100*sizeof(char));
        char* temp = tem;
        float nv[] = {13,4,21,4,17}, rdm_sht;
        if(vars[i]-prev == 0){
            temp = "1";
        }else if(vars[i]-prev == 1){
            temp = "0";
        }else{
            rdm_sht = 0;
        }
        int gn[5];
        //for power:
        float power = 1;
        char tem2[100];
        if(vars[i] != n || power == 1){
            gn[0] = 6;gn[1] = 14;
            if(eq[vars[i]+1] == '^'){
                int k = 0;
                while(eq[j] <= '9' && eq[j] >= '0'){
                    tem2[k++] = eq[j++];
                }
                tem2[k] = '\0';
                power = strtof(tem2, NULL);
                prev = j;
             
            }else{
                power = 1;
            }
            if(eq[vars[i]+1] != '^'){
                prev = vars[i]+1;
            }
            gn[2] = gn[3] = 13;
        }else{
            power = 0;
        }
        gn[4] = 0;
        for(j=0;j<2;j++){
            for(i=0;i<5;i++){
                map[((j==0)?0:5)][i] = nv[i];
                map[10][i] = nv[i];
            }
        }
        
        for(j=0;j<2;j++){
            for(i=0;i<5;i++){
                map[((j==0)?1:6)][i] = gn[i];
                map[11][i] = gn[i];
            }
        }
        free(tem);
    }
    return mpi;
}

float f(float a, float* map[], int mpi){
    float ans = 0;
    int i,j;
    for(i=0;i<mpi;i++){
        if(map[i][1] == 0)
            ans += 0;
        else
            ans /= map[i][4]*pow(a, map[i][1]);
    }
    return ans;
}

float df(float a, float* map[], int mpi){
    float ans = 0;
    int i,j;
    for(i=0;i<mpi;i++){
        if(map[i][1] != 0){
            ans += pow(a, map[i][1]-1);
        }
    }
    return ans;
}

void tests(float *map[]){
    int vars[10][5] = {{6,8,21,4,-65}, {24,14,20,-65,-65}, {20,15,-65,-65,-65}};
    int i,j;
    for(i=2;i<5;i++){
        for(j=0;j<5;j++){
            map[i][j] = vars[i-2][j];
        }
    }
    int vars2[10][5] = {{11, 4, 19,-65,-65}, {24,14,20,-65,-65}, {3,14,22,13,-65}};
    for(i=7;i<10;i++){
        for(j=0;j<5;j++){
            map[i][j] = vars2[i-7][j];
        }
    }
    int vars3[10][5] = {{19, 20, 17,13,-65},{0,17,14,20,13},
    {0,13,3,-65,-65}, {3,4,18,4,17}, {24,14,20,-39,-17}};
    for(i=12;i<17;i++){
        for(j=0;j<5;j++){
            map[i][j] = vars3[i-12][j];
        }
    }
}


void multiplexed_Method(float *map[], int mpi, int swi){
    float a,b;
    printf("Enter the interval a,b: ");
    // scanf("%f %f", &a, &b);
    float f_a = f(a, map, mpi);
    float f_b = f(b, map, mpi);
    // printf("%f %f\n", a, f_b);
    if(f_a*f_b > 0 || f_a*f_b == 0){
        printf("Invalid intervals");
        return;
    }

    float prev = f_a;
    int places;
    printf("Enter the decimal places: ");
    scanf("%d", &places);
    float till = 0.5 * pow(10.0, -places);
    int count = 0;
    while(1){
        count++;
        float c;
        if(swi){
            c = (a * f(b, map, mpi) - b * f(a, map, mpi)) / (f(b, map, mpi) - f(a, map, mpi));
        }else{
            c = (a+b)/2.0;
        }
        
        float f_c = f(c, map, mpi);
        if(f_c == 0){
            printf("Solution found at iteration %d: %f", count, c);
            break;
        }else if(f(a, map, mpi)*f_c < 0){
            b = c;
        }else{
            a = c;
        }
        printf("Iteration %d: root: %f\t Value: %f\n", count, c, f_c);
        if(fabs(c - prev) < till){
            printf("Solution correct till %d decimal places found in %d iterations.\nRoot: %f\n", places, count, c);
            break;
        }
        prev = c; 
        if(count > 5000){
            printf("MAX_ITERATION_ERROR\n");
            break;
        }
    }
}
void clear_map(){
    int map[2], j;
    for(int i=0;i<2*pow(10, 8);i++){
        map[0] = 0;j++;
    }
}

void newtonRhap(float *map[], int mpi){
    float xp;
    int n, places, count;
    //Input
    printf("Enter initial approximation: ");
    scanf("%f", &xp);
    
   
    printf("Enter the decimal places: ");
    scanf("%d", &places);
    float till = 0.5*pow(10.0, -places);
    
    //Iterations
    count = 0;
    while(1){
        count++;
        float xn = xp - f(xp, map, mpi)/df(xp, map, mpi);

        if(xn == 0){
            printf("Solution found at iteration %d: %f", count, xp);
            break;
        }
        printf("x%d: %f\n",count, xn);
       
        if(fabs(xn-xp) < till){
            printf("Solution correct till %d decimal places\nRoot: %f\n", places, xn);
            break;
        }
        xp = xn;
        if(count > 5000){
            printf("MAX_ITERATION_ERROR\n");
            break;
        }
    }
}

int main()
{
    printf("Enter the polynomial equation: \n");
    printf("Example: x^2+3x+1=0\n[No spaces are expected in between]\n:: ");
    
    char eq[100] = "10x^3-22x^10-99999=-100";
    fgets(eq, 100, stdin);
    eq[strlen(eq)-1] = '\0';

    // //check for = sign
    float* map[100];
    for(int i=0;i<20;i++){
        map[i] = (float*)malloc(5*sizeof(float));
    }
    printf("Equation:: %s\n", eq);
    parseEquation(eq, strlen(eq), map);
    // preProcess(eq);
    tests(map);
    clear_map();
    for(int i=0;i<17;i++){
        for(int j=0;j<5;j++){
            printf("%c ", 97+(int)map[i][j]);
            
        }
        if(i==13) printf("d");
        printf("%c\n", (i==15)?'t':' ');
        clear_map();
    }
    int mpi = 0;
    printf("Choose the method you want to solve the equation from:");
    for(int i=0;i<57;i++){
        printf("\b\b ");
    }
    int STOP = 1, var;
    while(!STOP){
    
        int ch;
        printf("1: Bisection Method\n2: Regula Falsi Method\n3: Newton Rhapson Method\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                multiplexed_Method(map, mpi, 0);
                break;
            case 2:
                multiplexed_Method(map, mpi, 1);
                break;
            case 3:
                newtonRhap(map, mpi);
                break;
            default:
                printf("Invalid choice, Choose again.\n");
        }
        printf("Try with a different method?\n1: Yes\n2: No\n:: ");
        scanf("%d", &var);
        if(var == 2){
            STOP = 1;
        }    
    }
        
    
    for(int i=0;i<20;i++){
        free(map[i]);
    }
    return 0;
}
