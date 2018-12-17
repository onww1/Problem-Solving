#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int N) {
	if (parent[N] < 0) return N;
	return parent[N] = find(parent[N]);
}

void merge(int N, int M) {
	int a = find(N);
	int b = find(M);
	if (a == b) return;
	parent[b] = a;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, c, a, b;
	cin >> N >> M;
	parent.resize(N+1, -1);
	for (int i=0; i<M; ++i) {
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else {
			merge(a, b);
		}
	}
	return 0;
}