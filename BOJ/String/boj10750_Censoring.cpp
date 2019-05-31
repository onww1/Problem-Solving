#include <algorithm>
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

char text[1000001], pattern[101];
int len_text, len_pattern, failure_function[100];

int main(int argc, char *argv[]) {
    scanf(" %s %s", text, pattern);
    for (; text[len_text]; ++len_text);
    for (; pattern[len_pattern]; ++len_pattern);

    // failure function
    for (int i = 1, j = 0; i < len_pattern; ++i) {
        while (j && pattern[i] != pattern[j]) j = failure_function[j - 1];
        if (pattern[i] == pattern[j]) failure_function[i] = ++j;
    }

    deque <char> dtext(text, text + len_text);
    vector <char> st;

    // matching
    int j = 0;
    while (!dtext.empty()) {
        st.push_back(dtext.front());
        dtext.pop_front();
        while (j && st.back() != pattern[j]) j = failure_function[j - 1];
        if (st.back() == pattern[j]) {
            if (j == len_pattern - 1) {
                for (int i = 0; i < len_pattern; ++i) st.pop_back();
                for (int i = 0; !st.empty() && i < len_pattern; ++i) {
                    dtext.push_front(st.back());
                    st.pop_back();
                }
                j = 0;
            }
            else ++j;
        }
    }

    // output
    text[st.size()] = 0;
    while (!st.empty()) {
        text[st.size() - 1] = st.back(); 
        st.pop_back();
    }
    printf("%s\n", text);
    return 0;
}