#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 5e5 + 5;
int N, SA[MAX], LCP[MAX];
char S[MAX];

void countingSort(const int *A, const int *B, int *C, int N, int M);
void suffixArray(const char *A, int *C, int N);
void longestCommonPrefix(const int *A, const char *B, int *C, int N);

int main(int argc, char *argv[]) {
	
	scanf(" %s", S);
	for (N = 0; S[N]; ++N);

	suffixArray(S, SA, N);
	longestCommonPrefix(SA, S, LCP, N);

	for (int i = 0; i < N; ++i) printf("%d ", SA[i] + 1);	printf("\nx ");
	for (int i = 1; i < N; ++i) printf("%d ", LCP[i]);		puts("");
	return 0;

}

int cnt[MAX];
void countingSort(const int *A, const int *B, int *C, int N, int M) {
	for (int i = 0; i <= M; ++i) cnt[i] = 0;
	for (int i = 0; i < N; ++i) cnt[B[A[i]]]++;
	for (int i = 1; i <= M; ++i) cnt[i] += cnt[i - 1];
	for (int i = N; i--; C[--cnt[B[A[i]]]] = A[i]);
}

int g[MAX], tg[MAX];
void suffixArray(const char *A, int *C, int N) {
	int i, j, k;
	for (i = 0; i < N; ++i) {
		g[i] = A[i] - 'a' + 1;
		tg[i] = i;
	}

	countingSort(tg, g, C, N, 26);
	for (i = k = 1; i < N && k < N; i <<= 1) {
		for (k = 0; k < i; ++k) tg[k] = k - i + N;
		for (j = 0; j < N; ++j) if (C[j] >= i) tg[k++] = C[j] - i;
		countingSort(tg, g, C, N, k);
		tg[C[0]] = k = 1;
		for (j = 1; j < N; ++j) {
			if (g[C[j]] != g[C[j - 1]] || g[C[j] + i] != g[C[j - 1] + i]) ++k;
			tg[C[j]] = k;
		}
		for (j = 0; j < N; ++j) g[j] = tg[j];
	}
}

void longestCommonPrefix(const int *A, const char *B, int *C, int N) {
	int i, j;
	for (i = 0; i < N; ++i) tg[A[i]] = i;
	for (i = j = 0; i < N; ++i) {
		if (tg[i]) {
			while (B[i + j] == B[A[tg[i] - 1] + j]) ++j;
			C[tg[i]] = j;
		}
		if (j) j--;
	}
}