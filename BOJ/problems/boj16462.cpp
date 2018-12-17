#include <iostream>
#include <string>
using namespace std;

int parse(string score) {
	int ret = 0, len = score.length();
	if (len == 3) return 100;
	else if (len == 2) {
		if (score[0] == '0' || score[0] == '6')
			ret += 90;
		else ret += (score[0] - '0') * 10;

		if (score[1] == '0' || score[1] == '6')
			ret += 9;
		else ret += (score[1] - '0');
	}
	else if (len == 1) {
		if (score[0] == '0' || score[0] == '6')
			ret += 9;
		else ret += (score[0] - '0');
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, sum = 0;
	string score;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> score;
		sum += parse(score);
	} 

	cout << fixed;
	cout.precision(0);
	cout << ((double)sum / N) << '\n';
	return 0;
}