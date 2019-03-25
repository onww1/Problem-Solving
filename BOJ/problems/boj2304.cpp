#include <algorithm>
#include <cstdio>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1e5;
int N, HMX, C;
pii P[MAX];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &P[i].X, &P[i].Y);
        if (HMX < P[i].Y) {
            HMX = P[i].Y;
            C = 1;
        } else if (HMX == P[i].Y) C++;
    }
    sort(P, P + N);

    vector <pii> st;
    st.push_back({0, 0});

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (C && ((!st.empty() && st.back().Y < P[i].Y) || P[i].Y == HMX)) {
            ans += (st.back().Y * (P[i].X - st.back().X));
            st.push_back(P[i]);
        } 
        if (!C) {
            while (!st.empty() && st.back().Y < P[i].Y) st.pop_back();
            st.push_back(P[i]);
        }

        if (P[i].Y == HMX) C--;
    }

    for (int i = st.size() - 1; i >= 0; --i) {
        if (st[i].Y == HMX) {
            ans += HMX;
            break;
        } else ans += st[i].Y * (st[i].X - st[i - 1].X);
    }

    printf("%d\n", ans);
    return 0;
}