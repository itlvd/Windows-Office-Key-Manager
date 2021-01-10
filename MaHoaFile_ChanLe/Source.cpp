#include <stdio.h>
#include <conio.h>
#include <string.h>
int kiemtra(char x) {
	int i, s = 0;
	for (i = 0; i <= 7; i++)
		if (x & (1 << i)) s++;
	if (s % 2 == 0) return (0);
	return (1);
}
char code(char x) {
	if (kiemtra(x))
		x = x / 128;
	return(x);
}
char decode(char x) {
	if (x & 128)
		x = x & 127;
	return (x);
}
void code_file(char* name1, char* name2) {
	int i, k; char dong[255];
	FILE* fp1, * fp2;
	printf("\nTen file can ma hoa:"); scanf("%s", &name1);
	printf("\nTen file ma hoa:"); scanf("%s", &name2);
	fp1 = fopen(name1, "r"); fp2 = fopen(name2, "w");
	while (!feof(fp1)) {
		fgets(dong, 255, fp1);
		printf("%s", dong);
		k = strlen(dong);
		for (i = 0; i < k; i++) {
			if (dong[i] != ' ' && dong[i] != '\t' && dong[i] != '\n')
				dong[i] = code(dong[i]);
		}
		printf("%s", dong);
		fputs(dong, fp2);
	}
	fclose(fp1); fclose(fp2);
}
void decode_file(char* name1, char* name2) {
	int i, k; char dong[255];
	FILE* fp1, * fp2;
	printf("\nTen file can ma hoa:"); scanf("%s", &name1);
	printf("\nTen file ma hoa:"); scanf("%s", &name2);
	fp1 = fopen(name1, "r"); fp2 = fopen(name2, "w");
	while (!feof(fp1)) {
		fgets(dong, 255, fp1);
		printf("%s", dong);
		k = strlen(dong);
		for (i = 0; i < k; i++) {
			dong[i] = decode(dong[i]);
		}
		printf("%s", dong);
		fputs(dong, fp2);
	}
	fclose(fp1); fclose(fp2);
}
void main() {
	char name1[20], name2[20];
	code_file(name1, name2);
	decode_file(name1, name2);
}