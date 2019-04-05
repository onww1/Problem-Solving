#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, A[10];
	cin >> T;
	while (T--) {
		for (int i=0; i<10; ++i) cin >> A[i];
		sort(A, A+10);
		cout << A[7] << '\n';
	}
	return 0;
}