#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1e4;
const int INF = 0x3f3f3f3f;
int N, DP[MAX][10];
char src[MAX + 1], dst[MAX + 1];

int solve(int idx, int offset) {
    // 끝까지 도달했으면 움직일 필요 없으므로 0을 리턴
    if (idx == N) return 0;

    // offset에 맞춰서 현재 숫자를 구한다.
    int cur = (src[idx] - '0' + offset) % 10;
    int target = dst[idx] - '0';

    int &ret = DP[idx][cur];
    if (~ret) return ret;
    ret = INF;

    // 오른쪽으로 돌리기
    ret = min(ret, (cur - target + 10) % 10 + solve(idx + 1, offset));

    // 왼쪽으로 돌리기
    ret = min(ret, (target - cur + 10) % 10 + solve(idx + 1, (offset + target - cur + 10) % 10));

    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %s %s", &N, src, dst);
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, 0));
    return 0;
}