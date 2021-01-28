#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    const int INF = 1e8;

    int maxScoreSightseeingPair(vector<int>& A) {
        int answer = -INF, mx = A[0], idx = 0;
        for (int i = 1; i < A.size(); i++) {
            answer = max(answer, A[i] + mx + idx - i);
            if (mx + idx - i < A[i]) {
                mx = A[i];
                idx = i;
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> A = {8, 1, 5, 2, 6};

    /* Output */
    int ret = solution.maxScoreSightseeingPair(A);

    /* Answer */
    int answer = 11;

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
