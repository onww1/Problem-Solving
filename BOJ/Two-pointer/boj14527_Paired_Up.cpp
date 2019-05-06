#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, mx = 0;
pii P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].Y, &P[i].X);
    sort(P, P + N);

    int L = 0, R = N - 1;
    while (L <= R) {
        mx = max(mx, P[L].X + P[R].X);
        if (P[L].Y == P[R].Y) {
            P[L].Y = P[R].Y = 0;
            L++, R--;
        } else if (P[L].Y > P[R].Y) {
            P[L].Y -= P[R].Y; P[R].Y = 0;
            R--;
        } else {
            P[R].Y -= P[L].Y; P[L].Y = 0;
            L++;
        }
    }    

    printf("%d\n", mx);
    return 0;
}