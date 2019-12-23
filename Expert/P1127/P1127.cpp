#include <stdio.h>
#include <memory.h>
#include <time.h>

static unsigned int seed = 5;

extern int encode(char*, char*, int);
extern void decode(char*, char*, int);

static char alphabet[1304];
static int dic_len[1024];
static char dic[1024][8];
static char dummy1[1025];
static char paper[65536];
static char dummy2[1341];
static char bak_paper[65536];
static char dummy3[3132];
static char src[65536];
static char dummy4[3943];
static char dest[65536];

// https://en.wikipedia.org/wiki/Letter_frequency
const int hit[26] = {106, 19, 29, 55, 165, 29, 26, 79, 90, 2, 17, 52, 31, 88, 97, 25, 1, 78, 82, 122, 36, 13, 33, 2, 26, 1}; // total 1304

int rand() {
	seed = seed * 214013L + 2531011L;
	return (seed >> 16) & 0x7FFF;
}

void build_dic() {
	int idx = 0;
	for (int i = 0; i < 26; ++i) {
		int n = hit[i];
		for (int j = 0; j < n; ++j) {
			alphabet[idx++] = 'a' + i;
		}
	}
	for (int i = 0; i < 1024; ++i) {
		int len = rand() % 7 + 1;
		for (int j = 1; j <= len; ++j) {
			dic_len[i] = len;
			dic[i][j] = alphabet[rand() % 1304];
		}
	}
}

int main() {
	/*
	 * SCORE를 최대한 낮은 값으로 만드는 것이 목표
	 * user.cpp 파일에서 어떠한 전역변수를 사용해서는 안된다.
	 * user.cpp 파일에서 static 등의 키워드가 사용될 시 실격처리됨.
	 * user.cpp 파일에서 사용가능한 library는 memory.h가 유일하다.
	 **/
	build_dic();

	long double SCORE = 0;
	clock_t start = clock();

	int papern;
	int sel;
	int wordLen;
	for (int i = 0; i < 100; ++i) {
		while (papern < 65536) {
			sel = rand() % 1024;
			wordLen = dic_len[sel];
			if (papern + wordLen > 65535) break;
			for (int j = 1; j <= wordLen; ++j) {
				paper[papern++] = dic[sel][j];
			}
			paper[papern++] = ' ';
		}

		for (int j = 0; j < papern; ++j) {
			bak_paper[j] = paper[j];
		}

		int s = encode(src, bak_paper, papern); 
		for (int j = s; j < 65536; ++j) {
			src[j] = 0;
		}

		decode(dest, src, s);
		if (memcmp(dest, paper, papern) != 0) {
			SCORE += 10000000;
		} else {
			SCORE += s;
		}
	}

	SCORE += (long double)(clock() - start) / 100000;
	printf("total SCORE : %.5Lf\n", SCORE);

	return 0;
}