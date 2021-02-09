#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> pairs;
        for (int i = 0; i < scores.size(); i++)
            pairs.emplace_back(scores[i], ages[i]);
        sort(pairs.begin(), pairs.end());

        int answer = 0;

        vector<int> dp(pairs.size(), 0);
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = i - 1; j >= 0; j--)
                if (pairs[j].second <= pairs[i].second)
                    dp[i] = max(dp[i], dp[j]);
            dp[i] += pairs[i].first;
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> scores = {
        {1, 3, 5, 10, 15},
        {4, 5, 6, 5},
        {1, 2, 3, 5}
    };
    vector<vector<int>> ages = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 1},
        {8, 9, 10, 1}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < scores.size(); i++)
        ret.push_back(solution.bestTeamScore(scores[i], ages[i]));

    /* Answer */
    vector<int> answer = {34, 16, 6};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
