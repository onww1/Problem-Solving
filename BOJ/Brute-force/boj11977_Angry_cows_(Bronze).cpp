#include <algorithm>
#include <cstdio>
using namespace std;

int N, A[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    sort(A, A + N);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = 1;
        // left
        for (int j = i - 1, r = 1, pos = A[i]; j >= 0; r++) {
            bool changed = false;
            while (j >= 0 && A[j] + r >= pos) {
                changed = true;
                cnt++; j--;
            }
            if (!changed) break;
            else pos = A[j + 1];
        }
        // right
        for (int j = i + 1, r = 1, pos = A[i]; j < N; r++) {
            bool changed = false;
            while (j < N && A[j] - r <= pos) {
                changed = true;
                cnt++; j++;
            }
            if (!changed) break;
            else pos = A[j - 1];
        }
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);
    return 0;
}