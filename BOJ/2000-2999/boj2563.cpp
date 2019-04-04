#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct paper
{
	int left;
	int bottom;
};

bool compareLeft(const paper& a, const paper& b)
{
	return a.left < b.left;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	paper p[100];

	for(int i=0; i<n; i++)
	{
		cin >> p[i].left >> p[i].bottom;
	}

	// sort(p, p+n, compareLeft);

	// int minLeft = 0;
	// int sum = 0;
	// for(int i=p[0].left; i<100; i++)
	// {
	// 	while(i - p[minLeft].left >= 10) minLeft++;
	// 	vector<int> v;
	// 	for(int j=minLeft; true; j++)
	// 	{
	// 		if(p[j].left - i >= 10) break;
	// 		v.push_back(p[j].bottom);
	// 	}
	// 	sort(v.begin(), v.end());
		
	// 	int len = v.size();
	// 	for(int j=0; j<len-1; j++)
	// 	{
	// 		if(v[j+1] - v[j] >= 10) sum += 10;
	// 		else sum += (v[j+1] - v[j]);
	// 	}
	// 	sum += 10;
	// }

	int arr[100][100] = {0, };
	for(int i=0; i<n; i++)
	{
		for(int j=p[i].left - 1; j < p[i].left + 9; j++)
		{
			for(int k=p[i].bottom - 1; k < p[i].bottom + 9; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	int sum = 0;
	for(int i=0; i<100; i++)
	{
		for(int j=0; j<100; j++)
		{
			sum += arr[i][j];
		}
	}

	cout << sum << '\n';

	return 0;
}