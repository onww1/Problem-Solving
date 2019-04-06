#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, sum;
	vector<int> factor;
	cin >> N;
	while (~N) {
		sum = 1;
		factor.clear();
		factor.push_back(1);
		for (int i=2; i<=N/2; ++i) {
			if (N % i == 0) {
				sum += i;
				factor.push_back(i);
			}
		}

		if (sum == N) {
			cout << N << " = " << 1;
			int len = factor.size();
			for (int i=1; i<len; ++i) {
				cout << " + " << factor[i];
			}
			cout << '\n';
		}
		else {
			cout << N << " is NOT perfect." << '\n';
		}

		cin >> N;
	}
	return 0;
}