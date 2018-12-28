#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
	bool noPrime[1000001] = {true, true, };
	ll min, max;
	scanf("%lld %lld", &min, &max);

	for (int i=2; i*i <= 1000000; ++i) {
		if (!noPrime[i]) {
			for (int j=i; i*j <= 1000000; ++j)
				noPrime[i*j] = true;
		}
	}

	vector<int> prime;
	for (int i=2; i<1000000; ++i) 
		if (!noPrime[i]) prime.push_back(i);

	ll cnt = max - min + 1;
	ll len = max - min + 1;
	bool isOK;
	for (ll i = 0LL; i < len; ++i) {
		isOK = true;
		for (int j=0; (ll)prime[j] * prime[j] <= min + i; ++j) {
			if ((min + i) % (prime[j] * prime[j]) == 0) {
				isOK = false;
				break;
			}
		}
		if (!isOK) --cnt;
	}
	printf("%lld\n", cnt);
	return 0;
}