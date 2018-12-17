#include <iostream>
#include <string>
using namespace std;

int my_max(int a, int b) { return a > b ? a : b; }

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int dp[1001][1001] = {0, };
	int len1 = s1.length(), len2 = s2.length();

	for (int i=1; i<=len1; i++) {
		for (int j=1; j<=len2; j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = my_max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout << dp[len1][len2] << '\n';
	return 0;
}