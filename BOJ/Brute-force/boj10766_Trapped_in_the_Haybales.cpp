#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, ans;
pii P[4000];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d %d", &P[i].Y, &P[i].X);
    sort(P, P + N);

    for (int i = 0; i < N - 1; ++i) {
        int l = i, r = i + 1, s = P[r].X - P[l].X;
        while (1) {
            if (P[l].Y < s) {
                if (--l < 0) break;
                s = P[r].X - P[l].X;
                continue;
            }
            else if (P[r].Y < s) {
                if (++r >= N) break;
                s = P[r].X - P[l].X;
                continue;
            }
            break;
        }

        if (l >= 0 && r < N) 
            ans += (P[i + 1].X - P[i].X);
    }   

    printf("%d\n", ans);
    return 0;
}