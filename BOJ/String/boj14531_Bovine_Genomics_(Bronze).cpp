#include <cstdio>

int N, M, ans;
char in[100][101], idx[128];
bool chk[100][4];

int main(int argc, char *argv[]) {
    idx['A'] = 0, idx['G'] = 1;
    idx['T'] = 2, idx['C'] = 3;

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", in[0]);
        for (int j = 0; in[0][j]; ++j) 
            chk[j][idx[in[0][j]]] = true;
    }
    for (int i = 0; i < N; ++i) scanf(" %s", in[i]);
    for (int j = 0; j < M; ++j) {
        bool hasCommon = false;
        for (int i = 0; i < N; ++i) 
            hasCommon |= chk[j][idx[in[i][j]]];
        if (!hasCommon) ans++;
    }
  
    printf("%d\n", ans);
    return 0;
}