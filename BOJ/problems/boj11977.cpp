#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, A[100];
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> A[i];

	sort(A, A+N);

	int max = 0, t = 1, cnt = 0, ptr = 0;
	for (int i=0; i<N; i++) {
		cnt = 1;
		
		for (ptr = i, t = 1; ptr > 0; t++) {
			int cur = A[ptr];
			if (A[ptr-1] + t < cur) break;
			while (ptr > 0 && A[ptr-1] + t >= cur) {
				cnt++; ptr--;
			}
		}

		for (ptr = i, t = 1; ptr < N-1; t++) {
			int cur = A[ptr];
			if (cur + t < A[ptr+1]) break;
			while (ptr < N-1 && cur + t >= A[ptr+1]) {
				cnt++; ptr++;
			}
		}

		max = max > cnt ? max : cnt;
	}

	cout << max << '\n';
	return 0;
}