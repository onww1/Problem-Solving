#include <iostream>
#include <vector>
using namespace std;

struct point
{
	int r, c;
};

int R, C, cnt = 0;
vector<point> stack;

int move_r[] = {-1, 1, 0, 0};
int move_c[] = {0, 0, -1, 1};

bool is_ddoo(int r, int c){
	int l = r * R + c;
	if(l%5 == 0 || l%5 == 3) return true;
	else return false;
}

bool check(int r, int c){
	if(r < 0 || r >= R || c < 0 || c >= C) return false;
	return true;
}

bool isVisit(int r, int c){
	int len = stack.size();
	for(int i=0; i<len; i++){
		if(stack[i].r == r && stack[i].c == c) 
			return true;
	}
	return false;
}

void dfs(int r, int c, int t){
	if(t == 4){
		cnt++;
		return;
	}

	stack.push_back({r, c});

	for(int k=0; k<4; k++){
		int dr = r + move_r[k];
		int dc = c + move_c[k];

		if(check(dr, dc)){
			if(t == 2 && is_ddoo(dr, dc) && !isVisit(dr, dc)){
				dfs(dr, dc, t+1);
			} 
			else if(!is_ddoo(dr, dc) && !isVisit(dr, dc)){
				dfs(dr, dc, t+1);
			}
		}
	}

	stack.pop_back();
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(is_ddoo(i, j)){
				dfs(i, j, 0);
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}