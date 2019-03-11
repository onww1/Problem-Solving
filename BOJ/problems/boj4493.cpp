#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<char,char> pcc;

map <pcc, int> dict;
void init() {
	dict[pcc('R', 'P')] = dict[pcc('S', 'R')] = dict[pcc('P', 'S')] = 1;
	dict[pcc('P', 'R')] = dict[pcc('R', 'S')] = dict[pcc('S', 'P')] = 0;
}

int T, N, C[2];
char a, b;
int main() {
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		C[0] = C[1] = 0;
		while (N--) {
			scanf(" %c %c", &a, &b);
			if (a == b) continue;
			C[dict[pcc(a, b)]]++;
		}
		if (C[0] > C[1]) puts("Player 1");
		else if (C[0] < C[1]) puts("Player 2");
		else puts("TIE");
	}
	return 0;
}