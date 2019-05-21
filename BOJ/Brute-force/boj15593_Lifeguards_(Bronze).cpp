#include <algorithm>
#include <cstdio>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

int N, S[1001], tot;
pii P[100];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &P[i].X, &P[i].Y);
        for (int j = P[i].X; j < P[i].Y; ++j) {
            if (!S[j]) tot++;
            S[j]++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = P[i].X; j < P[i].Y; ++j) 
            if (S[j] == 1) cnt++;
        ans = max(ans, tot - cnt);
    }

    printf("%d\n", ans);
    return 0;
}