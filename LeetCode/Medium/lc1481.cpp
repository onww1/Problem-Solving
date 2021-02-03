#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> cnts;
        int cnt = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) {
                cnts.push_back(cnt);
                cnt = 1;
            }
            else cnt++;
        }
        cnts.push_back(cnt);
        sort(cnts.begin(), cnts.end());
        int answer = cnts.size();
        for (int i = 0; i < cnts.size(); i++) {
            if (cnts[i] <= k) {
                answer--;
                k -= cnts[i];
            }
            else break;
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> arr = {
        {5, 5, 4},
        {4, 3, 1, 1, 3, 3, 2}
    };
    vector<int> k = {1, 3};

    /* Output */
    vector<int> ret;
    for (int i = 0; i < arr.size(); i++)
        ret.push_back(solution.findLeastNumOfUniqueInts(arr[i], k[i]));

    /* Answer */
    vector<int> answer = {1, 2};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
