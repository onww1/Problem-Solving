#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int hour, minute, c_min;
	cin >> hour >> minute >> c_min;

	minute += c_min;
	hour = (hour + minute/60) % 24;
	minute %= 60;

	cout << hour << ' ' << minute << '\n';

	return 0;
}