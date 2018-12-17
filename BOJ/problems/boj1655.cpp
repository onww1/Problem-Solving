#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec;
	int x;

	for (int i=1; i<=N; i++) {
		cin >> x;
		auto it = lower_bound(vec.begin(), vec.end(), x);
		vec.insert(it, x);
		cout << vec[(i-1)/2] << '\n';
	}
	return 0;
}