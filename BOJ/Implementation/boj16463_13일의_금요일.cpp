#include <iostream>
using namespace std;

bool isReap(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) return true;
	else return false;
}

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	int rdays[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

	int year = 2019;
	int curDays = 4;
	int cnt = 0;
	int thisYearDays = 365;
	bool reap = false;

	while (year <= N) {
		if (reap) {
			for (int i=1; i<=12; i++) {
				if (curDays < rdays[i]) {
					if (curDays - rdays[i-1] == 13) cnt++;
					break;
				}
			}
		}
		else {
			for (int i=1; i<=12; i++) {
				if (curDays < days[i]) {
					if (curDays - days[i-1] == 13) cnt++;
					break;
				}
			}
		}

		curDays += 7;
		if (curDays > thisYearDays) {
			curDays -= thisYearDays;
			year++;
			reap = isReap(year);
			thisYearDays = reap?366:365;
		}
	}

	cout << cnt << '\n';

	return 0;
}