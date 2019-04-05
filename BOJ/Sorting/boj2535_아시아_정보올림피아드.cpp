#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
	int nation, num, score;
};

bool cmp(Node a, Node b) { return a.score > b.score; }

int N, C[101];
Node A[101];

int main() {
	scanf("%d", &N);
	for (int i = 0, na, nu, sc; i < N; ++i) {
		scanf("%d %d %d", &na, &nu, &sc);
		A[i] = {na, nu, sc};
	}
	sort(A, A + N, cmp);
	for (int i = 0, idx = 0; i < N; ++i) {
		if (idx == 3) break;
		if (C[A[i].nation] < 2) {
			printf("%d %d\n", A[i].nation, A[i].num);
			C[A[i].nation]++;
			idx++;
		}
	}
	return 0;
}