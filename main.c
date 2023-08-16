#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int rec(int a,int b,int count,int *res) {
	if (!count)
		(*res)++;
	for (int j = a + 1; j <= b && count; j++)
		rec(j, b, count-1, res);
}
int calc(int from,int to,int comb_len,int comb_of_comb_len) {
	int part1=0, part2=0;
	rec(0, comb_len, comb_of_comb_len, &part1);
	rec(0, to - from + 1 - comb_len, comb_len - comb_of_comb_len, &part2);
	return part1 * part2;
}
void menu_stat() {
	int from, to, comb_len, comb_of_comb_len,run;
	do {
		printf("Enter numbers of game like 1,70: ");
		scanf("%d %d", &from, &to);
		printf("Enter win combination len: ");
		scanf("%d", &comb_len);
		printf("Enter a len of part of combination of win combination: ");
		scanf("%d", &comb_of_comb_len);
		printf("The number of posible unique combinations of %d from %d\nfrom %d win numbers Is: %d\n",
			comb_of_comb_len, comb_len, to - from + 1,
			calc(from,to,comb_len,comb_of_comb_len));
		printf("again enter 1 else exit: ");
		scanf("%d", &run);
	}while (run == 1);
}
int main() {
	menu_stat();
	system("pause>0");
	return 0;
}