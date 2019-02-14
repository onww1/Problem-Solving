#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1000;
bool noPrime[MAX + 1];

int main(int argc, char *argv[]) {
	int k, n;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; ++i) {
		if (!noPrime[i]) {
			--k;
			if (!k) {
				printf("%d\n", i);
				break;
			}

			for (int j = i * i; j <= n; j += i) {
				if (!noPrime[j]) --k;
				noPrime[j] = true;
				if (!k) {
					printf("%d\n", j);
					break;
				}
			}
		}

		if (k <= 0) break;
	}
	return 0;
}