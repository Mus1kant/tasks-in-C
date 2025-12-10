
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200
#define MAXLEN 21 // '\0' + 1 symbol

// a[i][j] = *(*(a + i) + j)

// ---------------------qsort--------------------
// void qsort(int* base, size_t bsize, size_t size, 
//     int (*compare)(const void*, const void*));
// ---------------------qsort--------------------

int cmp_str(const void* a, const void* b){
    const char* strA = a;
    const char* strB = b;
    return strcmp(strA, strB);
    //------------------------OR-----------------------------
    // return strcmp((const char *)strA, (const char *)strB);
    //------------------------OR-----------------------------
}

void print_list(const char* tittle, char arr[][MAXLEN], int count) {
    printf("%s", tittle);

    if(count > 0){
        for(int i = 0; i < count; ++i){
            if(count > 0)
                printf(" ");
            if(i > 0){
                printf(", ");
            }
            printf("%s", arr[i]);
        }
    }

    printf("\n");
}

int main(){
    int n;
    FILE* fin;

    char subscribers[MAXN][MAXLEN];
    char subscriptions[MAXN][MAXLEN];
    char friends[MAXN][MAXLEN];
    char also_friends[MAXN][MAXLEN];

    if((fin = fopen("input.txt", "rt")) == NULL)
        exit(1);
    if(fscanf(fin, "%d", &n) != 1){
        fclose(fin);
        exit(1);
    }

    // считываем подписчиков
    for(int i = 0; i < n; ++i){
        if(fscanf(fin, "%20s", subscribers[i]) != 1)
            exit(1);
    }

    int m;
    fscanf(fin, "%d", &m);

    // считываем подписки
    for(int i = 0; i < m; ++i){
        if(fscanf(fin, "%20s", *(subscriptions + i)) != 1)
            exit(1);
    }

    fclose(fin);

    qsort(subscribers, n, MAXLEN, cmp_str);
    qsort(subscriptions, m, MAXLEN, cmp_str);

    int i, j , k, l;
    i = j = k = l = 0;
    
    
    // subscribers:    anna, ivan, petya, vasya
    // subscriptions:  dima, ivan, kolya, vasya, zhenya
    
    while(i < n && j < m) {
        int c = strcmp(subscribers[i], subscriptions[j]);
        if(c == 0){
            strcpy(friends[k++], subscriptions[j]);
            i++;
            j++;    
        }
        else if(c < 0){
            i++;
        }
        else if(c > 0){
            strcpy(also_friends[l++], subscriptions[j++]);
        }
    }

    while(j < m){
        strcpy(also_friends[l++], subscriptions[j++]);
    }


    print_list("Friends: ", subscribers, n);
    print_list("Mutual Friends: ", friends, k);
    print_list("Also Friend of: ", also_friends, l);

    return 0;
}