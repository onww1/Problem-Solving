/*
 *  BOJ 1141. 접두사
 *  
 *  시간 복잡도 : O(N^2 * L) (L : 단어 길이)
 *  공간 복잡도 : O(NL)
 *  
 *  단어들을 입력받고, 문자열을 비교하면서 접두사인지 체크를 하고, 접두사인애를 표시해둡니다.
 *  접두사 X 집합은 접두사인 애만 제거하면 될 것이라고 생각을 하여 그것들만 제외하고 카운트하였습니다.
 */

#include <algorithm>
#include <cstdio>
using namespace std;

int N, P[51];
char W[51][51];

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf(" %s", W[i]);
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1, k; j <= N; ++j) {
            // 문자열 비교 -> 서로 다른 부분에서 멈춤.
            for (k = 0; W[i][k] && W[j][k]; ++k) 
                if (W[i][k] != W[j][k]) break;

            if (!W[i][k]) P[i] = 1; // 앞 문자열이 끝까지 갔으면 접두사
            else if (!W[j][k]) P[j] = 1; // 뒷 문자열이 끝까지 갔으면 접두사
        }
    }

    // 접두사가 아닌 것만 카운트해서 출력
    int cnt = 0;
    for (int i = 1; i <= N; ++i) if (!P[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}