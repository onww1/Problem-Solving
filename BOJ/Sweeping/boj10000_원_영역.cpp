#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;
typedef pair<int, pii> piii;

int n;
pii p[300050];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    for (int i = 0, x, r; i < n; ++i) {
        scanf("%d %d", &x, &r);
        p[i] = { x - r, x + r };
    }
    sort(p, p + n, [](const pii a, const pii b) {
        if (a.X == b.X) return a.Y > b.Y;
        return a.X < b.X;
    });
    
    int ans = n + 1;
    vector <piii> st;
    for (int i = 0, sum = 0; i < n; ++i) {
        while (!st.empty() && st.back().Y.Y <= p[i].X) {
            sum = st.back().Y.Y - st.back().Y.X + st.back().X;
            st.pop_back();
            if (!st.empty() && (st.back().Y.Y - st.back().Y.X == sum))
                ans++;
        }
        st.push_back({sum, p[i]}); sum = 0;
    }

    while (!st.empty()) {
        int sum = st.back().Y.Y - st.back().Y.X + st.back().X;
        st.pop_back();
        if (!st.empty() && (st.back().Y.Y - st.back().Y.X == sum))
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}
