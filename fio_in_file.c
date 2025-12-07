#include <stdio.h>
#include <stdlib.h>

int main(void){
    char surname[101];
    int age;
    float tall;

    int N, len;
    const char* filename = "input.txt";

    FILE* fin;
    FILE* fout;
    if((fin = fopen(filename, "rt")) == NULL){
        exit(1);
    }

    if((fout = fopen("output.txt", "wt")) == NULL){
        exit(1);
    }

    if(fscanf(fin, "%d %d", &N, &len) != 2){
        fclose(fin);
        exit(1);
    }

    for(int i = 0; i < N; ++i){
        if(fscanf(fin, "%s %d %f", surname, &age, &tall) != 3){
            fclose(fin);
            fclose(fout);
            exit(1);
        }
        fprintf(fout, "%-*s %4.2d %6.2f\n", len, surname, age, tall);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}