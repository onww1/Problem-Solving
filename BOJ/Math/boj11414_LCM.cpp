#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll A, B;

int main(int argc, char *argv[]) {
	scanf("%lld %lld", &A, &B);
	if (A == B) return !printf("1\n");
	if (A > B) swap(A, B);
	
	vector <ll> d;
	ll diff = B - A;
	for (int i = 1; i * i <= diff; ++i) {
		if (diff % i == 0) {
			d.push_back(i);
			if (i * i != diff) 
				d.push_back(diff / i);
		}
	}
	
	sort(d.begin(), d.end());
	
	ll mn = 0x7fffffffffffffff, k = 0;
	for (ll dd : d) {
		if (A % dd == B % dd) {
			ll offset = dd - A % dd;
			ll LCM = (A + offset) * (B + offset) / dd;
			if (LCM < mn) {
				mn = LCM;
				k = offset;	
			}
		}	
	}
	
	printf("%lld\n", k);
	return 0;
}