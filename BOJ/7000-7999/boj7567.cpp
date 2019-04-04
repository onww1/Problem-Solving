#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	getline(cin, str);
	int len = str.length();
	int sum = 10;
	char prev = str[0];

	for(int i=1; i<len; i++)
	{
		if(prev == str[i]) sum += 5;
		else
		{
			prev = str[i];
			sum += 10;
		}
	}

	cout << sum << '\n';

	return 0;
}