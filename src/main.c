#include <sodium.h>
#include <stdio.h>

int population = 2;

int b1 = 100;
int d1 = 10;
int r1 = 5;

int randnum() {
	int randnum = randombytes.random() % 100 + 1;
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
int main() {
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	step();
	step();
	step();
	step();
	step();
	
}
  
