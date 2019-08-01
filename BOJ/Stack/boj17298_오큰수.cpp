#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1;
int n, a[MAX], nge[MAX];
vector <int> st;

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty()) {
            if (st.back() > a[i]) {
                nge[i] = st.back();
                break;
            }
            st.pop_back();
        }
        if (st.empty()) nge[i] = -1;
        st.push_back(a[i]);
    }
    for (int i = 0; i < n; ++i) printf("%d ", nge[i]); puts("");
    return 0;
}