#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int in, sum=0, arr[101] = {0, };
	int max = 0, max_idx = -1;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	for (int i=0; i<10; ++i) {
		cin >> in;
		sum += in;
		arr[in/10]++;
		if (arr[in/10] > max) {
			max = arr[in/10];
			max_idx = in;
		}
	}

	cout << (sum / 10) << '\n' << max_idx << '\n';
	return 0;
}