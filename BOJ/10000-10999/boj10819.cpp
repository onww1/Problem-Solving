#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct element
{
	int n = 0;
	int val[4] = {0, 0, 0, 0};
}

int global_max = -1;
int n, a[8], p[8];
vector<int> ls, rs;
vector<element> left, right;
bool visited[4];

void init_visited(){
	for(int i=0; i<4; i++) visited[i] = false;
}

void permutation(vector<int> v, vector<){

}

int abs(int a){ return a>0?a:-a; }

int cal(){
	int sum = 0;
	for(int i=0; i<n-1; i++)
		sum += abs(p[i+1] - p[i]);
	return sum;
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);

	sort(a, a+n);
	if(n%2 == 0){
		for(int i=0; i<n/2; i++){
			ls.push_back(a[i]);
			rs.push_back(a[i+n/2]);
		}

	}
}