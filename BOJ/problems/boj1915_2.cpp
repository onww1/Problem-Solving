#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>

using namespace std;
#define MAX 987654321


char temp;
int n, m, idx;
int A[1001][1001];
int dp[1001][1001];

int maxF(int a, int b) {
	if (a > b) return a;
	else return b;
}

int mini(int a, int b, int c) {
	if (a < b) return (a < c) ? a : c;
	else return (b < c) ? b : c;

}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &A[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] == 1) dp[i][j] = mini(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
			else dp[i][j] = 0;
		}
	}


	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			//printf("%d ", dp[i][j]);
			if (max < dp[i][j]) max = dp[i][j];
		}
		//printf("\n");
	}


	// print result
	printf("%d\n", max*max);


	return 0;
}