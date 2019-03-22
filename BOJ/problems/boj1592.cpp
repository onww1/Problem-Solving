/*
 *  BOJ 1592. 영식이와 친구들
 *
 *  시간 복잡도 : O(N^2)
 *  공간 복잡도 : O(N)
 *
 *  문제에서 하라는대로 실행만 해주면 됩니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e3;
int N, M, L, cnt[MAX];

int main(int argc, char *argv[]) {
    scanf("%d %d %d", &N, &M, &L);
    int cur = 0, ans = 0;
    while (1) {
        cnt[cur]++;
        if (cnt[cur] == M) break;

        if (cnt[cur] % 2) cur = (cur + L) % N;
        else cur = (cur + N - L) % N;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}