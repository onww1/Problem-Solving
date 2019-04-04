/*
 *	BOJ 1467. 수 지우기
 *
 *	시간 복잡도 : O(N^2)
 *	공간 복잡도 : O(N)
 *
 *	일단 원래 수와 지워야 할 수들을 체크하면서 각 숫자가 몇개씩 있는지 카운트합니다.
 *	이후, 원래 수에서 처음 자리부터 시작해서 하나씩 확인을 하는데, 이때 이것을 지울지 말지를 결정합니다.
 *	그것을 결정하는 기준은 자신 이후에 나오는 수 중에서 자신보다 작은 수가 절대 없어지지 않는 것이 확인되면 지우면 안되고,
 *	자신보다 큰 수가 절대 없어지지 않는 것이 확인되면 지워야 합니다.
 *	그렇게 쭉 돌면 답이 나옵니다!
 */

#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX = 1e3;
char A[MAX + 1], R[MAX + 1], ans[MAX + 1];
int AC[10], RC[10], idx;

int main(int argc, char *argv[]) {
	// 입력을 받고, 각 숫자를 카운트
    scanf(" %s %s", A, R);
    for (int i = 0; A[i]; ++i) AC[A[i] - '0']++;
    for (int i = 0; R[i]; ++i) RC[R[i] - '0']++;
  
    for (int i = 0; A[i]; ++i) {
        int N = A[i] - '0';
        AC[N]--;

        if (RC[N]) {
        	// 지워야 할 수와 남은 수가 같다면 지운다.
            if (RC[N] > AC[N]) { RC[N]--; continue; }

            int cnt[10]{}; // 자신보다 작은 수를 카운트 -> 지웠을 경우를 가정함
            bool GO = false; // 지울지 말지 확인하는 변수

            for (int j = i + 1; A[j]; ++j) {
            	// 자신보다 작은 수
                if (A[j] < A[i]) {
                    cnt[A[j] - '0']++;
                    // 현재 수까지 지웠다고 가정했을 때, 지워야 하는 수보다 많다면 이 수는
                    // 절대 지워지지 않으므로 현재 보고 있는 수를 지우면 안된다.
                    if (cnt[A[j] - '0'] > RC[A[j] - '0']) break;
                } 
                // 자신보다 큰 수
                else if (A[j] > A[i]) {
                	// 이 수의 남은 갯수가 지워야 하는 수보다 많다면 이것을 지울 필요가 없기 때문에
                	// 현재 보고 있는 수를 지운다.
                    if (AC[A[j] - '0'] > RC[A[j] - '0']) {
                        GO = true;
                        break;
                    }
                }
            }

            // 지워야 한다는 판단이 내려지면 지운다.
            if (GO) { RC[N]--; continue; }
        }

        // 지우지 않는 것들은 ans 배열에 쌓아준다.
        ans[idx++] = A[i];
    }

    ans[idx] = 0;
    printf("%s\n", ans);
    return 0;
}
