#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string input[5];
	int len[5];

	for(int i=0; i<5; i++)
	{
		getline(cin, input[i]);
		len[i] = input[i].length();
	}

	for(int i=0; i<15; i++)
	{
		for(int j=0; j<5; j++)
		{
			if(len[j] > i) cout << input[j][i];
		}
	}
	cout << '\n';
	
	return 0;
}