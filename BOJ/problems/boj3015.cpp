#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

ll N, ans;
vector <pii> st;

int main(int argc, char *argv[]) {
    scanf("%lld", &N);

    for (int i = 0, A, cnt; i < N; ++i) {
        scanf("%d", &A); cnt = 1;

        if (!st.empty()) ans += (st.back().X > A ? 1 : st.back().Y);
        
        while (!st.empty() && st.back().X < A) {
            st.pop_back();
            if (!st.empty()) ans += (st.back().X > A ? 1 : st.back().Y);
        }

        if (!st.empty() && st.back().X == A) {
            cnt += st.back().Y; st.pop_back();
            if (!st.empty()) ans++;
        }

        st.push_back({A, cnt});
    }

    printf("%lld\n", ans);
    return 0;
}