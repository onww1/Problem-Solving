#include <stdio.h>

int main(void){
	int N, L, cnt=0, ok, cur, len, hasD, arr[100][100]={0};
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	// row
	for(int i=0; i<N; i++){
		ok = 1;
		cur = arr[i][0];
		len = 1;
		hasD = 0;
		for(int j=1; j<N; j++){
			if(arr[i][j] == cur){len++; continue;}
			else if(arr[i][j] == cur-1){
				cur--; len=1;
				if(j+L > N){ ok = 0; break; }
				for(int k=j; k<j+L; k++){
					if(arr[i][k] != cur){ ok = 0; break; }
				}
				j += L-1;
				if(!ok) break;
				len += L-1;
				hasD = 1;
			} 
			else if(arr[i][j] == cur+1){
				if((hasD && len >= 2*L) || (!hasD && len >= L)){
					cur++; len=1;
					hasD = 0;
				}
				else{
					ok = 0;
					break;
				}
			}
			else{ ok = 0; break;}
		}
		cnt += ok;
	}

	// column
	for(int j=0; j<N; j++){
		ok = 1;
		cur = arr[0][j];
		len = 1;
		hasD = 0;
		for(int i=1; i<N; i++){
			if(arr[i][j] == cur){len++; continue;}
			else if(arr[i][j] == cur-1){
				cur--; len=1;
				if(i+L > N){ ok = 0; break; }
				for(int k=i; k<i+L; k++){
					if(arr[k][j] != cur){ ok = 0; break; }
				}
				i += L-1;
				if(!ok) break;
				len += L-1;
				hasD = 1;
			} 
			else if(arr[i][j] == cur+1){
				if((hasD && len >= 2*L) || (!hasD && len >= L)){
					cur++; len=1;
					hasD = 0;
				}
				else{
					ok = 0;
					break;
				}
			}
			else{ ok = 0; break;}
		}
		cnt += ok;
	}

	printf("%d\n", cnt);
	return 0;
}