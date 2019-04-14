#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, A;
vector <int> lis;
int main() {
	scanf("%d %d", &N, &A); lis.push_back(A);
	for (int i = 1; i < N; ++i) {
		scanf("%d", &A);
		if (A > lis.back()) lis.push_back(A);
		else *lower_bound(lis.begin(), lis.end(), A) = A;
	}
	printf("%lu\n", lis.size());
	return 0;
}