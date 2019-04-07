#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char map[100][100] = { 0, };
	int N, R, C;

	cin >> N >> R >> C;
	int mode = (R + C) % 2;
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			if ( (i + j) % 2 == mode )
				cout << 'v';
			else 
				cout << '.';
		}
		cout << '\n';
	}

	return 0;
}