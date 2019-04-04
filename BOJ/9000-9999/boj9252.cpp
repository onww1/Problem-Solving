// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main() {
// 	string s1, s2;
// 	cin >> s1 >> s2;

// 	int dp[1001][1001] = {0, };
// 	int len1 = s1.length(), len2 = s2.length();

// 	for (int i=1; i<=len1; i++) {
// 		for (int j=1; j<=len2; j++) {
// 			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
// 			else dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
// 		}
// 	}

// 	int row = len1, col = len2;
// 	vector<char> lcs(dp[len1][len2]);
// 	while(dp[row][col]) {
// 		if (dp[row][col] > dp[row-1][col] && dp[row][col] > dp[row][col-1]) {
// 			lcs[dp[row-1][col-1]] = s1[row-1];
// 			row--; col--;
// 		}
// 		else {
// 			while(dp[row][col] == dp[row-1][col]) row--;
// 			while(dp[row][col] == dp[row][col-1]) col--;
// 		}
// 	}

// 	cout << dp[len1][len2] << '\n';
// 	for (int i=0; i<dp[len1][len2]; i++) {
// 		cout << lcs[i];
// 	}
// 	cout << '\n';

// 	return 0;
// }

/*
 *	BOJ 9252. LCS 2
 *
 *   
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005][1005];
char a[1005], b[1005], res[1005];
int main(int argc, char *argv[]) {
	int l1, l2, len, i, j;
	scanf("%s %s", a + 1, b + 1);
	l1 = strlen(a + 1);
	l2 = strlen(b + 1);
	for (i = 1; i <= l1; ++i) {
		for (j = 1; j <= l2; ++j) {
			if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	len = dp[l1][l2], res[len] = 0;
	i = l1, j = l2;
	while (len && i && j) {
		if (a[i] == b[j]) {
			res[--len] = a[i];
			--i; --j;
		} 
		else if (dp[i][j] == dp[i-1][j]) --i;
		else --j;
	}
	return !printf("%d\n%s\n", dp[l1][l2], res);
}