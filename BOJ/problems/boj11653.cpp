#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1) printf("%d\n", n);
	return 0;
}