#include <algorithm>
#include <cstdio>
#include <deque>
using namespace std;

const int MAX = 10;
const int move_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int move_c[] = {0, -1, 0, 1, -1, 1, -1, 1};
int N, M, K, MAP[MAX][MAX], A[MAX][MAX], breeding[MAX][MAX];
deque <int> trees[MAX][MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) { 
        scanf("%d", A[i] + j);
        MAP[i][j] = 5;
    }
    for (int i = 0, x, y, z; i < M; ++i) {
        scanf("%d %d %d", &x, &y, &z);
        trees[x - 1][y - 1].push_front(z);
    }

    for (int year = 0; year < K; ++year) {
        // spring & summer & winter
        for (int i = 0; i < N; ++i) {
            for (int j = 0, k; j < N; ++j) {
                int dsize = trees[i][j].size();
                // spring
                for (k = 0; k < dsize; ++k) {
                    if (trees[i][j].front() <= MAP[i][j]) {
                        MAP[i][j] -= trees[i][j].front();
                        trees[i][j].push_back(trees[i][j].front() + 1);
                        if ((trees[i][j].front() + 1) % 5 == 0) breeding[i][j]++;
                        trees[i][j].pop_front();
                    } else break;
                }

                // summer
                for (; k < dsize; ++k) {
                    MAP[i][j] += trees[i][j].front() / 2;
                    trees[i][j].pop_front();
                }

                // winter
                MAP[i][j] += A[i][j];
            }
        }

        // autumn
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (breeding[i][j]) {
                    for (int k = 0; k < 8; ++k) {
                        int dr = i + move_r[k];
                        int dc = j + move_c[k];
                        if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                        for (int l = 0; l < breeding[i][j]; ++l) 
                            trees[dr][dc].push_front(1);
                    }
                    breeding[i][j] = 0;
                }
            }
        }
    }
  
    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) ans += (int)trees[i][j].size();
    printf("%d\n", ans);
    return 0;
}