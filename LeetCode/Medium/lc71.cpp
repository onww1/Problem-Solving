#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

/* Solution Class */
class Solution {
public:
    void handleToken(string& path, int start, int len, vector<string>& st) {
        string token = path.substr(start, len);
        if (token == ".");
        else if (token == "..") {
            if (!st.empty())
                st.pop_back();
        }
        else st.push_back(token);
    }

    string simplifyPath(string path) {
        vector<string> st;
        int p = 1;
        for (int i = 1; i < path.length(); i++) {
            if (path[i] == '/') {
                if (i == p) {
                    p++;
                    continue;
                }
                handleToken(path, p, i - p, st);
                p = i + 1;
            }
        }
        if (p < path.length()) 
            handleToken(path, p, path.length() - p, st);
        
        string answer = "";
        for (int i = 0; i < st.size(); i++) {
            answer += '/';
            answer += st[i];
        }
        if (answer.empty()) answer += '/';
        return answer;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    /* Input */
    vector<string> path = {
        "/home/",
        "/../",
        "/home//foo/",
        "/a/./b/../../c/"
    };

    /* Output */
    vector<string> ret;
    for (int i = 0; i < path.size(); i++)
        ret.push_back(solution.simplifyPath(path[i]));

    /* Answer */
    vector<string> answer = {
        "/home",
        "/",
        "/home/foo",
        "/c"
    };
    
    /* Check */
    assert(ret == answer);

    puts("PASS!");
    return 0;
}
