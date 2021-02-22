#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* Solution Class */
class Solution {
public:
    int numIslandsV1(vector<vector<char>>& grid) {
        int answer = 0;

        numRow = grid.size();
        numCol = grid[0].size();
        vector<vector<bool>> visit(numRow, vector<bool>(numCol, false));

        for (int r = 0; r < numRow; r++) {
            for (int c = 0; c < numCol; c++) {
                if (grid[r][c] == '1' && !visit[r][c]) {
                    answer++;
                    bfs(r, c, grid, visit);
                }
            }
        }

        return answer;
    }

private:
    const int move_r[4] = {-1, 1, 0, 0};
    const int move_c[4] = {0, 0, -1, 1};
    int numRow, numCol;

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
        queue<pair<int,int>> que;
        que.emplace(row, col);
        visit[row][col] = true;

        while (!que.empty()) {
            int r = que.front().first;
            int c = que.front().second;
            que.pop();

            for (int k = 0; k < 4; k++) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= numRow || dc < 0 || dc >= numCol)
                    continue;
                if (grid[dr][dc] == '1' && !visit[dr][dc]) {
                    que.emplace(dr, dc);
                    visit[dr][dc] = true;
                }
            }
        }
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<char>>> grid = {
        {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        },
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        }
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < grid.size(); i++)
        ret.push_back(solution.numIslands(grid[i]));

    /* Answer */
    vector<int> answer = {1, 3};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
