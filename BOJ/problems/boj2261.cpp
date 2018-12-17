#include <iostream>
#include <vector>
using namespace std;

struct point {
	int r, c;
};

int distance(point& a, point& b) {
	return (a.r - b.r) * (a.r - b.r) + (a.c - b.c) * (a.c - b.c);
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, r, c;
	cin >> N;

	vector<point> p(N);
	for (int i=0; i<N; i++) {
		cin >> r >> c;
		p[i] = {r, c};
	}

	int min = 987654321;
	for (int i=0; i<N-1; i++) {
		for (int j=i+1; j<N; j++) {
			int d = distance(p[i], p[j]);
			min = d < min ? d : min;
		}
	}

	cout << min << '\n';

	return 0;
}