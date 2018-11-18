#include <iostream>
#include <string>
using namespace std;

int abs(int a) { return a > 0 ? a : -a; }
int min(int a, int b) { return a < b ? a : b; }

int main(int argc, char const *argv[])
{
	string src, dst;
	cin >> src >> dst;

	int len1 = src.length();
	int len2 = dst.length();

	int dp[1001][1001] = { 0, };
	for (int i=1; i<=len1; i++) {
		for (int j=1; j<=len2; j++) {
			if (src[i-1] == dst[j-1])
				dp[i][j] = dp[i-1][j-1];
			else 
				if (i == 1 || j == 1) {
					dp[i][j] = 
				}
				else {
					dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
				}
		}
	}

	for (int i=1; i<=len1; i++) {
		for (int j=1; j<=len2; j++) {
			cout << dp[i][j] << ' ';
		}
		cout <<'\n';
	}

	cout << dp[len1][len2] << '\n';
	return 0;
}