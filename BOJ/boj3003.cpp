#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int correct[6] = {1, 1, 2, 2, 2, 8}, in;
	for (int i=0; i<6; i++) {
		cin >> in;
		cout << (correct[i] - in) << ' ';
	}
	cout << '\n';
	return 0;
}