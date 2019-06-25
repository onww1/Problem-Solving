#include <algorithm>
#include <cstdio>
using namespace std;

int n, ans[11], ofs[11], sum[11][11];
char in[56];

bool solve(int idx) {
    if (idx == n + 1) return true;
    if (in[ofs[idx]] == '0') {
        int j = 1;
        for (; j < idx; ++j) {
            sum[j][idx] = sum[j][idx - 1];
            if ((sum[j][idx] > 0 && in[ofs[j] + idx - j] == '+') ||
                (sum[j][idx] < 0 && in[ofs[j] + idx - j] == '-') ||
                (sum[j][idx] == 0 && in[ofs[j] + idx - j] == '0') );
            else break;
        }
        return j == idx && solve(idx + 1);
    }
    int sgn = (in[ofs[idx]] == '-' ? -1 : 1);
    for (int i = 1, j; i <= 10; ++i) {
        ans[idx] = sum[idx][idx] = i * sgn;
        for (j = 1; j < idx; ++j) {
            sum[j][idx] = sum[j][idx - 1] + ans[idx];
            if ((sum[j][idx] > 0 && in[ofs[j] + idx - j] == '+') ||
                (sum[j][idx] < 0 && in[ofs[j] + idx - j] == '-') ||
                (sum[j][idx] == 0 && in[ofs[j] + idx - j] == '0') );
            else break;
        }
        if (j == idx && solve(idx + 1)) return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d %s", &n, in);
    for (int i = 2; i <= n; ++i) 
        ofs[i] = ofs[i - 1] + n - i + 2;
    solve(1);
    for (int i = 1; i <= n; ++i) printf("%d ", ans[i]); puts("");
    return 0;
}