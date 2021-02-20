#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> value_symbol = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string answer = "";
        for (int i = 0; i < value_symbol.size(); i++) {
            while (value_symbol[i].first <= num) {
                answer += value_symbol[i].second;
                num -= value_symbol[i].first;
            }
        }
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<int> num = {3, 4, 9, 58, 1994};

    /* Output */
    vector<string> ret;
    for (int i = 0; i < num.size(); i++)
        ret.push_back(solution.intToRoman(num[i]));

    /* Answer */
    vector<string> answer = {"III", "IV", "IX", "LVIII", "MCMXCIV"};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
