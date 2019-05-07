#include <algorithm>
#include <cstdio>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 1e5;
int N, G, ans;
piii logs[MAX];
map <int, int> dist;
map <int, int> cows;

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &G);
    for (int i = 0; i < N; ++i) scanf("%d %d %d", &logs[i].X, &logs[i].Y.X, &logs[i].Y.Y);
    sort(logs, logs + N);

    dist[0] = 1e9;
    for (int i = 0; i < N; ++i) {
        int &cow = cows[logs[i].Y.X];

        bool is_prev_top = (cow == dist.rbegin()->X);
        int prev_cnt = dist[cow]--;
        if (prev_cnt == 1) dist.erase(cow);

        cow += logs[i].Y.Y;

        int cur_cnt = ++dist[cow];
        bool is_cur_top = (cow == dist.rbegin()->X);

        if (is_prev_top) {
            if (!is_cur_top || prev_cnt != 1 || cur_cnt != 1) 
                ++ans;
        } 
        else if (is_cur_top) 
            ++ans;
    }

    printf("%d\n", ans);
    return 0;
}