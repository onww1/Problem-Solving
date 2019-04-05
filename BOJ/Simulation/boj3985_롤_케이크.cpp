/*
 *  BOJ 3985. 롤 케이크
 *
 *  시간 복잡도 : O(NL)
 *  공간 복잡도 : O(L)
 *
 *  사람들이 주는 구간에 대해서 만약 그 구간에 어떤 값도 없으면 그 사람의 인덱스를 넣어주고 카운트 하는 식으로
 *  실제 받는 값을 계산해서 max를 갱신하고, 기대값은 그저 구간의 길이를 갱신하면 되기때문에 그렇게 모두 확인하고
 *  마지막에 출력해주는 식으로 했습니다.
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#define X first
#define Y second
using namespace std;
typedef pair <int, int> pii;

const int MAX = 1000;
int cake[MAX + 1], L, N, P, K;
pii ex_max, real_max;

int main(int argc, char *argv[]) {
    scanf("%d %d", &L, &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d", &P, &K);

        // 가장 많은 조각을 받을 것으로 기대하는 방청객을 갱신
        if (ex_max.X < K - P + 1) ex_max = {K - P + 1, i};
        
        // 실제 수를 계산
        int cnt = 0;
        for (int j = P; j <= K; ++j) {
            if (!cake[j]) {
                cake[j] = i;
                cnt++;
            }
        }

        // 실제로 가장 많은 조각을 받는 방청객을 갱신
        if (real_max.X < cnt) real_max = {cnt, i};
    }

    printf("%d\n%d\n", ex_max.Y, real_max.Y);
    return 0;
}