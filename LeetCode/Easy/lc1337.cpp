#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> answer;

        int n = mat.size(), m = mat[0].size();
        vector<bool> used(n, false);
        for (int col = 0; col < m && answer.size() < k; col++) {
            for (int row = 0; row < n && answer.size() < k; row++) {
                if (!used[row] && !mat[row][col]) {
                    used[row] = true;
                    answer.push_back(row);
                }
            }
        }

        for (int row = 0; row < n && answer.size() < k; row++)
            if (!used[row]) {
                used[row] = true;
                answer.push_back(row);
            }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> mat = {
        {
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 0, 0, 0},
            {1, 1, 1, 1},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        }
    };
    vector<int> k = {3, 2};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < mat.size(); i++)
        ret.push_back(solution.kWeakestRows(mat[i], k[i]));

    /* Answer */
    vector<vector<int>> answer = {
        {2, 0, 3},
        {0, 2}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
