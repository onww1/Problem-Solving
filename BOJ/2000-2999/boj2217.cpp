#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> rope(N);
	for (int i=0; i<N; ++i) cin >> rope[i];

	sort(rope.begin(), rope.end());
	
	int min = rope[N-1], max = -1;
	for (int i=N-1; i>=0; i--) {
		min = min > rope[i] ? rope[i] : min;
		max = max < min * (N-i) ? min * (N-i) : max;
	}

	cout << max << '\n';

	return 0;
}