#include <cstdio>
typedef long double ldb;

const ldb ERR = 1e-10;
int N, L, W, H;

int main() {
    scanf("%d %d %d %d\n", &N, &L, &W, &H);
    ldb left = 0.0, right = 1e9, mid, ans;
    while (right - left > ERR) {
        mid = (left + right) / 2;
        int cnt = (int)(L / mid) * (int)(W / mid) * (int)(H / mid);
        if (cnt >= N) {
            ans = mid;
            left = mid;
        } else right = mid;
    }

    printf("%.12Lf\n", ans);
    return 0;
}