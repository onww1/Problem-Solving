#include <cstdio>
using namespace std;

int main() {
	long long R, r;
	scanf("%lld %lld", &R, &r);

	long long result = R * R - 2 * R * r;
	printf("%lld\n", result);
	return 0;
}