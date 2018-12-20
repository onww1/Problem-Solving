#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int X, Y, M;
	cin >> X >> Y >> M;

	vector<bool> vec(M+1, false);
	vec[0] = true;

	int max = 0;
	for (int i=0; i<=M; ++i) {
		if (vec[i]) {
			max = i;
			if (i + X <= M) vec[i + X] = true;
			if (i + Y <= M) vec[i + Y] = true;
		}
	}

	cout << max << '\n';

	return 0;
}