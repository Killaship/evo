#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define populationsize 8
int population[populationsize];

int cutoff = 100; // Minimum resistance needed to survive. Increments by 0.5 each generation.
int m1 = 10;
int m2 = 10;
int randnum() {
	int randnum;
	randnum = randombytes_random() % 10000 + 1;
	return randnum;
}
bool firstgen = true;
void step() {
	for(int i = 0; i < populationsize; i++) {
		printf("%d",(population[i] / 100));
		if(population[i] == 0) {
			// skip, this creature is dead
		}
		else if(population[i] < cutoff) {
			population[i] = 0;
		}
		else if(randnum() <= m1) {
			population[i]--;
		}
		else if(randnum() <= m2) {
			population[i]++;
		}
	}

	if(firstgen == false) {
		cutoff = cutoff + 10;
	}
	if(firstgen == true) {
		firstgen = false;

	}

	int sum = 0;
	for(int i = 0; i < populationsize; i++) {
		if(population[i] >= cutoff) {
			sum++;
		}
	}

	printf(" Survived Population = %d Cutoff = %f", sum, ((float) cutoff / 100));

	printf("\n");
	char waitchar;
	scanf("%c", &waitchar);
}
int main(int argc, char *argv[]) {
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	for(int i = 0; i < populationsize; i++) {
		population[i] = randnum() / 25;
	}
	int g;
	for(g = 0; g < atoi(argv[1]); g++) {
		step();
	}
}

