#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int phi[1001], noPrime[1001];
int main(int argc, char *argv[]) {
	for (int i = 2; i <= 1000; ++i) phi[i] = i;
	for (int i = 2; i <= 1000; ++i) {
		if (!noPrime[i]) {
			for (int j = 1; i * j <= 1000; ++j) {
				phi[i * j] = phi[i * j] / i * (i - 1);
				noPrime[i * j] = 1;
			}
		}
		phi[i] += phi[i - 1];
	}

	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", phi[n] * 2 + 3);
	}
	return 0;
}