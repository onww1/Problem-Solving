#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int cnt[26]{};
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        bool anagram = true;
        for (int i = 0; i < 26; i++)
            if (cnt[i])
                anagram = false;
        return anagram;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> s = {"anagram", "rat"};
    vector<string> t = {"nagaram", "car"};

    /* Output */
    vector<bool> ret;
    for (int i = 0; i < s.size(); i++) 
        ret.push_back(solution.isAnagram(s[i], t[i]));

    /* Answer */
    vector<bool> answer = {true, false};

    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
