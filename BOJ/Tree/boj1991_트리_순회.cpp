#include <cstdio>
#include <cstring>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int n;
pii child[26];

void preorder(int node) {
	if (node == -1) return;
	printf("%c", node + 'A');
	preorder(child[node].X);
	preorder(child[node].Y);
}

void inorder(int node) {
	if (node == -1) return;
	inorder(child[node].X);
	printf("%c", node + 'A');
	inorder(child[node].Y);
}

void postorder(int node) {
	if (node == -1) return;
	postorder(child[node].X);
	postorder(child[node].Y);
	printf("%c", node + 'A');
}

int main(int argc, char *argv[]) {
	char pa, l, r;
	scanf("%d", &n);
	memset(child, -1, sizeof(child));
	for (int i = 0; i < n; ++i) {
		scanf(" %c %c %c", &pa, &l, &r);
		if (l != '.') child[pa - 'A'].X = l - 'A';
		if (r != '.') child[pa - 'A'].Y = r - 'A';
	}

	preorder(0);	puts("");
	inorder(0);		puts("");
	postorder(0);	puts("");

	return 0;
}