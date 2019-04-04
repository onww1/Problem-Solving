#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int INF = 0x7f7f7f7f;
int N, P, A[MAX][MAX], DP[1 << MAX];
char in[MAX + 1];

int solve(int visited, int cnt) {
	if (cnt >= P) return 0;

	int &ret = DP[visited];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < N; ++i) {
		if (visited & (1 << i)) continue;
		
		int mn = INF;
		for (int j = 0; j < N; ++j) 
			if (visited & (1 << j)) 
				mn = min(mn, A[j][i]);
	
		ret = min(ret, mn + solve(visited | (1 << i), cnt + 1));
	}
	
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) scanf("%d", &A[i][j]);
	scanf(" %s %d", in, &P);

	int state = 0, cnt = 0;
	for (int i = 0; in[i]; ++i)
		if (in[i] == 'Y') state |= (1 << i), cnt++;

	if (P && !cnt) return !printf("-1\n");
	if (P <= cnt) return !printf("0\n");

	memset(DP, -1, sizeof(DP));
	return !printf("%d\n", solve(state, cnt));
}