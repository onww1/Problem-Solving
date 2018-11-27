#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int tc, n;
	vector<int> vec;

	cin >> tc;
	while (tc--) {
		cin >> n;
		vec.clear();
		vec.resize(n);
		for (int i=0; i<n; i++) {
			cin >> vec[i];
		}
		sort(vec.begin(), vec.end());
		cout << (2 * (vec[n-1] - vec[0])) << '\n';
	}

	return 0;
}