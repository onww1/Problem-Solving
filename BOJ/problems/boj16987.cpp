#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N;
vector <pii> egg;

int solve(int T) {
    if (T == N) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) 
            if (egg[i].X <= 0) ++cnt;
        return cnt;
    }

    if (egg[T].X <= 0) return solve(T + 1);

    int ret = 0;
    bool checked = false;
    for (int i = 0; i < N; ++i) {
        if (i != T && egg[i].X > 0) {
            checked = true;
            egg[i].X -= egg[T].Y;
            egg[T].X -= egg[i].Y;
            ret = max(ret, solve(T + 1));
            egg[i].X += egg[T].Y;
            egg[T].X += egg[i].Y;
        }
    }
    if (!checked) ret = max(ret, solve(T + 1));
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0, S, W; i < N; ++i) {
        scanf("%d %d", &S, &W);
        egg.push_back({S, W});
    }

    printf("%d\n", solve(0));
    return 0;
}