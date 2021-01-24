#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> spaces(maxWidth + 1);
        spaces[0] = "";
        for (int i = 1; i <= maxWidth; i++)
            spaces[i] = spaces[i - 1] + " ";

        vector<string> answer;
        int i = 0;
        while (i < n) {
            int sum = 0, cnt = 0;
            while (i < n && sum + words[i].length() + cnt <= maxWidth) {
                sum += words[i++].length();
                cnt++;
            }
            string cur = "";
            int rest = maxWidth - sum;
            if (i == n) {
                cur += words[i - cnt];
                for (int j = i - cnt + 1; j < i; j++) {
                    cur += " ";
                    cur += words[j];
                }
                cur += spaces[maxWidth - sum - cnt + 1];
            }
            else if (cnt == 1) {
                cur += words[i - cnt];
                cur += spaces[rest];
            }
            else {
                int q = rest / (cnt - 1), r = rest % (cnt - 1);
                cur += words[i - cnt];
                for (int j = i - cnt + 1; j < i; j++) {
                    if (r) {
                        cur += spaces[q + 1];
                        r--;
                    }
                    else cur += spaces[q];
                    cur += words[j];
                }
            }
            answer.push_back(cur);
        }

        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<vector<string>> words = {
        {"This", "is", "an", "example", "of", "text", "justification."},
        {"What","must","be","acknowledgment","shall","be"},
        {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"}
    };
    vector<int> maxWidth = {16, 16, 20};

    /* Output */
    vector<vector<string>> ret;
    for (int i = 0; i < words.size(); i++)
        ret.push_back(solution.fullJustify(words[i], maxWidth[i]));

    /* Answer */
    vector<vector<string>> answer = {
        {"This    is    an", "example  of text", "justification.  "},
        {"What   must   be", "acknowledgment  ", "shall be        "},
        {"Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "}
    };

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}