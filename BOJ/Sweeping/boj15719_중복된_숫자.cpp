#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M = -1, in;
	cin >> N;

	vector<bool> visited(N);
	for (int i=0; i<N; i++) {
		cin >> in;
		if (visited[in]) {
			M = in;
		}
		else visited[in] = true;
	}

	cout << M << '\n';
	return 0;
}