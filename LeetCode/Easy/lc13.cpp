#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

/* Solution Class */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> dict;
        dict["I"] = 1;
        dict["IV"] = 4;
        dict["V"] = 5;
        dict["IX"] = 9;
        dict["X"] = 10;
        dict["XL"] = 40;
        dict["L"] = 50;
        dict["XC"] = 90;
        dict["C"] = 100;
        dict["CD"] = 400;
        dict["D"] = 500;
        dict["CM"] = 900;
        dict["M"] = 1000;
        
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && dict.count(s.substr(i, 2))) {
                answer += dict[s.substr(i, 2)];
                i++;
            }
            else {
                answer += dict[s.substr(i, 1)];
            }
        }
        
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {
        "III",
        "IV",
        "IX",
        "LVIII",
        "MCMXCIV"
    };

    /* Output */
    vector<int> ret;
    for (int i = 0; i < s.size(); i++)
        ret.push_back(solution.romanToInt(s[i]));

    /* Answer */
    vector<int> answer = {3, 4, 9, 58, 1994};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
