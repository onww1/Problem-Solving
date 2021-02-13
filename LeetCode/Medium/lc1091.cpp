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
    const int move_r[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int move_c[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        vector<vector<int>> dist(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.emplace(0, 0);

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 8; k++) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= n || dc < 0 || dc >= n) continue;
                if (!dist[dr][dc] && !grid[dr][dc]) {
                    dist[dr][dc] = dist[r][c] + 1;
                    q.emplace(dr, dc);
                }
            }
        }

        return dist[n - 1][n - 1] > 0 ? dist[n - 1][n - 1] : -1;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> grid = {
        {
            {0, 1},
            {1, 0}
        },
        {
            {0, 0, 0},
            {1, 1, 0},
            {1, 1, 0}
        }
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < grid.size(); i++)
        ret.push_back(solution.shortestPathBinaryMatrix(grid[i]));

    /* Answer */
    vector<int> answer = {2, 4};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
