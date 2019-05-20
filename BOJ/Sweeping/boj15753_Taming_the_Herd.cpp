#include <cstdio>

int N, mn, mx, A[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);

    bool valid = true, seq = false;
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] != -1) {
            mx++;
            if (!seq) mn++;
            seq = false;

            if (A[i] > i) {
                valid = false;
                break;
            }

            for (int j = 1; j <= A[i]; ++j) 
                if (A[i - j] != -1 && A[i] - j != A[i - j])
                    valid = false;
            i -= A[i];
        }
        else {
            if (!seq) {
                mn++;
                seq = true;
            }
            mx++;
        }
    }

    if (valid) printf("%d %d\n", mn, mx);
    else printf("-1\n");
    return 0;
}