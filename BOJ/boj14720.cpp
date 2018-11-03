#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int A, cur = 0, cnt = 0;
	for (int i=0; i<N; i++) {
		cin >> A;
		if (A == cur) {
			cnt++;
			cur = (cur + 1)%3;
		}
	}

	cout << cnt << '\n';
	return 0;
}