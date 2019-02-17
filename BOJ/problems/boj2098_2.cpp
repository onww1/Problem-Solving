/*
 *  BOJ 2098. 외판원 순회
 * 
 *  시간 복잡도 : O(N^2 * 2^N)
 *  공간 복잡도 : O(N * 2^N)
 * 
 *  너무 웰논인 문제라서 풀긴 풀었는데,, 시간 복잡도 설명이 안되네요 ㅋㅋ 
 *  N^2이 어떻게 나오는지는 같이 생각해봐야 할 것 같습니다.
 * 
 *  비트마스킹 기법을 사용했습니다.
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int MAX = 16;
const int INF = 0x7f7f7f7f;
int dist[MAX][MAX], dp[MAX][1 << MAX], n;

int TSP(int cur, int visited) {
	if (visited == (1 << n) - 1) {
		if (dist[cur][0] == 0) return INF;
		return dist[cur][0];
	}

	int &ret = dp[cur][visited];
	if (ret != -1) return ret;
	ret = INF;

	for (int next = 1; next < n; ++next) {
		if (dist[cur][next] > 0 && !(visited & (1 << next))) 
			ret = min(ret, dist[cur][next] + TSP(next, visited | (1 << next)));
	}
	return ret;
}

int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d", &dist[i][j]);
	memset(dp, -1, sizeof(dp));
	return !printf("%d\n", TSP(0, 1));
}