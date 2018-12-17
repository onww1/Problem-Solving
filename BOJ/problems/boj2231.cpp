#include <iostream>
using namespace std;

int partialSum(int N) {
	int sum = N;
	while (N > 0) {
		sum += (N%10);
		N/=10;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	bool isFound = false;
	for (int i=(N-70 > 0 ? N-70 : 1); i<N; ++i) {
		if (partialSum(i) == N) {
			cout << i << '\n';
			isFound = true;
			break;
		}
	}
	if (!isFound) cout << 0 << '\n';

	return 0;
}