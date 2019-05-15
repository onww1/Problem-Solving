#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e6;
int N, L;
pii P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].X, &P[i].Y);
    sort(P, P + N);

    int l = P[0].X;
    for (int i = 0; i < N; ++i) {
        if (P[i].X <= l && P[i].Y > l) {
            L += P[i].Y - l;
            l = P[i].Y;
        } else if (P[i].X > l) {
            L += P[i].Y - P[i].X;
            l = P[i].Y;
        }
    }

    printf("%d\n", L);
    return 0;
}