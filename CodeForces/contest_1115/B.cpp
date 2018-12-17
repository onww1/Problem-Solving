#include <iostream>
#include <vector>
using namespace std;

struct item {
	int num;
	int cnt;
};

int getPower(int a) {
	int mask = 1;
	for (int i=0; i<31; i++) {
		if ( a / (mask << i) == 0 || ( a / (mask << i) == 1 && a % (mask << i) == 0 ) )
			return i;
	}
	return 31;
}

int main() {
	int N;
	cin >> N;

	vector<item> vec;
	int num = 2, cnt = 0;
	while (N % num == 0) {
		cnt++;
		N /= num;
	}
	if (cnt > 0) vec.push_back({num, cnt});

	num = 3, cnt = 0;
	while (N > 1) {
		while (N % num == 0) {
			cnt++;
			N /= num;
		}
		if (cnt > 0) vec.push_back({num, cnt});
		num += 2; cnt = 0;
	}

	int min = 1, max = 0, tmp = 0;
	bool isSatisfied = true;
	for (int i=0; i<vec.size(); i++) {
		min *= vec[i].num;
		tmp = getPower(vec[i].cnt);
		if (isSatisfied) isSatisfied = (vec[i].cnt == (1 << tmp));
		if (max && max != tmp) isSatisfied = false; 
		max = max > tmp ? max : tmp;
	}
	cout << min << ' ' << (isSatisfied ? max : max + 1) << '\n';

	return 0;
}