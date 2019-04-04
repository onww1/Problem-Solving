#include <cstdio>
#include <cstdlib>

int cnt=0;
int memory[16] = {1, };
int decode(int size){
	int count = 0;
	while(size>1){
		count++;
		size/=2;
	}
	return count;
}
void Z(int r, int c, int dr, int dc, int size){
	int n = decode(size/2);
	if(r == dr && c == dc){printf("%d\n", cnt); exit(0);}
	if(size == 1){cnt++; return;}
	if(r<=dr && dr<r+size/2 && c<=dc && dc<c+size/2) Z(r, c, dr, dc, size/2);
	else cnt+=memory[n];
	if(r<=dr && dr<r+size/2 && c+size/2<=dc && dc<c+size) Z(r, c+size/2, dr, dc, size/2);
	else cnt+=memory[n];
	if(r+size/2<=dr && dr<r+size && c<=dc && dc<c+size/2) Z(r+size/2, c, dr, dc, size/2);
	else cnt+=memory[n];
	if(r+size/2<=dr && dr<r+size && c+size/2<=dc && dc<c+size) Z(r+size/2, c+size/2, dr, dc, size/2);
	else cnt+=memory[n];
	return;
}

int main(void){
	int N, r, c, size = 1;
	scanf("%d %d %d", &N, &r, &c);
	for(int i=0; i<N; i++) size *= 2;
	for(int i=1; i<=N; i++) memory[i] = 4 * memory[i-1];
	Z(0, 0, r, c, size);
	return 0;
}