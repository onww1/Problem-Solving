#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector< vector<int> >& vec, string& src, string& dst, int offset) {
	if (src.length() == 0) {
		return;
	}

	// left
	int rot = (dst[0] - src[0] - offset + 20) % 10;
	offset = (offset + rot) % 10;

	// right
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	string src, dst;
	cin >> src >> dst;

	vector< vector<int> > vec(N);
	for (int i=0; i<N; i++) 
		vec[i].resize(10);

	solve(vec, src, dst, 0, 0);

	return 0;
}