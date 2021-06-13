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

void parseEquation(char *eq, float *map,int size){
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
        float parsed_val = strtof(temp, NULL);
        if(vars[i] != n)
            map[eq[vars[i]]-'a'] += parsed_val;
        else
            map[26] = parsed_val;
        prev = vars[i]+1;
        free(tem);
    }
}

void parseAllEquations(int size, float arr[size][size+1]){
    int i,j;
    char eq[100];
    float map[27];
    printf("You can use the following variables: \n> ");
    for(i=0;i<size;i++){
        printf("%c%c", 97+i, ((i+1==size)?'\n':' '));
    }
    printf("Example: 2a-3b+99d-0.8c=0\n[No spaces are expected in between]\n");
    for(i=0;i<size;i++){    
        clr(map);
        printf("Enter equation %d: ", i+1);
        fgets(eq, 100, stdin);
        eq[strlen(eq)-1] = '\0';
        printf("%s\n", eq);
        parseEquation(eq, map, size);
        printf("Equation:: %s\n", eq);
        printf("Parsed Values:: ");
        for(j=0;j<=size;j++){
            arr[i][j] = map[(j==size)?26:j];
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int i,j,size;
    printf("Enter the number of equations: ");
    scanf("%d", &size);
    while(getchar() != '\n');
    float arr[size][size+1];
    clr(arr);

    parseAllEquations(size, arr);  

    printf("Input Matrix:: \n");
    for(int i=0;i<size;i++){
        for(j=0;j<=size;j++){
            printf("%*.2f",8,arr[i][j]);
        }
        printf("\n");
    }  

    float pool[size];
    clr(pool);
    

}

