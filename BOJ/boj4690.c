#include <stdio.h>

int main(void){
	int cube[4], triple;

	for(int a=3; a<=100; a++){
		cube[0] = a * a * a;
		triple = 0;
		for(int b=2; b<=100; b++){
			cube[1] = b * b * b;
			if(triple + cube[1] >= cube[0]) break;

			triple += cube[1];
			for(int c=b; c<=100; c++){
				cube[2] = c * c * c;
				if(triple + cube[2] >= cube[0]) break;

				triple += cube[2];
				for(int d=c; d<=100; d++){
					cube[3] = d * d * d;
					if(triple + cube[3] == cube[0]){
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
						break;
					}
					else if(triple + cube[3] > cube[0]) break;
				}

				triple -= cube[2];
			}

			triple -= cube[1];
		}
	}

	return 0;
}