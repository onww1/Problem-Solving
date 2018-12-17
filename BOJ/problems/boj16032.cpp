#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, arr[10000];

	while (true) {
		cin >> N;
		if (!N) break;

		int sum = 0;
		for (int i=0; i<N; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		int cnt = 0;
		for (int i=0; i<N; i++) {
			if (N * arr[i] <= sum) cnt++;
		}

		cout << cnt << '\n';
	}
	return 0;
}