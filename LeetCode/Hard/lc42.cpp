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
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        
        int n = height.size();
        int answer = 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > leftMax) 
                    leftMax = height[left];
                else
                    answer += leftMax - height[left];
                left++;
            } else {
                if (height[right] > rightMax)
                    rightMax = height[right];
                else
                    answer += rightMax - height[right];
                right--;
            }
        }

        return answer;
    }

    int trapV2(vector<int>& height) {
        if (height.empty())
            return 0;

        int n = height.size();
        vector<int> right(n, 0);

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1], height[i]);
        
        int answer = 0, leftMax = 0;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            answer += min(leftMax, right[i]) - height[i];
        }

        return answer;
    }

    int trapV1(vector<int>& height) {
        if (height.empty())
            return 0;

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < height.size(); i++) 
            pq.emplace(height[i], i);
        
        int left = pq.top().second;
        int right = pq.top().second;
        pq.pop();

        int answer = 0;
        while (!pq.empty()) {
            int h = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            if (left <= idx && idx <= right)
                continue;

            for (int i = idx + 1; i < left; i++) 
                answer += h - height[i];
            left = min(left, idx);

            for (int i = right + 1; i < idx; i++)
                answer += h - height[i];
            right = max(right, idx);
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> height = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1},
        {4, 2, 0, 3, 2, 5}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < height.size(); i++)
        ret.push_back(solution.trap(height[i]));

    /* Answer */
    vector<int> answer = {6, 9};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
