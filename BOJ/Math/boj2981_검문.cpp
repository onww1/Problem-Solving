#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int _abs(int a) { return a < 0 ? -a : a; }
int _gcd(int a, int b) { return b ? _gcd(b, a % b) : a; }

const int MAX = 100;
int N, A[MAX];

int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	
	int GCD = _abs(A[1] - A[0]);
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			GCD = _gcd(GCD, _abs(A[j] - A[i]));
		}
	}
	
	vector <int> d;
	for (int i = 1; i * i <= GCD; ++i) {
		if (GCD % i == 0) {
			d.push_back(i);
			if (i * i != GCD) 
				d.push_back(GCD / i);
		}
	}
	
	sort(d.begin(), d.end());
	for (int i = 1; i < d.size(); ++i)
		printf("%d ", d[i]);
	puts("");
	return 0;
}