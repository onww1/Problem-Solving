#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str1, str2;
	char op;

	getline(cin, str1);
	cin >> op;
	getchar();
	getline(cin, str2);

	int len1 = str1.length();
	int len2 = str2.length();

	if(op == '+')
	{
		if(len1 == len2) 
		{
			str1[0] = '2';
			cout << str1 << '\n';
		}
		else
		{
			for(int i=((len1>len2)?len1:len2); i>0; i--)
			{
				if(i == len1 || i == len2) cout << 1;
				else cout << 0;
			}
			cout << '\n';
		}
	}
	else
	{
		cout << 1;
		for(int i=0; i< len1 + len2 - 2; i++)
			cout << 0;
		cout << '\n';
	}

	return 0;
}