#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;

int N, A, mn[7], mx[7];
int main(int argc, char *argv[]) {
    scanf("%d", &N);

    ll sum = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &A);
        sum += A;
        int mod = sum % 7;
        if (!mn[mod]) mn[mod] = i;
        mx[mod] = i;
    }

    int ans = mx[0];
    for (int i = 1; i < 7; ++i) ans = max(ans, mx[i] - mn[i]);
    printf("%d\n", ans);

    return 0;
}