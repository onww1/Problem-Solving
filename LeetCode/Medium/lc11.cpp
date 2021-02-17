#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> p;
        for (int i = 0; i < height.size(); i++)
            p.emplace_back(-height[i], i);
        sort(p.begin(), p.end());
        int lo = p[0].second, hi = p[0].second;
        int answer = 0;
        for (int i = 1; i < p.size(); i++) {
            lo = min(lo, p[i].second);
            hi = max(hi, p[i].second);
            answer = max(answer, -p[i].first * (hi - lo));
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> height = {
        {1, 8, 6, 2, 5, 4, 8, 3, 7},
        {1, 1},
        {4, 3, 2, 1, 4},
        {1, 2, 1}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < height.size(); i++)
        ret.push_back(solution.maxArea(height[i]));

    /* Answer */
    vector<int> answer = {49, 1, 16, 2};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
