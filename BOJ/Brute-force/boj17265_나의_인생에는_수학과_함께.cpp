#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, mn = INF, mx = -INF, P[8];
char MAP[5][5];

int calculate(int a, int b, int op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf(" %c", MAP[i] + j);
    for (int i = 0; i < N - 1; ++i) P[i + N - 1] = 1;
    
    do {
        int r = 0, c = 0, val = MAP[0][0] - '0';
        char op = 0;
        for (int j = 0; j < 2 * N - 2; ++j) {
            if (P[j]) ++c;
            else ++r;
            if (j % 2) val = calculate(val, MAP[r][c] - '0', op);
            else op = MAP[r][c];
        }
        mx = max(mx, val);
        mn = min(mn, val);
    } while (next_permutation(P, P + 2 * N - 2));

    printf("%d %d\n", mx, mn);
    return 0;
}