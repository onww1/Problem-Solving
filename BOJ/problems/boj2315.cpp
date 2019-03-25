/*
 *  BOJ 2315. 가로등 끄기
 *  
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N^2)
 * 
 *  DP[i][j][k] : j ~ k 구간을 끌 때 낭비되는 전력의 최솟값.
 *                i가 1이면 왼쪽을 마지막으로 끈 상태, 0이면 오른쪽을 마지막으로 끈 상태 
 *
 *  위와 같이 DP 항을 정의해두고, 가장 왼쪽을 끌 때와 오른쪽을 끌 떄에 대한 값을 갱신해 나갑니다.
 *  이때 낭비되는 전력의 경우 부분합을 구해두고, 전체 합에서 끈 부분의 합을 빼서 현재 이동하는 거리만큼
 *  곱해주면 미래에 낭비될 전력도 함께 계산되기 때문에 현재 거리만 보면 됩니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int MAX = 1e3;
const ll LL_INF = 0x3f3f3f3f3f3f3f3fLL;
int N, M, D[MAX + 1], W[MAX + 1];
ll DP[2][MAX + 1][MAX + 1], P[MAX + 1];

ll solve(int left, int start, int end) {
    if (start == M && end == M) return 0;   // start와 end가 둘 다 M이면 0 리턴
    else if (start == M && end > M && left == 1) return LL_INF; // M이 마지막일 수 없는데 마지막이라고 할 경우 무한대 리턴
    else if (start < M && end == M && left == 0) return LL_INF; // M이 마지막일 수 없는데 마지막이라고 할 경우 무한대 리턴

    // 이미 값이 있으면 리턴
    ll &ret = DP[left][start][end];
    if (ret != -1) return ret;
    ret = LL_INF;

    if (left) { // 왼쪽을 끄는 경우에 대한 값인 상황
        // 부분문제에서 마지막으로 끈 것이 왼쪽일 경우
        ret = min(ret, solve(1, start + 1, end) + (P[N] - P[end] + P[start]) * (D[start + 1] - D[start]));
        // 부분문제에서 마지막으로 끈 것이 오른쪽일 경우
        ret = min(ret, solve(0, start + 1, end) + (P[N] - P[end] + P[start]) * (D[end] - D[start]));
    } else { // 오른쪽을 끄는 경우에 대한 값인 상황
        // 부분문제에서 마지막으로 끈 것이 왼쪽일 경우
        ret = min(ret, solve(1, start, end - 1) + (P[N] - P[end - 1] + P[start - 1]) * (D[end] - D[start]));
        // 부분문제에서 마지막으로 끈 것이 오른쪽일 경
        ret = min(ret, solve(0, start, end - 1) + (P[N] - P[end - 1] + P[start - 1]) * (D[end] - D[end - 1]));
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", D + i, W + i);
        P[i] = P[i - 1] + W[i];
    }

    memset(DP, -1, sizeof(DP));
    printf("%lld\n", min(solve(0, 1, N), solve(1, 1, N)));
    return 0;
}
