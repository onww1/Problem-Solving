#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 100, PMAX = 1e6;
int A[MAX], n, ans_val = 1, ans_task;
bool noPrime[PMAX + 1];
vector <int> prime;

int _pow(int base, int exp) {
	int ret = 1;
	while (exp) {
		if (exp % 2) ret *= base;
		base *= base;
		exp /= 2;
	}
	return ret;
}

int main(int argc, char *argv[]) {
	
	for (int i = 2; i <= PMAX; ++i) {
		if (!noPrime[i]) {
			prime.push_back(i);
			for (ll j = (ll)i * i; j <= PMAX; j += i) noPrime[j] = true;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", A + i);
	for (int i = 0; i < prime.size(); ++i) {
		int avg = 0, cnt[MAX] = { 0 };
		for (int j = 0; j < n; ++j) {
			while (A[j] % prime[i] == 0) {
				avg++; cnt[j]++;
				A[j] /= prime[i];
			}
		}
		avg /= n;
		int task = 0;
		for (int j = 0; j < n; ++j) if (cnt[j] < avg) task += (avg - cnt[j]);
		
		if (avg) {
			ans_val *= _pow(prime[i], avg); 
			ans_task += task;
		}
	}

	return !printf("%d %d\n", ans_val, ans_task);
}

