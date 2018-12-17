#include <iostream>
#define MOD 1'000'000
using namespace std;

typedef unsigned long long ull;

struct matrix {
	ull m[2][2];
};

matrix multiply(matrix m1, matrix m2) {
	matrix res;
	res.m[0][0] = (m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0]) % MOD;
	res.m[0][1] = (m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1]) % MOD;
	res.m[1][0] = (m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0]) % MOD;
	res.m[1][1] = (m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1]) % MOD;
	return res;
}

matrix multi_power(matrix A, ull N) {
	if (N == 1) return A;

	matrix half = multi_power(A, N/2);
	matrix square = multiply(half, half);
	if (N%2) {
		matrix unit = {1, 1, 1, 0};
		square = multiply(square, unit);
	}
	return square;
}

int main(int argc, char const *argv[])
{
	ull N;
	cin >> N;

	matrix F1 = {1ULL, 1ULL, 1ULL, 0ULL};
	matrix res = multi_power(F1, N);

	cout << res.m[0][1] << '\n';

	return 0;
}