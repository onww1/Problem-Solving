#include <iostream>
#include <vector>
using namespace std;

void solve(vector< vector<char> >& map, int T, int S, int& cnt) {
	if (T == 7) {

	}
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	vector< vector<char> > map(5);
	for (int i=0; i<5; i++) {
		map.resize(5);
		for (int j=0; j<5; j++) 
			cin >> map[i][j];
	}

	int cnt = 0;
	solve(map, 0, 0, cnt);
	cout << cnt << '\n';
	return 0;
}