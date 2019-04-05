#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

bool noPrime[1000001];
vector <int> prime;

char in[101];
ll e[10], k, p, len;

int main(int argc, char *argv[]) {

	for (int i = 2; i <= 1000000; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (ll j = (ll)i * i; j <= 1000000; j += i) noPrime[j] = true;
		}
	}

	scanf(" %s %lld", in, &k);
	len = strlen(in);
	if (len == 101) return !printf("BAD 2\n");


	for (int i = 0; i < prime.size() && prime[i] < k; ++i) {
		int remain = 0;
		for (int j = 0; in[j]; ++j) remain = (remain * 10 + in[j] - '0') % prime[i];
		if (remain == 0) return !printf("BAD %d\n", prime[i]);
	}

	return !printf("GOOD\n");
}