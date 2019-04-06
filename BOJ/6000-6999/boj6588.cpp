#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
bool noPrime[MAX + 1];
vector <int> prime;

int main(int argc, char *argv[]) {
	
	for (int i = 2; i <= MAX; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (ll j = (ll)i * i; j <= MAX; j += i) noPrime[j] = true;
		}
	}

	int n;
	while (true) {
		scanf("%d", &n);
		if (!n) break;

		for (int j = 1; j < prime.size(); ++j) {
			if (2 * prime[j] <= n) {
				auto it = lower_bound(prime.begin(), prime.end(), n - prime[j]);
				if (it != prime.end() && *it == n - prime[j]) {
					printf("%d = %d + %d\n", n, prime[j], *it);
					break;
				}
			}
			else {
				puts("Goldbach's conjecture is wrong.");
				break;
			}
		}
	}
	
	return 0;
}