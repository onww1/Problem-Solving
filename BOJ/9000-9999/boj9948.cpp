#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int day;
	string month;

	while (true) {
		cin >> day >> month;
		if (day == 0 && month.compare("#") == 0) break;

		if (month.compare("August") == 0) {
			if (day < 4) cout << "Yes" << '\n';
			else if (day == 4) cout << "Happy birthday" << '\n';
			else cout << "No" << '\n';
		}
		else if (month.compare("September") == 0 ||
				 month.compare("October") == 0 ||
				 month.compare("November") == 0 ||
				 month.compare("December") == 0) {
			cout << "No" << '\n';
		}
		else {
			if (month.compare("February") == 0 && day == 29) 
				cout << "Unlucky" << '\n';
			else 
				cout << "Yes" << '\n';
		}
	}
	return 0;
}