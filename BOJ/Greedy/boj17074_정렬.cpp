#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, A[MAX];
vector <pii> seg;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d", A + i);
    
    int l = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i] < A[i - 1]) {
            seg.push_back({l, i - 1});
            l = i;
        }
    }
    seg.push_back({l, N - 1});

    if (seg.size() == 1) return !printf("%d\n", N);
    if (seg.size() > 2) return !printf("0\n");

    int ans = 0;
    if (seg[0].X == seg[0].Y || A[seg[0].Y - 1] <= A[seg[1].X]) ++ans;
    if (seg[1].X == seg[1].Y || A[seg[0].Y] <= A[seg[1].X + 1]) ++ans;
    printf("%d\n", ans);

    return 0;
}