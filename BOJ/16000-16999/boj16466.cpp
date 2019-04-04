#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	bool isOccupied[1000001] = {false, };
	int x;

	for (int i=0; i<N; i++) {
		cin >> x;
		isOccupied[x] = true;
	}

	for (int i=1; i<=1000000; i++) {
		if (!isOccupied[i]) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}