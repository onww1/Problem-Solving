#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
char T[MAX + 2], P[MAX + 2];
int LT, LP, F[MAX + 2], ans[MAX + 2], idx;

int main(int argc, char *argv[]) {
	
	// input
	fgets(T, sizeof(T), stdin);
	fgets(P, sizeof(P), stdin);

	// get string length
	for (LT = 0; T[LT]; ++LT);
	for (LP = 0; P[LP]; ++LP);

	// remove newline character
	if (T[LT - 1] == '\n') T[--LT] = 0;
	if (P[LP - 1] == '\n') P[--LP] = 0;

	// fail function
	for (int i = 1, j = 0; i < LP; ++i) {
		while (j > 0 && P[i] != P[j]) j = F[j - 1];
		if (P[i] == P[j]) F[i] = ++j;
	}

	// matching
	for (int i = 0, j = 0; i < LT; ++i) {
		while (j > 0 && T[i] != P[j]) j = F[j - 1];
		if (T[i] == P[j]) {
			if (j == LP - 1) {
				ans[idx++] = i - LP + 2;
				j = F[j];
			}
			else j++;
		}
	}

	// output
	printf("%d\n", idx);
	for (int i = 0; i < idx; ++i) printf("%d ", ans[i]); puts("");
	return 0;
}