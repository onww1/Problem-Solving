#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
using namespace std;

/* Solution Class */
typedef pair<int,int> pii;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 0; i < n; i++) {
            int& num = nums[i];
            int cnt = 0;
            while (num % 2 == 0) {
                cnt++;
                num >>= 1;
            }
            mx = max(mx, num);
            pq.emplace(num, max(cnt, 1));
        }
        
        int answer = mx - pq.top().first;
        while (!pq.empty()) {
            pii cur = pq.top(); pq.pop();
            if (!cur.second) break;
            cur.second--;
            cur.first <<= 1;
            mx = max(mx, cur.first);
            pq.push(cur);
            answer = min(answer, mx - pq.top().first);
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> nums = {
        {1, 2, 3, 4},
        {4, 1, 5, 20, 3},
        {2, 10, 8}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
        ret.push_back(solution.minimumDeviation(nums[i]));

    /* Answer */
    vector<int> answer = {1, 3, 3};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}


// dp[i][j][2] : nums[i]를 홀수상태로 만들고 2^j 만큼 곱해져있을때 가능한 mn과 mx
