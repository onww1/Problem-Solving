#include <cstdio>
#include <queue>
#include <utility>

int n, m;
char map[10][11];
std::queue< std::pair< std::pair< std::pair<int,int>, std::pair<int,int> >, int > > q;

int main(void){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%s", map[i]);
	}

	int rr, rc, br, bc, cnt;
	for(int i=1; i<n-1; i++){
		for(int j=1; j<m-1; j++){
			if( map[i][j] == 'R' ){
				map[i][j] = '.';
				rr = i; rc = j;
			}
			if( map[i][j] == 'B' ){
				map[i][j] = '.';
				br = i; bc = j;
			}
		}
	}

	q.push( std::make_pair( std::make_pair( std::make_pair(rr, rc), std::make_pair(br, bc) ), 0) );
	while(!q.empty()){
		rr = q.front().first.first.first;
		rc = q.front().first.first.second;
		br = q.front().first.second.first;
		bc = q.front().first.second.second;
		cnt = q.front().second;
		q.pop();

		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<m; j++){
		// 		if(i==rr && j==rc) printf("R");
		// 		else if(i==br && j==bc) printf("B");
		// 		else printf("%c", map[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");

		if( cnt == 10 ) {printf("-1\n"); break;}

		//left
		int rval = rc, bval = bc, ok = 0, flag = 1;
		if(rr == br){
			if(rc < bc){
				while( rval - 1 > 0 ) {
					if( map[rr][rval-1] == '.') rval--;
					else if( map[rr][rval-1] == 'O' ) { rval--; ok = 1; break;}
					else break;
				}
				while( bval - 1 >= rval ) {
					if( map[br][bval-1] == '.' && bval - 1 > rval) bval--;
					else if( map[br][bval-1] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
			} else{
				while( bval - 1 > 0 ) {
					if( map[br][bval-1] == '.') bval--;
					else if( map[br][bval-1] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
				while( rval - 1 > bval ) {
					if(!flag) break;
					else if( map[rr][rval-1] == '.') rval--;
					else if( map[rr][rval-1] == 'O' ) { ok = 1; flag = 1; break;}
					else break;
				}
			}
		} else {
			while( rval - 1 > 0 ) {
				if( map[rr][rval-1] == '.') rval--;
				else if( map[rr][rval-1] == 'O' ) { rval--; ok = 1; break;}
				else break;
			}
			while( bval - 1 > 0 ) {
				if(ok) break;
				else if( map[br][bval-1] == '.') bval--;
				else if( map[br][bval-1] == 'O' ) {flag = 0; break;}
				else break;
			}
		}
		
		if(ok) {printf("%d\n", cnt+1); break;}
		if(flag) q.push( std::make_pair( std::make_pair( std::make_pair(rr, rval), std::make_pair(br, bval)), cnt+1) );

		//right
		rval = rc, bval = bc, ok = 0, flag = 1;
		if(rr == br){
			if(rc > bc){
				while( rval + 2 < m ) {
					if( map[rr][rval+1] == '.') rval++;
					else if( map[rr][rval+1] == 'O' ) { rval++; ok = 1; break;}
					else break;
				}
				while( bval + 1 <= rval ) {
					if( map[br][bval+1] == '.' && bval + 1 < rval) bval++;
					else if( map[br][bval+1] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
			} else{
				while( bval + 2 < m ) {
					if( map[br][bval+1] == '.') bval++;
					else if( map[br][bval+1] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
				while( rval + 1 < bval ) {
					if(!flag) break;
					else if( map[rr][rval+1] == '.') rval++;
					else if( map[rr][rval+1] == 'O' ) { ok = 1; flag = 1; break;}
					else break;
				}
			}
		} else {
			while( rval + 2 < m ) {
				if( map[rr][rval+1] == '.') rval++;
				else if( map[rr][rval+1] == 'O' ) { rval++; ok = 1; break;}
				else break;
			}
			while( bval + 2 < m ) {
				if(ok) break;
				else if( map[br][bval+1] == '.') bval++;
				else if( map[br][bval+1] == 'O' ) {flag = 0; break;}
				else break;
			}
		}
		
		if(ok) {printf("%d\n", cnt+1); break;}
		if(flag) q.push( std::make_pair( std::make_pair( std::make_pair(rr, rval), std::make_pair(br, bval)), cnt+1) );
		
		//up
		rval = rr, bval = br, ok = 0, flag = 1;
		if(rc == bc){
			if(rr < br){
				while( rval - 1 > 0 ) {
					if( map[rval-1][rc] == '.') rval--;
					else if( map[rval-1][rc] == 'O' ) { rval--; ok = 1; break;}
					else break;
				}
				while( bval - 1 >= rval ) {
					if( map[bval-1][bc] == '.' && bval - 1 > rval) bval--;
					else if( map[bval-1][bc] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
			} else{
				while( bval - 1 > 0 ) {
					if( map[bval-1][bc] == '.') bval--;
					else if( map[bval-1][bc] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
				while( rval - 1 > bval ) {
					if(!flag) break;
					else if( map[rval-1][rc] == '.') rval--;
					else if( map[rval-1][rc] == 'O' ) { ok = 1; flag = 1; break;}
					else break;
				}
			}
		} else {
			while( rval - 1 > 0 ) {
				if( map[rval-1][rc] == '.') rval--;
				else if( map[rval-1][rc] == 'O' ) { rval--; ok = 1; break;}
				else break;
			}
			while( bval - 1 > 0 ) {
				if(ok) break;
				else if( map[bval-1][bc] == '.') bval--;
				else if( map[bval-1][bc] == 'O' ) {flag = 0; break;}
				else break;
			}
		}
		
		if(ok) {printf("%d\n", cnt+1); break;}
		if(flag) q.push( std::make_pair( std::make_pair( std::make_pair(rval, rc), std::make_pair(bval, bc)), cnt+1) );
		
		//down
		rval = rr, bval = br, ok = 0, flag = 1;
		if(rc == bc){
			if(rr > br){
				while( rval + 2 < n ) {
					if( map[rval+1][rc] == '.') rval++;
					else if( map[rval+1][rc] == 'O' ) { rval++; ok = 1; break;}
					else break;
				}
				while( bval + 1 <= rval ) {
					if( map[bval+1][bc] == '.' && bval + 1 < rval) bval++;
					else if( map[bval+1][bc] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
			} else{
				while( bval + 2 < n ) {
					if( map[bval+1][bc] == '.') bval++;
					else if( map[bval+1][bc] == 'O' ) { ok = 0; flag = 0; break;}
					else break;
				}
				while( rval + 1 < bval ) {
					if(!flag) break;
					else if( map[rval+1][rc] == '.') rval++;
					else if( map[rval+1][rc] == 'O' ) { ok = 1; flag = 1; break;}
					else break;
				}
			}
		} else {
			while( rval + 2 < n ) {
				if( map[rval+1][rc] == '.') rval++;
				else if( map[rval+1][rc] == 'O' ) { rval++; ok = 1; break;}
				else break;
			}
			while( bval + 2 < n ) {
				if(ok) break;
				else if( map[bval+1][bc] == '.') bval++;
				else if( map[bval+1][bc] == 'O' ) {flag = 0; break;}
				else break;
			}
		}
		
		if(ok) {printf("%d\n", cnt+1); break;}
		if(flag) q.push( std::make_pair( std::make_pair( std::make_pair(rval, rc), std::make_pair(bval, bc)), cnt+1) );
	}

	return 0;
}