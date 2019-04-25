#include <stdio.h>
#include <algorithm>
using namespace std;

struct Trie {
	Trie* child[2];
	Trie() { child[0] = child[1] = 0; }
	~Trie() {
		for (int i = 0; i < 2; ++i)
			if (child[i]) delete child[i];
	}
	void insert(int N, int exp) {
		if (exp < 0) return;
		int next = N >> exp; 
		if (next) N ^= (1 << exp);
		if (!child[next]) child[next] = new Trie;
		child[next]->insert(N, exp - 1);
	}
	int query(int N, int s, int exp) {
		if (exp < 0) return 0;
		int next = N >> exp;
		if (next) N ^= (1 << exp);
		if (exp == s) return child[1]->query(N, s, exp - 1) + (1 << exp);
		if (child[next]) return child[next]->query(N, s, exp - 1);
		return child[1 - next]->query(N, s, exp - 1) + (1 << exp);
	}
};

const int MAX = 2e5;
int N, A[MAX];
long long ans;
Trie* t;

void solve(int s, int e, int exp) {
	if (exp < 0 || s + 1 >= e) return;
	int target = ((A[s] >> (exp + 1)) << (exp + 1)) + (1 << exp);
	int idx = lower_bound(A + s, A + e, target) - A;

	if (s < idx && idx < e) {
		int mn = 0x7f7f7f7f;
		for (int i = s; i < idx; ++i) 
			mn = min(mn, t->query(A[i], exp, 29));
		ans += mn;
	}

	solve(s, idx, exp - 1);
	solve(idx, e, exp - 1);	
}

int main(int argc, char *argv[]) {
	t = new Trie;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	sort(A, A + N);
	N = unique(A, A + N) - A;
	
	for (int i = 0; i < N; ++i) t->insert(A[i], 29);
	solve(0, N, 29);
	printf("%lld\n", ans);
	delete t;
	return 0;
}
