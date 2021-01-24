#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
using namespace std;

/* Solution Class */
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0.0)));
        vector<vector<int>> visit(N, vector<int>(N, 0));
        vector<int> move_r = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> move_c = {-1, 1, -2, 2, -2, 2, -1, 1};
        queue<pair<int,int>> q[2];
        dp[0][r][c] = 1.0;
        q[0].emplace(r, c);
        for (int i = 1, t = 0; i <= K; i++, t ^= 1) {
            while (!q[t].empty()) {
                int cr = q[t].front().first;
                int cc = q[t].front().second;
                q[t].pop();

                for (int k = 0; k < 8; k++) {
                    int dr = cr + move_r[k];
                    int dc = cc + move_c[k];
                    if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
                    dp[i][dr][dc] += dp[i - 1][cr][cc] / 8.0;
                    if (visit[dr][dc] != i) {
                        q[1 - t].emplace(dr, dc);
                        visit[dr][dc] = i;
                    }
                }
            }
        }

        double answer = 0.0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                answer += dp[K][i][j];
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    int n = 3, k = 2, r = 0, c = 0;

    /* Output */
    double ret = solution.knightProbability(n, k, r, c);

    /* Answer */
    double answer = 0.0625;

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}