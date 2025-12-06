#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* fin;
    FILE* fout;
    fin = fopen("input.txt", "rt");
    if(fin == NULL){
        exit(1);
    }

    if((fout = fopen("output.txt", "wt")) == NULL){
        exit(1);    
    }

    int temp = 0;
    int sum = 0;
    int flag = 1;
    for(;(flag = fscanf(fin, "%d", temp)) == 1;){
            sum += temp;
    }
    fprintf(fout, "%d\n", sum);


    fclose(fin);
    fclose(fout);
    return 0;
}