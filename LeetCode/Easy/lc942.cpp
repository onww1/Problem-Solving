#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.length();
        vector<int> ret(n + 1, 0);
        ret[0] = n;
        int lo = n, hi = n;
        for (int i = 0; i < n; i++) {
            if (S[i] == 'I') ret[i + 1] = ++hi;
            else ret[i + 1] = --lo;
        }
        if (lo != 0) {
            int diff = -lo;
            for (int i = 0; i <= n; i++)
                ret[i] += diff;
        }
        return ret;
    }
};

bool check(string S, vector<int> &ret) {
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'I' && ret[i] < ret[i + 1]) continue;
        if (S[i] == 'D' && ret[i] > ret[i + 1]) continue;
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> S = {"IDID", "III", "DDI"};

    /* Output */
    vector<vector<int>> ret;
    for (int i = 0; i < S.size(); i++)
        ret.push_back(solution.diStringMatch(S[i]));

    /* Answer */
    bool results = true;
    for (int i = 0; i < S.size(); i++)
        results &= check(S[i], ret[i]);

    /* Check */
    assert(results);

    puts("PASS!");
    return 0;
}
