#include <cstdio>
#include <cstring>
#define MOD 1000000
using namespace std;

int main(int argc, char const *argv[])
{
	char cipher[5001];
	scanf("%s", cipher);

	int len = strlen(cipher);
	int dp[5000] = {0, };
	bool isValid = true;

	if (cipher[0] == '0') {
		isValid = false;
	}
	dp[0] = 1;

	for (int i=1; isValid && i<len; ++i) {
		if (cipher[i] == '0') {
			if (cipher[i-1] == '1' || cipher[i-1] == '2') {
				if (i == 1) dp[i] = 1;
				else dp[i] = dp[i-2];
			}
			else isValid = false;
		}
		else if ('1' <= cipher[i] && cipher[i] <= '6') {
			if (cipher[i-1] == '1' || cipher[i-1] == '2') {
				if (i == 1) dp[i] = 2;
				else dp[i] = (dp[i-2] + dp[i-1]) % MOD;
			}
			else dp[i] = dp[i-1];
		}
		else {
			if (cipher[i-1] == '1') {
				if (i == 1) dp[i] = 2;
				else dp[i] = (dp[i-2] + dp[i-1]) % MOD;
			}
			else dp[i] = dp[i-1];
		}
	}

	printf("%d\n", isValid?dp[len-1]:0);

	return 0;
}