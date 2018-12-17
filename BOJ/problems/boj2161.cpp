#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	queue<int> q;
	for (int i=1; i<=N; ++i) q.push(i);

	bool mode = true;
	while (!q.empty()) {
		int item = q.front();
		q.pop();

		if (mode) cout << item << ' ';
		else q.push(item);
		mode = !mode;
	}
	cout << '\n';

	return 0;
}