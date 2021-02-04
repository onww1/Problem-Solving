#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for (int candy: candies)
            mx = max(mx, candy);
        
        vector<bool> ret;
        for (int candy: candies)
            ret.push_back(candy + extraCandies >= mx);
        
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> candies = {
        {2, 3, 5, 1, 3},
        {4, 2, 1, 1, 2},
        {12, 1, 12}
    };
    vector<int> extraCandies = {3, 1, 10};

    /* Output */
    vector<vector<bool>> ret;
    for (int i = 0; i < candies.size(); i++)
        ret.push_back(solution.kidsWithCandies(candies[i], extraCandies[i]));

    /* Answer */
    vector<vector<bool>> answer = {
        {true, true, true, false, true},
        {true, false, false, false, false},
        {true, false, true}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
