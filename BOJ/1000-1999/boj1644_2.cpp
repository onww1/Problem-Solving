#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MAX = 4e6;
bool noPrime[MAX + 1];
vector <int> prime;

int main(int argc, char *argv[]) {
	
	for (int i = 2; i <= MAX; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (ll j = (ll)i * i; j <= MAX; j += i) noPrime[j] = true;
		}
	}

	int cnt = 0, l = 0, r = 1, sum = 2, n;
	scanf("%d", &n);
	while (l < r && r <= prime.size()) {
		if (sum == n) {
			++cnt;
			sum -= prime[l++];
			sum += prime[r++];
		}
		else if (sum > n) sum -= prime[l++];
		else sum += prime[r++];
	}
	
	return !printf("%d\n", cnt);
}