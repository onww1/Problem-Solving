#include <iostream>
using namespace std;

struct person
{
	int weight;
	int height;
};

int compare(person p1, person p2)
{
	if(p1.weight > p2.weight && p1.height > p2.height)
		return -1;
	else if(p1.weight < p2.weight && p1.height < p2.height)
		return 1;
	else return 0;
}

int main(int argc, char const *argv[])
{
	int n, rank[50];
	person arr[50];

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i].weight >> arr[i].height;
		rank[i] = 1;
	}

	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			int k = compare(arr[i], arr[j]);
			if(k > 0) rank[i]++;
			else if(k < 0) rank[j]++;
		}
	}

	cout << rank[0];
	for(int i=1; i<n; i++)
		cout << " " << rank[i];
	cout << '\n';

	return 0;
}