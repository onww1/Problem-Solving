#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> lis;
	int next;

	for (int i=0; i<n; i++) {
		cin >> next;
		auto it = lower_bound(lis.begin(), lis.end(), next);
		if (it == lis.end()) lis.push_back(next);
		else *it = next;
	}

	cout << lis.size() << '\n';
	return 0;
}