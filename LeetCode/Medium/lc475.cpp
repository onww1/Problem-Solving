#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int lo = 0, hi = max(heaters.back(), houses.back()) - min(heaters[0], houses[0]);
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (canCover(houses, heaters, mid)) 
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        return lo;
    }

    bool canCover(vector<int>& houses, vector<int>& heaters, int radius) {
        if (houses[0] < heaters[0] - radius || houses.back() > heaters.back() + radius) 
            return false;

        int lastCover = 0, i = 0;
        for (int heater: heaters) {
            int left = max(lastCover, heater - radius);
            lastCover = heater + radius;
            while (i < houses.size()) {
                if (houses[i] < left) 
                    return false;
                else if (houses[i] > lastCover)
                    break;
                i++;
            }
        }
        
        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<int>> houses = {
        {1, 2, 3},
        {1, 2, 3, 4},
        {1, 5}
    };
    vector<vector<int>> heaters = {
        {2},
        {1, 4},
        {2}
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < houses.size(); i++)
        ret.push_back(solution.findRadius(houses[i], heaters[i]));

    /* Answer */
    vector<int> answer = {1, 1, 3};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
