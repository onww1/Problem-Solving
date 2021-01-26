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
    const int move_r[4] = {-1, 1, 0, 0};
    const int move_c[4] = {0, 0, -1, 1};
    int n, m, vis;
    vector<vector<int>> visit;

    bool check(int diff, vector<vector<int>>& heights) {
        queue<pair<int,int>> q;
        q.emplace(0, 0); visit[0][0] = ++vis;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r == n - 1 && c == m - 1) 
                return true;

            for (int k = 0; k < 4; k++) {
                int dr = r + move_r[k];
                int dc = c + move_c[k];
                if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
                if (visit[dr][dc] != vis && abs(heights[r][c] - heights[dr][dc]) <= diff) {
                    q.emplace(dr, dc);
                    visit[dr][dc] = vis;
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size(), vis = 0;
        visit.clear();
        for (int i = 0; i < n; i++) visit.push_back(vector<int>(m, 0));
        int lo = 0, hi = 1e6;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid, heights)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> heights = {
        {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}
        },
        {
            {1, 2, 3},
            {3, 8, 4},
            {5, 3, 5}
        },
        {
            {1, 2, 1, 1, 1},
            {1, 2, 1, 2, 1},
            {1, 2, 1, 2, 1},
            {1, 2, 1, 2, 1},
            {1, 1, 1, 2, 1}
        }
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < heights.size(); i++)
        ret.push_back(solution.minimumEffortPath(heights[i]));

    /* Answer */
    vector<int> answer = {2, 1, 0};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
