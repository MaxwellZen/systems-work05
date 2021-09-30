#include<stdio.h>
#include<stdlib.h>

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
	printf("Bytes in hexadecimal:\n");
	char* copy = charptr;
	for (int i = 0; i < 4; i++) {
		printf("%hhx ", *copy);
		copy++;
	}
	printf("\n");
	printf("Bytes in decimal:\n");
	copy = charptr;
	for (int i = 0; i < 4; i++) {
		printf("%hhu ", *copy);
		copy++;
	}
	printf("\n");
}
