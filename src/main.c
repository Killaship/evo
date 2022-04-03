#include <sodium.h>
#include <stdio.h>

int population;

int b1 = 100;
int d1 = 10;
int r1 = 5;

int main() {
	if(sodium_init() < 0) {
		/* panic! the library couldn't be initialized, it is not safe to use */
		return 1;
	}

}
  
