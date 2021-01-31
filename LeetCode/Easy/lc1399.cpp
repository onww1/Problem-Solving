#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int sum_digits(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int> cnt(37, 0);
        for (int i = 1; i <= n; i++)
            cnt[sum_digits(i)]++;
        int mx = 0, cnt_group = 0;
        for (int i = 1; i < 37; i++) {
            if (mx == cnt[i]) 
                cnt_group++;
            else if (cnt[i] > mx) {
                mx = cnt[i];
                cnt_group = 1;
            }
        }
        return cnt_group;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> n = {13, 2, 15, 24};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.countLargestGroup(n[i]));

    /* Answer */
    vector<int> answer = {4, 2, 6, 5};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
