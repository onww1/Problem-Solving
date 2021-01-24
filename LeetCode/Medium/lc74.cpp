#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (matrix[mid][0] <= target) lo = mid + 1;
            else hi = mid - 1;
        }
        if (hi == -1) return false;
        int r = hi;
        lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (matrix[r][mid] <= target) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi != -1 && matrix[r][hi] == target;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<vector<int>>> matrix = {
        {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
        },
        {
            {1, 3, 5, 7},
            {10, 11, 16, 20},
            {23, 30, 34, 60}
        }
    };
    vector<int> target = {3, 13};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < matrix.size(); i++)
        ret.push_back(solution.searchMatrix(matrix[i], target[i]));

    /* Answer */
    vector<bool> answer = {true, false};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}