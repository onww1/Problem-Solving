/*
 *  BOJ 1062. 가르침
 *
 *  시간 복잡도 : O(21CK-5 * NL) (L : 15)
 *  공간 복잡도 : O(NL)
 *  
 *  기본적으로 있는 a, c, i, n, t를 미리 처리해두고, 나머지 K - 5개를 백트래킹으로 정해서
 *  모든 단어들을 확인해보는 식으로 했습니다. (브루트포스)
 *  그렇게해서 가장 많은 단어를 배울 수 있는 상태를 저장해서 그 값을 출력했습니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;

int N, K, ans;
char words[50][16];
bool alpha[26];

void solve(int T, int P) {
    if (T == K) {   // K개를 다 선정했으면
        int cnt = 0;
        for (int i = 0, j; i < N; ++i) {    // 모든 단어를 보면서 체크
            for (j = 4; words[i][j]; ++j) 
                if (!alpha[words[i][j] - 'a']) break;
            if (!words[i][j]) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    for (int i = P + 1; i < 26; ++i) 
        if (!alpha[i]) {    // 아직 체크 안된애면 체크
            alpha[i] = true;
            solve(T + 1, i);
            alpha[i] = false;
        }
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf(" %s", words[i]);
    alpha[0] = alpha[2] = alpha[8] = alpha[13] = alpha[19] = true; // 이미 있는건 전처리

    if (K < 5) return !printf("0\n");   // K가 5보다 작으면 기본애들을 배울 수 없음.
    solve(5, 0);

    printf("%d\n", ans);
    return 0;
}