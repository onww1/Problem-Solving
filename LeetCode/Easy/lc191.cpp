#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);   
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<uint32_t> n = {
        0b00000000000000000000000000001011,
        0b00000000000000000000000010000000,
        0b11111111111111111111111111111101
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.hammingWeight(n[i]));

    /* Answer */
    vector<int> answer = {3, 1, 31};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
