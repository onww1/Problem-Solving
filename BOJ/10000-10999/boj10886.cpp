#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, in, result[2] = {0, 0};
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> in;
		result[in]++;
	}
	if(result[0] > result[1])
	{
		cout << "Junhee is not cute!" << '\n';
	}
	else
	{
		cout << "Junhee is cute!" << '\n';
	}
	return 0;
}