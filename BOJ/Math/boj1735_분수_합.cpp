#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }
int _lcm(int a, int b) { return a / _gcd(a, b) * b; }

int main(int argc, char *argv[]) {
	int an, ad, bn, bd;
	scanf("%d %d %d %d", &an, &ad, &bn, &bd);
	int numerator = an * bd + bn * ad;
	int denominator = ad * bd;
	int GCD = _gcd(numerator, denominator);
	return !printf("%d %d\n", numerator / GCD, denominator / GCD);
}