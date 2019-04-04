#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, sum = 0, res, point = 1;
	bool isConsecutive = false;

	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> res;
		if (res) {
			if (isConsecutive) point++;
			sum += point;
			isConsecutive = true;
		}
		else {
			isConsecutive = false;
			point = 1;
		}
	}

	cout << sum << '\n';
	return 0;
}