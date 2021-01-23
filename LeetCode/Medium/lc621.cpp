#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task: tasks) cnt[task - 'A']++;
        sort(cnt.begin(), cnt.end(), greater<int>());
        int mx_cnt = 1;
        for (int i = 1; i < 26; i++) {
            if (cnt[i] == cnt[0]) mx_cnt++;
            else break;
        }
        int value = cnt[0] + n * (cnt[0] - 1) + mx_cnt - 1;
        return mx_cnt >= n + 1 || value < tasks.size() ? tasks.size() : value;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<char>> tasks = {
        {'A', 'A', 'A', 'B', 'B', 'B'},
        {'A', 'A', 'A', 'B', 'B', 'B'},
        {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}
    };
    vector<int> n = {2, 0, 2};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.leastInterval(tasks[i], n[i]));

    /* Answer */
    vector<int> answer = {8, 6, 16};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}