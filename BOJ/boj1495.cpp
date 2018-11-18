#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int cache[100] = {0, };

int adjust(vector<int>& V, int S, int T, int M) {

	if (S < 0 || S > M) return -1;

	if (cache[S] )
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, S, M;
	vector<int> V(100);

	cin >> N >> S >> M;
	for (int i=0; i<S; i++) 
		cin >> V[i];

	memset(cache, -1, sizeof(cache));
	int max = adjust(V, S, 0, M);
	cout << max << '\n';

	return 0;
}