#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(int argc, char const *argv[])
{
	ull N;
	cin >> N;
	
	ull left = 0ULL, right = (1ULL << 32ULL), mid;
	while (left + 1 < right) {
		mid = (left + right) / 2ULL;
		ull square = mid * mid;
		if (square == N) break;
		else if (square < N) {
			left = mid;
		}
		else if (square > N) {
			right = mid;
		}
	}
	
	if (N == 0) cout << 0 << '\n';
	else if (mid * mid >= N) cout << mid << '\n';
	else if (mid * mid < N) cout << (mid + 1ULL) << '\n';

	return 0;
}