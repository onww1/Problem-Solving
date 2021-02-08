#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int answer = 0, overR = -1, overL = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > R) {
                overR = overL = i;
            } else if (A[i] >= L) {
                overL = i;
                answer += i - overR;
            } else {
                answer += overL - overR;
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> A = {2, 1, 4, 3};
    int L = 2, R = 3;

    /* Output */
    int ret = solution.numSubarrayBoundedMax(A, L, R);

    /* Answer */
    int answer = 3;
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
