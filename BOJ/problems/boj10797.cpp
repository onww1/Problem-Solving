#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int day, car, cnt = 0;
	cin >> day;
	for(int i=0; i<5; i++)
	{
		cin >> car;
		if(car == day) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}