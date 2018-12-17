#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool isOK = true;
	int N, A, last = 0;
	cin >> N;
	vector<int> stack;
	for (int i=1; isOK && i<=N; i++) {
		cin >> A;
		if (A == i - stack.size()) {
			last = A;
		}
		else {
			while (isOK && stack.size() && stack.back() < A) {
				int back = stack.back();
				stack.pop_back();

				if (back - 1 == last) {
					last = back;
				}
				else {
					isOK = false;
				}
			}
			if (A - 1 == last) {
				last = A;
			}
			else stack.push_back(A);
		}
	}

	if (isOK) cout << "Nice\n";
	else cout << "Sad\n";

	return 0;
}