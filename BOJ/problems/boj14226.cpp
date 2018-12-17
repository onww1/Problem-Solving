#include <iostream>
#include <cstring>
using namespace std;

int map[1001], S;

bool check(int pos) {
	if (pos < 0 || pos > 1000) return false;
	return true;
}

void solve(int pos, int clip) {
	if (check(pos + clip) && map[pos + clip] > map[pos] + 1) {
		map[pos + clip] = map[pos] + 1;
		solve(pos + clip, clip);
	}

	if (check(pos - 1) && map[pos - 1] > map[pos] + 1) {
		map[pos - 1] = map[pos] + 1;
		solve(pos - 1, clip);
	}

	clip = pos;
	if (check(pos + clip) && map[pos + clip] > map[pos] + 2) {
		map[pos + clip] = map[pos] + 2;
		solve(pos + clip, clip);
	}

	if (check(pos - 1) && map[pos - 1] > map[pos] + 2) {
		map[pos - 1] = map[pos] + 2;
		solve(pos - 1, clip);
	}
}

int main(int argc, char const *argv[])
{
	memset(map, 127, 1001 * sizeof(int));
	map[0] = 1; map[1] = 0;

	cin >> S;
	solve(1, 0);

	cout << map[S] << '\n';
	return 0;
}