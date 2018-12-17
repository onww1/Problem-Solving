#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, in;
	cin >> N;

	vector<int> line;
	for (int i=1; i<=N; ++i) {
		cin >> in;
		if (!in) line.push_back(i);
		else line.insert(line.end() - in, i);
	}

	for (auto &it : line)
		cout << it << ' ';
	cout << '\n';
	return 0;
}