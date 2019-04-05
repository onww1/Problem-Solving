#include <cstdio>
#include <algorithm>
using namespace std;

struct wrapper {
	char word[30];
};

int N;
wrapper W[1000];

char toUpper(char c) {
	if ('a' <= c && c <= 'z') return c - 'a' + 'A';
	return c;
}

bool cmp(wrapper A, wrapper B) {
	int LenA = 0, LenB = 0;
	for (; A.word[LenA] && B.word[LenB]; ++LenA, ++LenB) {
		char a = toUpper(A.word[LenA]);
		char b = toUpper(B.word[LenB]);
		if (a == b) continue;
		return a < b;
	}
	if (!A.word[LenA]) return true;
	return false;
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (!N) break;
		for (int i = 0; i < N; ++i) scanf(" %s", W[i].word);
		sort(W, W + N, cmp);
		printf("%s\n", W[0].word);
	}
	return 0;
}