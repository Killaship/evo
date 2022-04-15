#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#define populationsize 8
int population[populationsize];

int cutoff = 1; // Minimum resistance needed to survive. Increments by 0.5 each generation.
int m1 = 10;
int m2 = 10;
int randnum() {
	int randnum;
	randnum = randombytes_random() % 100 + 1;
	return randnum;
}


int averagepop(int population[populationsize]) {
	int sum;
	for(int i = 0; i < populationsize; i++) {
		sum = sum + population[i];
	}
	int average = sum / populationsize;
	return average;
}
bool firstgen = true;
void step() {
	
	for(int i = 0; i < populationsize; i++) {
		if(population[i] < cutoff) {
			population[i] = 0;
		}
		else if(randnum() <= m1) {
			population[i]--;
		}
		else if(randnum() <= m2) {
			population[i]++;
		}
		else if(population[i] == 0) {
			// skip, this creature is dead
		}	
		printf("%d", population[i]);
	}


	if(firstgen == false) {
		cutoff = cutoff + 1;
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
	int popbuffer[populationsize];
	memcpy(population, popbuffer, sizeof(population));
	for(int i = 0; i < populationsize; i++) {
		popbuffer[i] = population[i];
	}
	for(int i = 0; i < populationsize; i++) {
		if(popbuffer[i] != 0) {
			population[i] = averagepop((int *)popbuffer);
		}
	}
	
	printf(" Survived Population = %d Cutoff = %d\n", sum, cutoff);
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

