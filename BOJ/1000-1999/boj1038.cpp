#include <iostream>
using namespace std;

typedef long long ll;

ll res;
int N, combination[11] = {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1};
ll num[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
bool visited[10] = {false, };

void solve(int len, int prev, int T, bool& isOK) {
	if (T == len) {
		combination[len]--;
		if (combination[len] == N) {
			for (int i = 0; i < 10; ++i) {
				if (visited[i]) {
					res = res * 10 + num[i];
				}
			}
			isOK = true;
		}
		return;
	}

	for (int i = prev + 1; !isOK && i < 10; ++i) {
		visited[i] = true;
		solve(len, i, T+1, isOK);
		visited[i] = false;
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	if (!N) cout << 0 << '\n';
	else {
		int len = 1;
		while (len <= 10 && N >= combination[len]) N -= combination[len++];
		if (len == 11) cout << -1 << '\n';
		else {
			bool isOK = false;
			solve(len, -1, 0, isOK);
			cout << res << '\n';
		}
	}
	return 0;
}