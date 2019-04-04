#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N, K;
	cin >> N >> K;

	bool isFound = false;
	for (int i=1; i <= N; ++i) {
		if (N % i == 0) {
			K--;
			if (!K) {
				cout << i << '\n';
				isFound = true;
				break;
			}
		}
	}

	if (!isFound) cout << 0 << '\n';
	return 0;
}