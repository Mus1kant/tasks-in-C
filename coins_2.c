    #include <stdio.h>
    #include <stdlib.h>

    int main(){
        int N; // количество корзин
        int w; // масса одной настощей монеты
        int P; // суммарный вес всех взятых монет
        int d; // насколько граммов фальшивая монета легче настоящей

        // создание указателей на файл
        FILE *fin, *fout;
        
        // открытие файлов
        if( (fin = fopen("input.txt", "rt")) == NULL){
            exit(1);
        }
        if( (fout = fopen("output.txt", "wt")) == NULL){
            fclose(fin);
            exit(1);
        }
        
        // считывание данных из файла
        if(fscanf(fin, "%d %d %d %d", &N, &w, &d, &P) != 4){
            fclose(fin);
            fclose(fout);
            exit(1);
        }
        
        // считаем ожидаемый вес монет, если бы все были настоящие
        long long FullP = ((long long)N * (N - 1) / 2) * w;
        
        // если веса совпали , фальшивая корзина последняя (из нее не брали монет)
        // иначе разность равна FullP - P = k * d, где k - номер корзины с фальшивфми монетами
        if(FullP == P){
            fprintf(fout, "%d", N);
        }else{
            fprintf(fout, "%lld\n", (FullP - P) / d);
        }

        fclose(fin);
        fclose(fout);

        return 0;
    }
