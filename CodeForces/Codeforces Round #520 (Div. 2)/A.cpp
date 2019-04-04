#include <iostream>
using namespace std;

int main() {
	int N, A[100];
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	int max = 0, left = -1, right = -1;
	for (int i=0; i<N-1; i++) {
		if (A[i+1] == A[i] + 1) {
			if (left == -1) {
				left = i;
				right = i+1;
			}
			else {
				right++;
			}
			if (i == N-2) {
				if (A[left] == 1 || A[right] == 1000) {
					max = max > right - left ? max : right - left;
				}
				else max = max > right - left -1 ? max : right - left -1;
			}
		}
		else {
			if (A[left] == 1 || A[right] == 1000) {
				max = max > right - left ? max : right - left;
			}
			else max = max > right - left -1 ? max : right - left -1;

			left = right = -1;
		}
	}

	cout << max << '\n';

	return 0;
}