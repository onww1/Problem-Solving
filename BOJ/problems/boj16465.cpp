#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, L, x[100];
	cin >> N >> M >> L;
	for (int i=0; i<N; i++) {
		cin >> x[i];
	}

	int cnt = 0;
	int left = -1, right = 0, sum = x[0];
	bool isOK = false;
	while (right < N && left < right) {
		if (sum == L && (left == -1 || right == N-1)) {
			cnt++;
			if (left == -1) {
				left = right;
				right = right + 1;
				if (right == N) {
					isOK = true;
					break;
				}
				else sum = x[right];
			}
			else {
				isOK = true;
				break;
			}
		}
		else if (sum == 2 * L) {
			cnt += 2;
			left = right;
			right = right + 1;
			if (right == N) {
				isOK = true;
				break;
			}
			else sum = x[right];
		}
		else if (sum > 2 * L) {
			left++;
			sum -= x[left];
		}
		else if (sum < 2 * L) {
			right++;
			if (right == N) break;
			else sum += x[right];
		}
	}

	cout << (isOK?cnt:-1) << '\n';

	return 0;
}