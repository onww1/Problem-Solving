#include <iostream>
using namespace std;

int a, b, max_val=0, sum=0;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i=0; i<10; i++) {
		cin >> a >> b;

		sum += (b-a);
		max_val = ( sum > max_val ? sum : max_val );
	}

	cout << max_val << '\n';
	return 0;
}