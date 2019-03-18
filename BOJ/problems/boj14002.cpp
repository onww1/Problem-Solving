#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

vector <pii> lis;
int N, A[1001], P[1001];

int main(int argc, char *argv[]) {
    memset(P, -1, sizeof(P));
    scanf("%d %d", &N, A);
    lis.push_back({A[0], 0});

    for (int i = 1; i < N; ++i) {
        scanf("%d", A + i);
        if (lis.back().X < A[i]) {
            P[i] = lis.back().Y;
            lis.push_back({A[i], i});
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), pii(A[i], -1));
            if (it - lis.begin() > 0) P[i] = lis[it - lis.begin() - 1].Y;
            *it = {A[i], i};
        }
    }

    vector <int> st;
    int p = lis.back().Y;
    while (p >= 0) {
        st.push_back(A[p]);
        p = P[p];
    }

    printf("%lu\n", lis.size());
    while (!st.empty()) {
        printf("%d ", st.back());
        st.pop_back();
    }

    puts("");
    return 0;
}
