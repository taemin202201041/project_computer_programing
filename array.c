#include <stdio.h>
void array(FILE* fp) {
	char k[100];
	while (fgets(k, 100, fp) != NULL) {
		printf("%s", k);
	}
}