// Nuri Furkan Pala

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int isThere(char arr[], int n, char *value) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == *value) return i;
	}
	return -1;
}

int size(char arr[]) {
	int i = 0, n = 0;
	while (true) {
		if (arr[i] != '\0') i++;
		else return i;
	}
}

int main(int argc, char *argv[]) {
	static char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	static char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	static char number[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	if (argc == 1) {
		printf("Caeser Cipher Encryption/Decryption Tool\nVersion: 1.0\nAuthor: Nuri Furkan Pala\n\nIf you need any help, enter 'caesercipher -h'.\n");
	}
	else if (!strcmp(argv[1], "-h")) {
		printf("Usage: caesercipher [OPTIONS] [WORD] ...\nEncrypt or decrypt words with 'Caeser Cipher'.\n\nOptions are:\n	-h	Help\n	-v	Version\n	-c	Encrypt/Decrypt without numbers\n	-n	Encrypt/Decrypt with numbers\n");
	}
	else if (!strcmp(argv[1], "-v")) {
		printf("Caeser Cipher Encryption/Decryption Tool Version: 1.0\n");
	}
	else if (!strcmp(argv[1], "-c")) {
		for (int i = 0; i < 26; i++) {
			printf("+%d	", i);
			for (int j = 2; j < argc; j++) {
				for (int k = 0; k < size(argv[j]); k++) {
					if (isThere(lower, 26, &argv[j][k]) != -1) printf("%c", lower[(isThere(lower, 26, &argv[j][k]) + i) % 26]);
					else if (isThere(upper, 26, &argv[j][k]) != -1) printf("%c", upper[(isThere(upper, 26, &argv[j][k]) + i) % 26]);
					else printf("%c", argv[j][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}
	else if (!strcmp(argv[1], "-n")) {
		for (int i = 0; i < 26; i++) {
			printf("+%d	", i);
			for (int j = 2; j < argc; j++) {
				for (int k = 0; k < size(argv[j]); k++) {
					if (isThere(lower, 26, &argv[j][k]) != -1) printf("%c", lower[(isThere(lower, 26, &argv[j][k]) + i) % 26]);
					else if (isThere(upper, 26, &argv[j][k]) != -1) printf("%c", upper[(isThere(upper, 26, &argv[j][k]) + i) % 26]);
					else if (isThere(number, 10, &argv[j][k]) != -1) printf("%c", number[(isThere(number, 10, &argv[j][k]) + i) % 10]);
					else printf("%c", argv[j][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}
	else {
		printf("Invalid option! If you need any help, enter 'caesercipher -h'.\n");
	}
	return 0;
}
