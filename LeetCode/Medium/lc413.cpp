#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) 
            return 0;

        int answer = 0;
        int prv = A[1] - A[0];
        int cnt = 1;

        for (int i = 2; i < A.size(); i++) {
            int diff = A[i] - A[i - 1];
            if (prv == diff) {
                answer += cnt;
                cnt++;
            } else {
                prv = diff;
                cnt = 1;
            }
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> A = {1, 2, 3, 4};

    /* Output */
    int ret = solution.numberOfArithmeticSlices(A);

    /* Answer */
    int answer = 3;

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
