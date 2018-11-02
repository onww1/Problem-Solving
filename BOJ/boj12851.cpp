#include <iostream>
#include <cstdlib>
using namespace std;

int N, K, map[100001] = { 0, };
int min = 1e9, cnt = 0;

void dfs(int pos) {
	if (map[pos] > min)
}

int main() {
	cin >> N >> K;
	memset(map, -1, 100001);
	map[N] = 0;

	dfs(N);
	cout << map[K] << '\n';
	cout << cnt << '\n';
	return 0;
}