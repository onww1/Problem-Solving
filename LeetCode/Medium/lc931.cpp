#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = 1e9;
                for (int k = -1; k <= 1; k++) {
                    if (j + k < 0 || j + k >= n) continue;
                    mn = min(mn, A[i - 1][j + k]);
                }
                A[i][j] += mn;
            }
        }
        int mn = 1e9;
        for (int i = 0; i < n; i++) mn = min(mn, A[n - 1][i]);
        return mn;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    /* Output */
    int ret = solution.minFallingPathSum(A);

    /* Answer */
    int answer = 12;
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
