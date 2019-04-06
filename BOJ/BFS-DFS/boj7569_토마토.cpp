#include <cstdio>
#include <queue>
using namespace std;

struct point
{
	int x, y, z;
	int day;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;

int tomato[100][100][100];
bool visited[100][100][100];

bool boundaryCheck(int x, int y, int z)
{
	if( x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= H )
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &M, &N, &H);
	int numOfZeros = 0;
	queue<point> q;
	for(int k=0; k<H; k++)
	{
		for(int j=0; j<N; j++)
		{
			for(int i=0; i<M; i++)
			{
				scanf("%d", &tomato[i][j][k]);
				if(tomato[i][j][k] == 1)
				{
					point p;
					p.x = i;
					p.y = j;
					p.z = k;
					p.day = 0;
					q.push(p);
					visited[i][j][k] = true;
				}
				else
				{
					visited[i][j][k] = false;
					if(tomato[i][j][k] == 0) numOfZeros++;
				}
			}
		}
	}

	int day = 0;
	while(!q.empty())
	{
		point p = q.front();
		q.pop();
		day = p.day;

		for(int i=0; i<6; i++)
		{
			if(boundaryCheck(p.x + dx[i], p.y + dy[i], p.z + dz[i])
			&& !visited[p.x + dx[i]][p.y + dy[i]][p.z + dz[i]]
			&& tomato[p.x + dx[i]][p.y + dy[i]][p.z + dz[i]] == 0)
			{
				point newPoint;
				newPoint.x = p.x+dx[i];
				newPoint.y = p.y+dy[i];
				newPoint.z = p.z+dz[i];
				newPoint.day = p.day+1;
				q.push(newPoint);
				visited[p.x + dx[i]][p.y + dy[i]][p.z + dz[i]] = true;
				numOfZeros--;
			}
		}
	}

	if(numOfZeros > 0) printf("-1\n");
	else printf("%d\n", day);

	return 0;
}
