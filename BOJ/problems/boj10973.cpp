#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	for (int i=0; i<N; ++i) cin >> A[i];

	int i, len = A.size();
	for (i=len-2; i>=0; i--) {
		if (A[i] > A[i+1]) {
			vector<int> tmp(A.begin() + i, A.end());
	
			int t_len = tmp.size();
			for (int j=0; j<t_len-1; ++j) {
				if (tmp[j] > tmp[j+1]) {
					swap(tmp[j], tmp[j+1]);
					if (j == t_len-2) {
						A[i] = tmp[j];
					}
				}
				else {
					A[i] = tmp[j-1];
					break;
				}
			}

			int offset = 0;
			for (int j=t_len-1; j>=0; j--) {
				if (tmp[j] != A[i]) {
					A[i+t_len-j-offset] = tmp[j];
				}
				else offset = 1;
			}
			break;
		}
	}

	if (i < 0) {
		cout << -1 << '\n';
	}
	else {
		for (auto &it : A)
			cout << it << ' ';
		cout << '\n';
	}

	return 0;
}