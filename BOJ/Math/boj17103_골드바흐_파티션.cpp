#include <cstdio>

const int MAX = 1e6 + 1;
int T, N;
bool noPrime[MAX] = {true, true, };

int main(int argc, char *argv[]) {
    for (int i = 2; i * i < MAX; ++i) 
        if (!noPrime[i]) 
            for (int j = i * i; j < MAX; j += i) 
                noPrime[j] = true;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        if (N == 4) puts("1");
        else {
            int cnt = 0;
            for (int i = 3; i <= N / 2; i += 2)
                if (!noPrime[i] && !noPrime[N - i]) cnt++;
            printf("%d\n", cnt);
        }
    }

    return 0;
}