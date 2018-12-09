#include <iostream>
#include <vector>
using namespace std;

int N, K, tr, tc;
vector< vector<int> > vec;

void draw(int r, int c, int n) {
	int square = n * n;
	int i = r, j = c;
	for (; i<r+n-1; i++) {
		if (square == K) {
			tr = i;
			tc = j;
		}
		vec[i][j] = square--;
	}
	for (; j<c+n-1; j++) {
		if (square == K) {
			tr = i;
			tc = j;
		}
		vec[i][j] = square--;
	}
	for (; i>r; i--) {
		if (square == K) {
			tr = i;
			tc = j;
		}
		vec[i][j] = square--;
	}
	for (; j>c; j--) {
		if (square == K) {
			tr = i;
			tc = j;
		}
		vec[i][j] = square--;
	}
	if (n > 3) draw(r+1, c+1, n-2);
	else if (n == 3) {
		vec[r+1][c+1] = 1;
		if (K == 1) {
			tr = r + 1;
			tc = c + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	vec.resize(N+1, vector<int>(N+1));

	draw(1, 1, N);
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cout << vec[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << tr << ' ' << tc << '\n';

	return 0;
}