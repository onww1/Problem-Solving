#include <cstdio>
#include <cstring>

int N, ans, P[11];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    memset(P, -1, sizeof(P));

    for (int i = 0, A, B; i < N; ++i) {
        scanf("%d %d", &A, &B);
        if (P[A] == -1) P[A] = B;
        else if (P[A] != B) {
            ans++;
            P[A] = B;
        }
    }
  
    printf("%d\n", ans);
    return 0;
}