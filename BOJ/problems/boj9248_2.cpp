#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 5e5 + 1;
int T, N, SA[MAX], LCP[MAX];
int RANK[MAX], g[MAX], tg[MAX];
char A[MAX];

// 비교 함수
bool compare(int x, int y) {
	if (g[x] == g[y]) return g[x + T] < g[y + T];
	return g[x] < g[y];
}

int main(int argc, char *argv[]) {
	
	// 입력 & 문자열 길이
	scanf(" %s", A);
	for (T = 1, N = 0; A[N]; ++N);

	// 초기화
	for (int i = 0; i < N; ++i) {
		SA[i] = i;
		g[i] = A[i] - 'a';
	}

	// SA (Suffix Array)
	while (T <= N) {
		g[N] = -1;

		// 그룹에 의한 정렬
		sort(SA, SA + N, compare);

		// 새로운 그룹을 설정
		tg[SA[0]] = 0;
		for (int i = 1; i < N; ++i) {
			// 다른 그룹일 때, 다음 그룹 번호로 지정
			if (compare(SA[i - 1], SA[i])) tg[SA[i]] = tg[SA[i - 1]] + 1;
			
			// 같은 그룹일 때, 같은 그룹 번호로 지정
			else tg[SA[i]] = tg[SA[i - 1]];
		}

		// tg 배열에 있는 그룹 정보를 g 배열로 이동
		for (int i = 0; i < N; ++i) g[i] = tg[i];

		// T 2배 증가
		T <<= 1;
	}

	// LCP (Longest Common Prefix)
	
	// SA 순서를 RANK 배열에 저장
	for (int i = 0; i < N; ++i) RANK[SA[i]] = i;

	// LCP 구하기
	for (int i = 0, len = 0; i < N; ++i) {
		int k = RANK[i];
		if (k > 0) {
			int j = SA[k - 1];
			while (A[j + len] == A[i + len]) len++;
			LCP[k] = len;
			if (len) len--;
		}
	}

	for (int i = 0; i < N; ++i) printf("%d ", SA[i] + 1); printf("\nx ");
	for (int i = 1; i < N; ++i) printf("%d ", LCP[i]); puts("");
	return 0;
}