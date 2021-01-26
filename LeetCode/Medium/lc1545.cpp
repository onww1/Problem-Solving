#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int center = (1 << (n - 1));
        if (center == k) return '1';
        if (k < center) return findKthBit(n - 1, k);
        k = 2 * center - k;
        char ret = findKthBit(n - 1, k);
        return ret == '1' ? '0' : '1';
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> n = {3, 4, 1, 2};
    vector<int> k = {1, 11, 1, 3};

    /* Output */
    vector<char> ret;
    for (int i = 0; i < n.size(); i++)
        ret.push_back(solution.findKthBit(n[i], k[i]));

    /* Answer */
    vector<char> answer = {'0', '1', '0', '1'};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
