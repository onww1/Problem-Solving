#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, in, A[201] = {0,};
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> in;
		A[in + 100]++;
	}
	cin >> in;
	cout << A[in + 100] << '\n';

	return 0;
}