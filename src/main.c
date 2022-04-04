#include <sodium.h>
#include <stdio.h>

int population;

int b1 = 100;
int d1 = 10;
int r1 = 5;

void step() {
	int randnum = randombytes.random() % 100 + 1;
	if(randnum <= b1) {
		population++;
	}
	if(randnum <= d1) {
		population--;
	}
	
}
int main() {
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}
	step();

}
  
