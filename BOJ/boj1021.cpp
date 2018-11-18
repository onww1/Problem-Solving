#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int a) { return a > 0 ? a : -a; }

int min(int a, int b) { return a < b ? a : b; }

int find_idx(vector<int>& list, int dst) {
	int left = -1, right = list.size();
	while ( left < right ) {
		int mid = ( left + right ) / 2;
		if ( list[mid] == dst ) return mid;
		else if ( list[mid] < dst ) left = mid;
		else right = mid;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;

	vector<int> list(N);
	for (int i=1; i<=N; i++) list[i-1] = i;

	int sum = 0;
	int in, p = 0;
	for (int i=0; i<M; i++) {
		cin >> in;
		int idx = find_idx(list, in);
		int len = list.size();
		sum += min(abs(idx - p), len - abs(idx - p));
		p = idx;
		list.erase(list.begin() + idx);
	}

	cout << sum << '\n';

	return 0;
}