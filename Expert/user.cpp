void make_huff(unsigned int ehuff[128], int hlen[128], char dhuff[512][9]) {
	ehuff['a'] = 0b1010;		hlen['a'] = 4; dhuff[0b1010][3] = 'a';
	ehuff['b'] = 0b011110;		hlen['b'] = 6; dhuff[0b011110][5] = 'b';
	ehuff['c'] = 0b01010;		hlen['c'] = 5; dhuff[0b01010][4] = 'c';
	ehuff['d'] = 0b10110;		hlen['d'] = 5; dhuff[0b10110][4] = 'd';
	ehuff['e'] = 0b1000;		hlen['e'] = 4; dhuff[0b1000][3] = 'e';
	ehuff['f'] = 0b01011;		hlen['f'] = 5; dhuff[0b01011][4] = 'f';
	ehuff['g'] = 0b101110;		hlen['g'] = 6; dhuff[0b101110][5] = 'g';
	ehuff['h'] = 0b0000;		hlen['h'] = 4; dhuff[0b0000][3] = 'h';
	ehuff['i'] = 0b1101;		hlen['i'] = 4; dhuff[0b1101][3] = 'i';
	ehuff['j'] = 0b111111100;	hlen['j'] = 9; dhuff[0b111111100][8] = 'j';
	ehuff['k'] = 0b011111;		hlen['k'] = 6; dhuff[0b011111][5] = 'k';
	ehuff['l'] = 0b11110;		hlen['l'] = 5; dhuff[0b11110][4] = 'l';
	ehuff['m'] = 0b01000;		hlen['m'] = 5; dhuff[0b01000][4] = 'm';
	ehuff['n'] = 0b1100;		hlen['n'] = 4; dhuff[0b1100][3] = 'n';
	ehuff['o'] = 0b1110;		hlen['o'] = 4; dhuff[0b1110][3] = 'o';
	ehuff['p'] = 0b111110;		hlen['p'] = 6; dhuff[0b111110][5] = 'p';
	ehuff['q'] = 0b111111110;	hlen['q'] = 9; dhuff[0b111111110][8] = 'q';
	ehuff['r'] = 0b0110;		hlen['r'] = 4; dhuff[0b0110][3] = 'r';
	ehuff['s'] = 0b0001;		hlen['s'] = 4; dhuff[0b0001][3] = 's';
	ehuff['t'] = 0b1001;		hlen['t'] = 4; dhuff[0b1001][3] = 't';
	ehuff['u'] = 0b01110;		hlen['u'] = 5; dhuff[0b01110][4] = 'u';
	ehuff['v'] = 0b1111110;		hlen['v'] = 7; dhuff[0b1111110][6] = 'v';
	ehuff['w'] = 0b01001;		hlen['w'] = 5; dhuff[0b01001][4] = 'w';
	ehuff['x'] = 0b111111101;	hlen['x'] = 9; dhuff[0b111111101][8] = 'x';
	ehuff['y'] = 0b101111;		hlen['y'] = 6; dhuff[0b101111][5] = 'y';
	ehuff['z'] = 0b111111111;	hlen['z'] = 9; dhuff[0b111111111][8] = 'z';
	ehuff[' '] = 0b001;			hlen[' '] = 3; dhuff[0b001][2] = ' ';
}

void write_bit(unsigned char* ptr, int &offset, int &idx, int needed, unsigned int bit) {
	unsigned char mask[9] = { 0, 1, 3, 7, 15, 31, 63, 127, 255 };
	while (offset <= needed) {
		*(ptr + idx++) |= ((bit >> (needed - offset)) & mask[offset]);
		*(ptr + idx) = 0;
		needed -= offset;
		offset = 8;
	}
	if (needed) {
		offset -= needed;
		*(ptr + idx) |= ((bit & mask[needed]) << offset);	
	}
}

unsigned int read_bit(unsigned char* ptr, int &offset, int &idx, int needed) {
	unsigned char mask[9] = { 0, 1, 3, 7, 15, 31, 63, 127, 255 };
	unsigned int ret = 0;
	while (offset <= needed) {
		ret = (ret << offset) + (*(ptr + idx++) & mask[offset]);
		needed -= offset;
		offset = 8;
	}
	offset -= needed;
	ret = (ret << needed) + (((*(ptr + idx)) >> offset) & mask[needed]);
	return ret;
}

char read_huff(unsigned char* ptr, int &offset, int &idx, char dhuff[512][9]) {
	unsigned int bit = 0;
	for (int depth = 0; depth < 9; ++depth) {
		if (!offset) {
			offset = 8;
			++idx;
		}
		bit = (bit << 1) + ((*(ptr + idx) >> (--offset)) & 1);
		if (dhuff[bit][depth]) 
			return dhuff[bit][depth];
	}
	return 0;
}

bool isSame(char* str1, char* str2, int len) {
	for (int i = 0; i < len; ++i) 
		if (str1[i] != str2[i])
			return false;
	return true;
}

int encode(char* src, char* paper, int papern) {
	char dic[1024][8]{};
	int pidx = 0, widx = 0, j = 0, cnt = 0;
	int idx[1 << 15]{};

	/* uniquify & indexing */
	for (; pidx < papern; ++pidx) {
		if (paper[pidx] == ' ') {
			while (j < 8) dic[cnt][j++] = 0;
			idx[widx++] = cnt;
			bool isFound = false;
			for (int i = 0; i < cnt; ++i) {
				if (isSame(dic[cnt], dic[i], 8)) {
					idx[widx - 1] = i;
					isFound = true;
					break;
				}
			}
			if (!isFound) ++cnt;
			j = 0;
		}
		else dic[cnt][j++] = paper[pidx];
	}

	/* make huff */
	unsigned int ehuff[128]{};
	int hlen[128]{};
	char dhuff[512][9]{};
	make_huff(ehuff, hlen, dhuff);

	int offset = 8, sidx = 0;
	unsigned char * ptr = (unsigned char *)src;
	src[0] = 0;

	/* write unique words */
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; dic[i][j]; ++j) 
			write_bit(ptr, offset, sidx, hlen[dic[i][j]], ehuff[dic[i][j]]);
		write_bit(ptr, offset, sidx, hlen[' '], ehuff[' ']);
	}
	write_bit(ptr, offset, sidx, hlen[' '], ehuff[' ']);

	/* write the number of words */
	write_bit(ptr, offset, sidx, 16, (unsigned int)widx);

	/* write index */
	for (int i = 0 ; i < widx; ++i) 
		write_bit(ptr, offset, sidx, 10, (unsigned int)idx[i]);

	if (offset < 8) ++sidx;
	return sidx;
}

void decode(char* dest, char* src, int s) {
	char dic[1024][8]{};
	int sidx = 0, offset = 8, cnt = 0, j = 0;
	unsigned char * ptr = (unsigned char *)src;

	/* make huff */
	unsigned int ehuff[128]{};
	int hlen[128]{};
	char dhuff[512][9]{};
	make_huff(ehuff, hlen, dhuff);

	/* read unique words */
	char cur = 0, prv = 0;
	while (sidx < s) {
		cur = read_huff(ptr, offset, sidx, dhuff);
		if (cur == ' ') {
			if (prv == ' ') break;
			++cnt;
			j = 0;
		}
		else dic[cnt][j++] = cur;
		prv = cur;
	}

	/* read the number of words */
	unsigned int didx = 0, widx = 0;
	widx = read_bit(ptr, offset, sidx, 16);

	/* read index & write answer */
	for (int i = 0; i < widx; ++i) {
		unsigned int idx = read_bit(ptr, offset, sidx, 10);
		for (int k = 0; dic[idx][k]; ++k)
			dest[didx++] = dic[idx][k];
		dest[didx++] = ' ';
	}
}