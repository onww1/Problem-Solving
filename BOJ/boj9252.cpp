#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int dp[1001][1001] = {0, };
	int len1 = s1.length(), len2 = s2.length();

	for (int i=1; i<=len1; i++) {
		for (int j=1; j<=len2; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
		}
	}

	int row = len1, col = len2;
	vector<char> lcs(dp[len1][len2]);
	while(dp[row][col]) {
		if (dp[row][col] > dp[row-1][col] && dp[row][col] > dp[row][col-1]) {
			lcs[dp[row-1][col-1]] = s1[row-1];
			row--; col--;
		}
		else {
			while(dp[row][col] == dp[row-1][col]) row--;
			while(dp[row][col] == dp[row][col-1]) col--;
		}
	}

	cout << dp[len1][len2] << '\n';
	for (int i=0; i<dp[len1][len2]; i++) {
		cout << lcs[i];
	}
	cout << '\n';

	return 0;
}