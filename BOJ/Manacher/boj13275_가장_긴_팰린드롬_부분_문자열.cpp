#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 1;
int N, A[2 * MAX];
char in[MAX], S[2 * MAX];

int main(int argc, char *argv[]) {
    scanf(" %s", in); S[0] = '#';
    for (int i = 0; in[i]; ++i, ++N) {
        S[2 * i + 1] = in[i];
        S[2 * i + 2] = '#';
    }
    N = 2 * N + 1;

    int r = 0, p = 0;
    for (int i = 0; i < N; ++i) {
        if (i <= r) A[i] = min(r - i, A[p * 2 - i]);
        else A[i] = 0;
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1]) A[i]++;
        if (i + A[i] > r) {
            r = i + A[i];
            p = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, A[i]);
    printf("%d\n", ans);
    return 0;
}