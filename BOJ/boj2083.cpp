#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string name;
	int age, weight;

	while (true) {
		cin >> name >> age >> weight;
		if (!age && !weight) break;

		if (age > 17 || weight >= 80)
			cout << name << ' ' << "Senior" << '\n';
		else
			cout << name << ' ' << "Junior" << '\n';
	}
	return 0;
}