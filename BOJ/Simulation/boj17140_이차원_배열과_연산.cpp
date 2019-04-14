#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 100;
int R, C, K, N, M, T, MAP[MAX][MAX], cnt[MAX + 1];
vector <int> V;

bool cmp(int a, int b) {
    if (cnt[a] == cnt[b]) return a < b;
    return cnt[a] < cnt[b];
}

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &R, &C, &K); R--, C--;
    N = M = 3;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf("%d", MAP[i] + j);

    while (T <= 100) {
        if (MAP[R][C] == K) break;
        else T++;

        if (N >= M) {
            int mx_len = 0;
            for (int i = 0; i < N; ++i) {
                V.clear();
                for (int j = 0; j < M; ++j) {
                    if (MAP[i][j] && !cnt[MAP[i][j]]) V.push_back(MAP[i][j]);
                    cnt[MAP[i][j]]++;
                }
                sort(V.begin(), V.end(), cmp);
                for (int j = 0; j < V.size(); ++j) {
                    if (j < 50) {
                        MAP[i][j * 2] = V[j];
                        MAP[i][j * 2 + 1] = cnt[V[j]];
                    }
                    cnt[V[j]] = 0;
                }
                for (int j = 2 * V.size(); j < M; ++j) MAP[i][j] = 0;
                mx_len = max(mx_len, min(2 * (int)V.size(), 100));
            }
            M = mx_len;
        } else {
            int mx_len = 0;
            for (int j = 0; j < M; ++j) {
                V.clear();
                for (int i = 0; i < N; ++i) {
                    if (MAP[i][j] && !cnt[MAP[i][j]]) V.push_back(MAP[i][j]);
                    cnt[MAP[i][j]]++;
                }
                sort(V.begin(), V.end(), cmp);
                for (int i = 0; i < V.size(); ++i) {
                    if (i < 50) {
                        MAP[i * 2][j] = V[i];
                        MAP[i * 2 + 1][j] = cnt[V[i]];
                    }
                    cnt[V[i]] = 0;
                }
                for (int i = 2 * V.size(); i < N; ++i) MAP[i][j] = 0;
                mx_len = max(mx_len, min(2 * (int)V.size(), 100));
            }
            N = mx_len;
        }
    }

    printf("%d\n", T > 100 ? -1 : T);
    return 0;
}