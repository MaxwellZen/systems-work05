#include<stdio.h>
#include<stdlib.h>

void printbytes(int isdec, char* ptr) {
	for (int i = 0; i < 4; i++) {
		if (isdec) printf("%hhu ", *ptr);
		else printf("%hhx ", *ptr);
		ptr++;
	}
	printf("    ");
}

void printupdate(char* ptr) {
	printf("hexadecimal: ");
	printbytes(0, ptr);

	printf("decimal: ");
	printbytes(1, ptr);
	printf("\n");
}

int main() {
	char c = 'x';
	int k = 5048737;
	long n = 1787239747;
	printf("char location:\t%p\t%lu\n", &c, &c);
	printf("int location:\t%p\t%lu\n", &k, &k);
	printf("long location:\t%p\t%lu\n", &n, &n);
	char *cptr = &c;
	int *kptr = &k;
	long *nptr = &n;
	printf("Before modification:\n");
	printf("cptr: %c    kptr: %d    nptr: %ld\n", *cptr, *kptr, *nptr);
	*cptr = 'y';
	*kptr = 12345;
	*nptr = 123456789;
	printf("After modification:\n");
	printf("cptr: %c    kptr: %d    nptr: %ld\n", *cptr, *kptr, *nptr);
	unsigned int us = 987654321;
	int* intptr = &us;
	char* charptr = &us;
	printf("intptr: %p    intptr points to: %d\n", intptr, *intptr);
	printf("charptr: %p    charptr points to: %d\n", charptr, *charptr);
	printf("decimal: %u    hex: %x\n", us, us);

	printf("Original:\n");
	printupdate(charptr);

	printf("Adding one to each byte:\n");
	char* copy = charptr;
	for (int i = 0; i < 4; i++) {
		(*copy)++;
		copy++;
		printupdate(charptr);
	}

	printf("Adding 16 to each byte:\n");
	us = 987654321;
	copy = charptr;
	for (int i = 0; i < 4; i++) {
		(*copy) += 16;
		copy++;
		printupdate(charptr);
	}
}
