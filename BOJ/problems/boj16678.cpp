#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, in, max = -1;
	bool arr[100001] = { false, };
	vector<int> cavity;
	vector<int> redundant;

	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> in;
		if (arr[in]) redundant.push_back(in);
		arr[in] = true;
		max = in > max ? in : max;
	}

	sort(redundant.begin(), redundant.end());

	for (int i=1; i<max; ++i) {
		if (!arr[i]) cavity.push_back(i);
	}

	ll sum = 0;
	int c_len = cavity.size();
	int r_len = redundant.size();
	int r_idx = 0;

	for (int i=0; i<c_len; ++i) {
		int target = cavity[i];
		while (r_idx < r_len && redundant[r_idx] < target) r_idx++;
		if (r_idx < r_len) sum += (ll)(redundant[r_idx++] - target);
		else {
			if (target > max) break;
			sum += (ll)(max - target);
			while (!arr[--max]);
		}
	}

	cout << sum << '\n';

	return 0;
}



