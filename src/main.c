#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int populationsize = 8;
int population[populationsize];
int cutoff = 1; // Provided in arguments, is minimum resistance needed to survive. Increments by 0.5 each generation.
int m1 = 10;
int randnum() {
	int randnum;
	randnum = randombytes_random() % 100 + 1;
	return randnum;
}
void step() {
	if(randnum <= b1) {
		population++;
	}
	for(int i = 1; i < populationsize; i++) {
		if(population[i] < cutoff)
		if(randnum() <= m1) {
			population[i]++;
		}
	}
	cutoff = cutoff + 0.5;
	printf("Survived Population = %d\n",population);
}
int main(int argc, char *argv[]) {
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	int g;
	cutoff = atoi(argv[2]);
	for(g = 0; g < atoi(argv[1]); g++) {
		step();
	}
}

