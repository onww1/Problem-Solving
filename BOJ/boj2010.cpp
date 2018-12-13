#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long sum = 0LL, in;
	int N;
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> in;
		sum += in;
	}
	cout << (sum - (long long)(N-1)) << '\n';
	return 0;
}