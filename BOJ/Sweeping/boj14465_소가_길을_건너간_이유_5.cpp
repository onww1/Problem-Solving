#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5;
const int INF = 0x3f3f3f3f;
int N, K, B, A[MAX + 1];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &K, &B);
    for (int i = 0, in; i < B; ++i) {
        scanf("%d", &in);
        A[in] = 1;
    }

    int mn = INF, sum = 0;
    for (int i = 1; i < K; ++i) sum += A[i];
    for (int i = K; i <= N; ++i) {
        sum += A[i];
        sum -= A[i - K];
        mn = min(mn, sum);
    }

    printf("%d\n", mn);
    return 0;
}

// #include <algorithm>
// #include <cstdio>
// using namespace std;

// const int MAX = 1e5 + 1;
// const int INF = 0x3f3f3f3f;
// int N, K, B, A[MAX];

// int main(int argc, char *argv[]) {
//     scanf("%d %d %d", &N, &K, &B);
//     for (int i = 0, C; i < B; ++i) {
//         scanf("%d", &C);
//         A[C] = 1;
//     }

//     int ans = INF;
//     for (int i = 1; i <= N; ++i) {
//         A[i] += A[i - 1];
//         if (i >= K) ans = min(ans, A[i] - A[i - K]);
//     }

//     printf("%d\n", ans);
//     return 0;
// }
