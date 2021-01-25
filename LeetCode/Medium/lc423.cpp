#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    string getNumberString(char num) {
        switch (num) {
        case '0': return "zero";
        case '1': return "one";
        case '2': return "two";
        case '3': return "three";
        case '4': return "four";
        case '5': return "five";
        case '6': return "six";
        case '7': return "seven";
        case '8': return "eight";
        case '9': return "nine";
        }
        return "";
    }

    string originalDigits(string s) {
        string order = "zxsvfgwtio";
        string number = "0675482391";
        vector<int> cnts(256, 0);
        for (char c: s) cnts[c]++;
        string answer = "";
        for (int i = 0; i < order.length(); i++) {
            string number_string = getNumberString(number[i]);
            int cnt = cnts[order[i]];
            for (int j = 0; j < cnt; j++) {
                answer += number[i];
                for (char c: number_string)
                    cnts[c]--;
            }
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> inputs = {
        "owoztneoer",
        "fviefuro"
    };

    /* Output */
    vector<string> ret;
    for (int i = 0; i < inputs.size(); i++)
        ret.push_back(solution.originalDigits(inputs[i]));

    /* Answer */
    vector<string> answer = {
        "012",
        "45"
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}

/*
zero -> z 1
one -> o 10
two -> w 7
three -> t 8
four -> f 5
five -> v 4
six -> x 2
seven -> s 3
eight -> g 6
nine -> i 9
*/