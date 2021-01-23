#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    void solve(int r, int n, int cv, int dv, int rdv, int &answer) {
        if (r == n) {
            answer++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (cv & (1 << c)) continue;
            if (dv & (1 << (r + c))) continue;
            if (rdv & (1 << (r - c + n - 1))) continue;
            solve(r + 1, n, cv | (1 << c), dv | (1 << (r + c)), rdv | (1 << (r - c + n - 1)), answer);
        }
    }

    int totalNQueens(int n) {
        int answer = 0;
        solve(0, n, 0, 0, 0, answer);
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> n = {4, 1};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.totalNQueens(n[i]));

    /* Answer */
    vector<int> answer = {2, 1};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}