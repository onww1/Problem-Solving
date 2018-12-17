#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int sum = 0, N;
	while (cin >> N) sum += N;
	cout << sum << '\n';
	return 0;
}