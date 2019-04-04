#include <algorithm>
#include <cstdio>
using namespace std;

const int mr[] = {1, 0};
const int mc[] = {0, 1};
int N, mx;
char MAP[50][51];

int check(int r, int c) {
    char cc = MAP[r][c];
    int R = 1, C = 1;
    for (int i = r + 1; i < N && MAP[i][c] == cc; i++, R++);
    for (int i = r - 1; i >= 0 && MAP[i][c] == cc; i--, R++);
    for (int i = c + 1; i < N && MAP[r][i] == cc; i++, C++);
    for (int i = c - 1; i >= 0 && MAP[r][i] == cc; i--, C++);
    return max(R, C);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf(" %s", MAP[i]);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 2; ++k) {
                int dr = i + mr[k];
                int dc = j + mc[k];
                if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;    
                swap(MAP[i][j], MAP[dr][dc]);
                mx = max(mx, check(i, j));
                mx = max(mx, check(dr, dc));
                swap(MAP[i][j], MAP[dr][dc]);
            }
        }
    }

    printf("%d\n", mx);
    return 0;
}

