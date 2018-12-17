#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int R, C, Q;
	cin >> R >> C >> Q;

	vector< vector<int> > vec(R);
	for (int i=0; i<R; i++) {
		vec[i].resize(C);
		cin >> vec[i][0];
		for (int j=1; j<C; j++) {
			cin >> vec[i][j];
			vec[i][j] += vec[i][j-1];
		}
	}
	
	int r1, c1, r2, c2;
	for (int i=0; i<Q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		int sum = 0;
		for (int i=r1-1; i<r2; i++) {
			if (c1 == 1) sum += vec[i][c2-1];
			else sum += (vec[i][c2-1] - vec[i][c1-2]);
		}
		cout << (sum / ((r2 - r1 + 1) * (c2 - c1 + 1))) << '\n';
	}
	return 0;
}