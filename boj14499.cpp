#include <cstdio>
#include <deque>

int n, m;
int map[20][20] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
std::deque<int> hori(3, 0);
std::deque<int> vert(4, 0);

int boundaryCheck(int row, int col){
	if(row < 0 || row >= n || col < 0 || col >= m) return 0;
	return 1;
}

void left(){
	int tmp1 = hori.front();
	int tmp2 = vert.back();
	hori.pop_front();
	vert.pop_back();
	hori.push_back(tmp2);
	vert.push_back(tmp1);
	vert[1] = hori[1];
}
void right(){
	int tmp1 = hori.back();
	int tmp2 = vert.back();
	hori.pop_back();
	vert.pop_back();
	hori.push_front(tmp2);
	vert.push_back(tmp1);
	vert[1] = hori[1];
}
void up(){
	int tmp = vert.front();
	vert.pop_front();
	vert.push_back(tmp);
	hori[1] = vert[1];
}
void down(){
	int tmp = vert.back();
	vert.pop_back();
	vert.push_front(tmp);
	hori[1] = vert[1];
}

int main(void){
	int ir, ic, t, command;
	scanf("%d %d %d %d %d", &n, &m, &ir, &ic, &t);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	while(t--){
		scanf("%d", &command);
		if(boundaryCheck(ir + dx[command-1], ic + dy[command-1])){
			ir += dx[command-1];
			ic += dy[command-1];

			if(command == 1) right();
			else if(command == 2) left();
			else if(command == 3) up();
			else if(command == 4) down();

			if(!map[ir][ic]) map[ir][ic] = vert[3];
			else {vert[3] = map[ir][ic]; map[ir][ic] = 0;}

			printf("%d\n", vert[1]);
		}
	}

	return 0;
}