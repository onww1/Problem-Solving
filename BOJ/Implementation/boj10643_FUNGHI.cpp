#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A[8], max = -1, sum = 0;
	for (int i=0; i<8; ++i) cin >> A[i];
	for (int i=0; i<8; ++i) {
		sum = A[i] + A[(i+1)%8] + A[(i+2)%8] + A[(i+3)%8];
		max = sum > max ? sum : max;
	}
	cout << max << '\n';
	return 0;
}