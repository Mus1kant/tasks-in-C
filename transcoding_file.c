#include <stdio.h>
#include <stdlib.h>


int main(void){
    FILE *in, *out;
    if((in = fopen("input.bin", "rb")) == NULL) exit(1);

    if((out = fopen("output.bin", "wb")) == NULL) exit(1);

    int ok = 1;
    if(in != NULL && out != NULL){
        unsigned short N;
        ok = 1;
        if(fread(&N, 2, 1, in) == 1){
            fwrite(&N, 2, 1, out);

            unsigned short i = 0;
            while(i < N && ok){
                short x;
                int y;

                if(fread(&x, 2, 1, in) == 1){
                    y = (int)x;
                    fwrite(&y, 4, 1, out);
                    i++;
                } else ok = 0;
            }
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}