#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long arr[5] = {0LL, }, in, max = 0;
	int max_idx = 0;

	for (int i=0; i<5; ++i) {
		for (int j=0; j<4; ++j) {
			cin >> in;
			arr[i] += in;
		}
		if (arr[i] > max) {
			max = arr[i];
			max_idx = i+1;
		}
	}

	cout << max_idx << ' ' << max << '\n';

	return 0;
}