#include <stdio.h>

class Trie {
public:
	Trie* child[2];
	Trie() {
		for (int i = 0; i < 2; ++i) child[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < 2; ++i) 
			if (child[i]) delete child[i];
	}
	void insert(const char* key) {
		if (*key == '\0') return;
		int next = *key - '0';
		if (!child[next]) child[next] = new Trie;
		return child[next]->insert(key + 1);
	}
	void query (char* key) {
		if (*key == '\0') return;
		int next = *key - '0';
		next ^= 1;
		if (child[next]) {
			*key = '1';
			return child[next]->query(key + 1);
		} else {
			*key = '0';
			return child[next ^ 1]->query(key + 1);
		}
	}
};

void dec_to_binary(int dec, char* res) {
	for (int i = 0; i < 30; ++i) 
		res[i] = (dec & (1 << (29 - i))) ? '1' : '0';
}

int binary_to_dec(char* binary) {
	int ret = 0;
	for (int i = 0; binary[i]; ++i) 
		ret = ret * 2 + binary[i] - '0';
	return ret;
}

const int MAX = 1e5;
int N, A, mx;
char binary[MAX][31];

int main(int argc, char *argv[]) {
	Trie *root = new Trie;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A);
		dec_to_binary(A, binary[i]);
		root->insert(binary[i]);
	}

	char tmp[31];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 30; ++j) tmp[j] = binary[i][j];
		root->query(tmp);
		int val = binary_to_dec(tmp);
		mx = mx < val ? val : mx;
	}

	printf("%d\n", mx);
	delete root;
	return 0;
}