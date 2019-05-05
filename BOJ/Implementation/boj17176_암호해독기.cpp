#include <cstdio>

const int MAX = 1e5;
int N, M, cnt[128];
char cmp[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &M);
        if (!M) cnt[' ']++;
        else if (1 <= M && M <= 26) cnt[M - 1 + 'A']++;
        else cnt[M - 27 + 'a']++;
    }

    getchar();
    fgets(cmp, sizeof(cmp), stdin);
    for (int i = 0; i < N; ++i) 
        cnt[cmp[i]]--;
    
    bool flag = 1;
    if (cnt[' ']) flag = 0;
    for (int i = 'A'; i <= 'Z'; ++i) if (cnt[i]) flag = 0;
    for (int i = 'a'; i <= 'z'; ++i) if (cnt[i]) flag = 0;

    puts(flag ? "y" : "n");
    return 0;
}


