#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class FenwickTree2D {
public:
	int size;
	vector< vector<ll> > data;

	FenwickTree2D(int _N) {
		size = _N;
		data = vector< vector<ll> >(size + 1, vector<ll>(size + 1));
	}

	void update(int x, int y, int val) {
		ll diff = val - sum(x, y, x, y);
		int yy;
		while (x <= size) {
			yy = y;
			while (yy <= size) {
				data[x][yy] += diff;
				yy += (yy & -yy);
			}
			x += (x & -x);
		}
	}

	ll sum(int x, int y) {
		ll ret = 0;
		int yy;
		while (x > 0) {
			yy = y;
			while (yy > 0) {
				ret += data[x][yy];
				yy -= (yy & -yy);
			}
			x -= (x & -x);
		}
		return ret;
	}

	inline ll sum(int x1, int y1, int x2, int y2) {
		return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
	}
};

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, w, x1, y1, x2, y2, c;
	cin >> N >> M;

	FenwickTree2D tree(N);

	for (int i=1; i<=N; ++i) {
		for (int j=1; j<=N; ++j) {
			cin >> c;
			tree.update(i, j, c);
		}
	}

	for (int i=0; i<M; ++i) {
		cin >> w;
		if (!w) {
			cin >> x1 >> y1 >> c;
			tree.update(x1, y1, c);
		} else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << tree.sum(x1, y1, x2, y2) << '\n';
		}
	}

	return 0;
}