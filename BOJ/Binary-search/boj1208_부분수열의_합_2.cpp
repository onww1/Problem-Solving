#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

int N, S, A[20], B[20];
int SA[1 << 20], SB[1 << 20];

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &S);
    for (int i = 0; i < N / 2; ++i) scanf("%d", A + i);
    for (int i = 0; i < (1 << (N / 2)); ++i) {
        for (int j = 0; j < N / 2; ++j) {
            if (i & (1 << j)) SA[i] += A[j];
        }
    }
    sort(SA, SA + (1 << (N / 2)));

    for (int i = N / 2; i < N; ++i) scanf("%d", B + i - N / 2);
    for (int i = 0; i < (1 << (N - N / 2)); ++i) {
        for (int j = 0; j < (N - N / 2); ++j) {
            if (i & (1 << j)) SB[i] += B[j];
        }
    }
    sort(SB, SB + (1 << (N - N / 2)));

    ll ans = 0, i, tmp, cnt;
    for (i = 1, tmp = SA[0], cnt = 1; i < (1 << (N / 2)); ++i) {
        if (SA[i] != tmp) {
            int num = upper_bound(SB, SB + (1 << (N - N / 2)), S - tmp) - lower_bound(SB, SB + (1 << (N - N / 2)), S - tmp);
            ans += (cnt * num);

            tmp = SA[i];
            cnt = 1;
        } 
        else cnt++;
    }

    int num = upper_bound(SB, SB + (1 << (N - N / 2)), S - tmp) - lower_bound(SB, SB + (1 << (N - N / 2)), S - tmp);
    ans += (cnt * num);

    if (S == 0) ans--;
    printf("%lld\n", ans);
    return 0;
}