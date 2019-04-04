/*
 *  BOJ 2624. 동전 바꿔주기
 *
 *  시간 복잡도 : O(KT)
 *  공간 복잡도 : O(KT)
 *
 *  DP[i][j] : i번째 동전부터 뒷 동전까지 사용해서 j원을 바꿔줄 수 있는 경우의 수
 *
 *  위와 같이 DP항을 정의하고 재귀적으로 호출하여 탑다운 방식으로 해결하였습니다.
 */

#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int KMAX = 100, TMAX = 10000;
int T, K, DP[KMAX + 1][TMAX + 1];
pii P[KMAX + 1];

int solve(int idx, int remain) {
    if (idx == K) {
        if (!remain) return 1;  // 마지막 인덱스까지 왔을 때, remain이 0이면 가능한 경우이므로 1을 리턴
        return 0;   // 아니라면 가능하지 않은 경우이므로 0을 리턴
    }

    int &ret = DP[idx][remain];
    if (ret != -1) return ret;
    ret = 0;

    for (int i = 0; i <= P[idx].Y; ++i) {
        // 가능한 수에 대해서 모두 돌려봄.
        if (remain - P[idx].X * i >= 0) {
            ret += solve(idx + 1, remain - P[idx].X * i);
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &T, &K);
    for (int i = 0, k, n; i < K; ++i) {
        scanf("%d %d", &k, &n);
        P[i] = {k, n};
    }
    sort(P, P + K, greater<pii>()); // 내림차순으로 정렬
    memset(DP, -1, sizeof(DP));
    printf("%d\n", solve(0, T));
    return 0;
}