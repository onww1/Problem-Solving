#include <stdio.h>
#include <memory.h>
#include <time.h>

static char memory[400000000];
static char dummy[253011];
static char atbl[100000000];

static unsigned long long seed = 5; // seed can be changed

static int mod = 256; // mod can be changed

static int   unit_size[4] = { 4, 16, 64, 256 };
static char* unit_ptr[4][10000000];
static int   unit_count[4];

extern void init_block(char atbl[100000000], char memory[400000000]);
extern char* alloc_block(char atbl[100000000], int size);
extern void free_block(char atbl[100000000], char* ptr);

static unsigned int pseudo_rand(void)
{
	seed = seed * 25214903917ULL + 11ULL;
	return (unsigned int)(seed >> 16);
}

static bool verify()
{
	char cmp_tbl[256][256];
	int verify_Cnt = 0;

	for (register int unit = 0; unit < 4; unit++)
		for (register int c = 0; c < unit_count[unit]; c++)
			if (unit_ptr[unit][c] != NULL)
				memset(unit_ptr[unit][c], c % mod, unit_size[unit]);

	for (register int c = 0; c < 256; c++) memset(cmp_tbl[c], c, 256);

	for (register int unit = 0; unit < 4; unit++)
		for (register int c = 0; c < unit_count[unit]; c++)
		{
			register char* ptr = unit_ptr[unit][c];
			if (ptr != NULL)
			{
				verify_Cnt++;
				if ((ptr < memory) || (ptr + unit_size[unit] > memory + 1562500 * 256)) 
					return false;
				if (memcmp(ptr, cmp_tbl[c % mod], unit_size[unit]) != 0) 
					return false;
			}
		}

	if (verify_Cnt == 0)
		return false;

	return true;
}

int main()
{
	int unit_total = 0;
	int alloc_total = 0;

	for (int c = 0; c < 4; c++)
	{
		unit_ptr[c][0] = NULL;
		unit_count[c] = 1;
	}

	clock_t start = clock();
	init_block(atbl, memory);

	while (unit_total != 400000000)
	{
		register int unit = pseudo_rand() % 4;
		register int index;

		char* ptr = alloc_block(atbl, unit_size[unit]);
		unit_ptr[unit][unit_count[unit]++] = ptr;

		if (ptr != NULL)
		{
			unit_total += unit_size[unit];
			alloc_total += unit_size[unit];
			memset(ptr, 0, unit_size[unit]);
		}
		else
			alloc_total -= unit_size[unit];

		unit = pseudo_rand() % 4;
		if (unit_count[unit] <= 0)
			break;
		index = pseudo_rand() % unit_count[unit];

		if (unit_ptr[unit][index] != NULL)
		{
			free_block(atbl, unit_ptr[unit][index]);
			unit_ptr[unit][index] = NULL;
			unit_total -= unit_size[unit];
		}
	}

	double SCORE = alloc_total + (100000 - (int)(clock() - start) / (CLOCKS_PER_SEC / 10000.0)) / 100000.0;
	if (verify() == false) SCORE = 0;

	printf("SCORE: %20.5lf\n", SCORE);

	return 0;
}



// DO NOT USE ANY HEAP OR STATIC MEMORY
void init_block(char atbl[100000000], char memory[400000000])
{	

}

char* alloc_block(char atbl[100000000], int size)
{	
	return 0;
}

void free_block(char atbl[100000000], char* ptr)
{
	
}