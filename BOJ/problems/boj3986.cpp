#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e5;
int N, ans;
char in[MAX + 1];
vector <char> st;

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        st.clear();
        scanf(" %s", in);
        for (int j = 0; in[j]; ++j) {
            if (!st.empty() && st.back() == in[j]) st.pop_back();
            else st.push_back(in[j]);
        }
        if (st.empty()) ans++;
    }

    printf("%d\n", ans);
    return 0;
}