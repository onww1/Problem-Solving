#include <iostream>
using namespace std;

struct bat
{
	int first;
	int second;
	int third;
};

int main(int argc, char const *argv[])
{
	int n;
	bat b[200];
	int cnt[101][3] = {0, };

	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> b[i].first >> b[i].second >> b[i].third;
		cnt[b[i].first][0]++;
		cnt[b[i].second][1]++;
		cnt[b[i].third][2]++;
	}
	for(int i=0; i<n; i++)
	{
		int score = 0;
		if(cnt[b[i].first][0] == 1) score += b[i].first;
		if(cnt[b[i].second][1] == 1) score += b[i].second;
		if(cnt[b[i].third][2] == 1) score += b[i].third;
		cout << score << '\n'; 
	}
	return 0;
}