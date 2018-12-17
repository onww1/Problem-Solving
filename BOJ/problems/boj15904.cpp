#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	getline(cin, str);
	char ucpc[5] = "UCPC";

	int len = str.length();
	int k = 0;
	for(int i=0; i<len; i++)
	{
		if(str[i] == ucpc[k])
		{
			k++;
			if(k==4) break;
		}
	}

	if(k==4) cout << "I love UCPC" << '\n';
	else cout << "I hate UCPC" << '\n';
	return 0;
}