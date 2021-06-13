/*
    Author: Aviral
    Title: 
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define E 2.71828
#define PI 3.14159265
#define clr(x) memset(x, 0, sizeof(x))


int parseEquation(char *eq, int size, float* map[]){
    int n = strlen(eq);
    int i,j;
    int vars[size+1];
    int var = 0;
    for(i=0;i<n;i++){
        if(eq[i] >= 'a' && eq[i] <= 'z'){
            vars[var++] = i;
        }
    }
    vars[var++] = n;
    int prev = 0;
    int mpi = 0;
    for(i=0;i<var;i++){
        char* tem = (char*)malloc(100*sizeof(char));
        
        char* temp = tem;
        if(vars[i]-prev == 0){
            temp = "1";
        }else if(vars[i]-prev == 1){
            if(eq[vars[i]-1] == '-')
                temp = "-1";
            else if(eq[vars[i]-1] == '+'){
                temp = "1";
            }else{
                strncpy(temp, eq+prev, vars[i]-prev);
            }
        }else{
            strncpy(temp, eq+prev, vars[i]-prev);
            temp[vars[i]-prev] = '\0';
            if(temp[0] == '='){
                temp = temp+1;
            }
        }
        float coeff = strtof(temp, NULL);
       
        //for power:
        float power;
        char tem2[100];
        if(vars[i] != n){
            if(eq[vars[i]+1] == '^'){
                
                j = vars[i]+2;
                
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
        }else{
            power = 0;
        }
        
        map[mpi] = (float*)malloc(2*sizeof(float));
        map[mpi][0] = coeff;
        map[mpi][1] = power;
        mpi++;
        free(tem);
       
    }
    return mpi;
}

void preProcess(char *eq){
    int n = strlen(eq);
    int flag = 1,i,j;
    for(i=0;i<n;i++){
        if(eq[i] <= 'z' && eq[i] >= 'a'){
            flag = 0;
        }
        
        if(eq[i] == '+' || eq[i] == '-' || eq[i] == '='){
            if(flag){
                char temp[100];
                int len = 0;
                for(j=i;j<=n;j++){
                    temp[len++] = eq[j];
                }
                
                strcpy(eq+i, "x^0");
                strcpy(eq+i+3, temp);
                break;
            }else{
                flag = 1;
            }
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    char eq[100] = "10x^3-22x^10-99999=-100";
    float* map[100];
    printf("%s\n", eq);
    preProcess(eq);
    printf("%s\n", eq);
    int mpi = parseEquation(eq, strlen(eq), map);
    for(int i=0;i<mpi;i++){
        printf("%*.2f   %*.2f\n", 10,map[i][0], 10,map[i][1]);
    }
    for(int i=0;i<mpi;i++){
        free(map[i]);
    }
}

