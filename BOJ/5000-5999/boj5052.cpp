#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie {
	bool finish;
	Trie *next[10];

	Trie() {
		finish = false;
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < 10; ++i)
			if (next[i]) delete next[i];
	}

	void insert(const char *key) {
		if (*key == 0) finish = true;
		else {
			int cur = *key - '0';
			if (next[cur] == 0) next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}

	int find(const char *key) {
		if (*key == 0) return 0;
		if (finish) return 1;
		int cur = *key - '0';
		next[cur]->find(key + 1);
	}
};

const int MAX = 10000;
int T, N;
char A[MAX + 1][11];

int main(int argc, char *argv[]) {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &N);
		Trie *root = new Trie();
		for (int i = 0; i < N; ++i) scanf(" %s", A[i]), root->insert(A[i]);
		bool hasPrefix = false;
		for (int i = 0; i < N; ++i)
			if (root->find(A[i])) hasPrefix = true;
		printf("%s\n", hasPrefix ? "NO" : "YES");
	}
	return 0;
}