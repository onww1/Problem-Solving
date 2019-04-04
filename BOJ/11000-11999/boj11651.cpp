#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int x, y;
};

bool cmp(point& a, point& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<point> vec(N);
	int x, y;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		vec[i] = {x, y};
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i=0; i<N; i++) {
		cout << vec[i].x << ' ' << vec[i].y << '\n';
	}
	return 0;
}