#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 10;
const int INF = 0x3f3f3f3f;
int R[6] = {0, 5, 5, 5, 5, 5};
int mn = INF, MAP[MAX][MAX];
bool visited[MAX][MAX];

bool check(int r, int c, int size) {
    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            if (!MAP[i][j] || visited[i][j]) return false; 
        }
    }
    return true;
}

void fill_area(int r, int c, int size, bool val) {
    for (int i = r; i < r + size; ++i) 
        for (int j = c; j < c + size; ++j) 
            visited[i][j] = val;
}

void solve(int r, int c, int cnt) {
    if (c == MAX) r++, c = 0;

    int i, j, flag = 0;
    for (i = r; i < MAX; ++i) {
        for (j = (i == r ? c : 0); j < MAX; ++j) 
            if (MAP[i][j] && !visited[i][j]) { flag = 1; break; }
        if (flag) break;
    }

    if (i == MAX) {
        mn = min(mn, cnt);
        return;
    }

    if (cnt >= mn) return;

    for (int size = 5; size > 0; --size) {
        if (!R[size]) continue;
        if (i + size - 1 < MAX && j + size - 1 < MAX && check(i, j, size)) {
            R[size]--;
            fill_area(i, j, size, true);
            solve(r, c + size, cnt + 1);
            fill_area(i, j, size, false);
            R[size]++;
        }
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) scanf("%d", &MAP[i][j]);
    solve(0, 0, 0);
    printf("%d\n", mn == INF ? -1 : mn);

    return 0;
}