import java.util.*;

public class Solution{
	static int[][] len, temp;
	static char[][] input;
	static boolean[][] visited;
	static boolean[][] curVisited;
	static int row, col, curAr, curAc;
	static boolean flag;

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), max=0;
		sc.nextLine();
		for(int test_case = 0; test_case < t; test_case++){
			input = new char[8][8];
			for(int i=0; i<8; i++){
				String line = sc.nextLine();
				input[i] = line.toCharArray();
			}
			len = new int[8][8];
			visited = new boolean[8][8];
			for(int i=0; i<8; i++) for(int j=0; j<8; j++) {len[i][j] = 0; visited[i][j] = false;}
			int i=0, j=0, a=64;
			while(a>0){
				a--;
				flag = false;
				temp = new int[8][8];
				curVisited = new boolean[8][8];
				for(i=0; i<8; i++) for(j=0; j<8; j++) {temp[i][j] = 0;curVisited[i][j] = false;}
				findMin();
				dfs(row, col);
				for(i=0; i<8; i++){
					for(j=0; j<8; j++){
						if(temp[i][j] > len[i][j])
							len[i][j] = temp[i][j];
					}
				}
			}
			for(i=0; i<8; i++){
				for(j=0; j<8; j++){
					if(max<len[i][j]) max = len[i][j];
				}
			}
			System.out.println(max);
		}
	}

	public static void findMin(){
		char min = 'Z'+1;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(!visited[i][j] && min>input[i][j]){
					row = i; col = j;
					min = input[i][j];
					if(min == 'A'){
						curAr = row;
						curAc = col;
						break;
					}else{curAr = -1; curAc = -1;}
				}
			}
		}
		visited[row][col] = true;
		temp[row][col] = 1;
	}

	public static void dfs(int r, int c){
		curVisited[r][c] = true;
		if(r>0){
			if(curVisited[r-1][c]);
			else if(input[r-1][c] > input[r][c]){
				if(temp[r-1][c] < temp[r][c] + 1){
					temp[r-1][c] = temp[r][c] + 1;
					dfs(r-1, c);
				}
			}
			else if(input[r][c] == 'Z' && input[r-1][c] == 'A'){
				if(!flag &&(r-1 != curAr || c != curAc)){
					flag = true;
					curAr = r-1; curAc = c;
					if(temp[r-1][c] < temp[r][c] + 1){
						temp[r-1][c] = temp[r][c] + 1;
						dfs(r-1, c);
					}
				} else if(flag && (r-1 == curAr && c == curAc)){
					if(temp[r-1][c] < temp[r][c] + 1){
						temp[r-1][c] = temp[r][c] + 1;
						dfs(r-1, c);
					}
				}

			}
		}
		if(r<7){
			if(curVisited[r+1][c]);
			else if(input[r+1][c] > input[r][c]){
				if(temp[r+1][c] < temp[r][c] + 1){
					temp[r+1][c] = temp[r][c] + 1;
					dfs(r+1, c);
				}
			}
			else if(input[r][c] == 'Z' && input[r+1][c] == 'A'){
				if(!flag &&(r+1 != curAr || c != curAc)){
					flag = true;
					curAr = r+1; curAc = c;
					if(temp[r+1][c] < temp[r][c] + 1){
						temp[r+1][c] = temp[r][c] + 1;
						dfs(r+1, c);
					}
				}else if(flag && (r+1 == curAr && c == curAc)){
					if(temp[r+1][c] < temp[r][c] + 1){
						temp[r+1][c] = temp[r][c] + 1;
						dfs(r+1, c);
					}
				}

			}
		}
		if(c>0){
			if(curVisited[r][c-1]);
			else if(input[r][c-1] > input[r][c]){
				if(temp[r][c-1] < temp[r][c] + 1) {
					temp[r][c-1] = temp[r][c] + 1;
					dfs(r, c-1);
				}
			}
			else if(input[r][c] == 'Z' && input[r][c-1] == 'A'){
				if(!flag &&(r != curAr || c-1 != curAc)){
					flag = true;
					curAr = r; curAc = c-1;
					if(temp[r][c-1] < temp[r][c] + 1){
						temp[r][c-1] = temp[r][c] + 1;
						dfs(r, c-1);
					}
				}else if(flag && (r == curAr && c-1 == curAc)){
					if(temp[r][c-1] < temp[r][c] + 1){
						temp[r][c-1] = temp[r][c] + 1;
						dfs(r, c-1);
					}
				}

			}
		}
		if(c<7){
			if(curVisited[r][c+1]);
			else if(input[r][c+1] > input[r][c]){
				if(temp[r][c+1] < temp[r][c] + 1) {
					temp[r][c+1] = temp[r][c] + 1;
					dfs(r, c+1);
				}
			}
			else if(input[r][c] == 'Z' && input[r][c+1] == 'A'){
				if(!flag &&(r != curAr || c+1 != curAc)){
					flag = true;
					curAr = r; curAc = c+1;
					if(temp[r][c+1] < temp[r][c] + 1){
						temp[r][c+1] = temp[r][c] + 1;
						dfs(r, c+1);
					}
				}else if(flag && (r == curAr && c+1 == curAc)){
					if(temp[r][c+1] < temp[r][c] + 1){
						temp[r][c+1] = temp[r][c] + 1;
						dfs(r, c+1);
					}
				}

			}
		}
		curVisited[r][c] = false;
	}
}