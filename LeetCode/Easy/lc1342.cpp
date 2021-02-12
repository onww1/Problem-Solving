#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int numberOfSteps (int num) {
        int answer = __builtin_popcount(num);
        for (int i = 19; i > 0; i--) 
            if (num & (1 << i)) {
                answer += i;
                break;
            }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> num = {14, 8, 123};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < num.size(); i++)
        ret.push_back(solution.numberOfSteps(num[i]));

    /* Answer */
    vector<int> answer = {6, 4, 12};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
