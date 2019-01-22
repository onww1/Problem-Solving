#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
using namespace std;
int dp[1050][1050], s, i, j;

int solve(int now, int clip) {
	if (now > 1020 || now < 1 || clip > s) return INF;
	if (now == s) return 0;
	int &ret = dp[now][clip];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, solve(now, now) + 1);
	ret = min(ret, solve(now + clip, clip) + 1);
	ret = min(ret, solve(now - 1, clip) + 1);
	return ret;
}

int main(int argc, char *argv[]) {	
	scanf("%d", &s);
	memset(dp, -1, sizeof(dp));
	return !printf("%d\n", solve(1, 0));
}