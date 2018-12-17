#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string str;
	cin >> str;

	int len = str.length();
	vector<string> suffix(len);

	for (int i=0; i<len; ++i) 
		suffix[i] = str.substr(i);

	sort(suffix.begin(), suffix.end());
	
	for (int i=0; i<len; ++i) 
		cout << suffix[i] << '\n';

	return 0;
}