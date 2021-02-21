#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int answer = 0;
        while (Y > X) {
            if (Y % 2 == 0) Y >>= 1;
            else Y++;
            answer++;
        }
        if (Y < X) answer += X - Y;
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> X = {2, 5, 3, 1024};
    vector<int> Y = {3, 8, 10, 1};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < X.size(); i++)
        ret.push_back(solution.brokenCalc(X[i], Y[i]));

    /* Answer */
    vector<int> answer = {2, 2, 3, 1023};
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
