#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int population;

int b1 = 100;
int d1 = 10;
int r1 = 5;

int randnum() {
	int randnum;
	randnum = randombytes_random() % 100 + 1;
	return randnum;
}
void step() {
	
	if(randnum <= b1) {
		population++;
	}
	for(int i = 1; i < population; i++) {
		if(randnum() <= d1) {
			population--;
		}
		if(randnum() <= r1) {
			population++;
		}
	}
	printf("Population = %d\n",population);
	
}
int main(int argc, char *argv[]) {
	population = atoi(argv[2]);
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	int g;
	for(g = 0; g < atoi(argv[1]); g++) {
		step();
	}
}
  
