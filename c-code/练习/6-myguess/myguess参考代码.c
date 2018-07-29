#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


void generate(char computer[])
{
	int i = 0, j, t;

	srand(time(NULL));
	while (i < 4) {
		t = rand() % 10 + '0';
		for (j = 0; j < i; ++j)
			if (t == computer[j])
				break;
		if (j == i) {
			computer[i] = t;
			++i;
		}
	}
}

int is_valid(char man[])
{
	int i, j;

	if (!(isdigit(man[0])
				&& isdigit(man[1])
				&& isdigit(man[2])
				&& isdigit(man[3])
				&& man[4] == '\0'))
		return 0;
	for (i = 0; i < 3; ++i)
		for (j = i + 1; j < 4; ++j)
			if (man[i] == man[j])
				return 0;
	return 1;
}

int compare(char man[], char computer[])
{
	int i, j, a = 0, b = 0;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (computer[i] == man[j] && i == j)
				++a;
			else if (computer[i] == man[j])
				++b;
	if (a == 4) {
		printf("YOU BET\n");
		return 1;
	}
	if (a == 0 && b == 0) {
		printf("0000\n");
		return 0;
	}
	while (a > 0) {
		putchar('A');
		--a;
	}
	while (b > 0) {
		putchar('B');
		--b;
	}
	putchar('\n');
	return 0;
}

int usr_input(char array[])
{
		printf("Please input four different letters:\n");
		if (scanf("%s", array) != 1) {
			printf("Unkown error!\n");
			return 1;
		}
		return 0;
}
void exit_output(char computer[])
{
		printf("The answer is: %c%c%c%c\n", computer[0], computer[1], computer[2], computer[3]);
}
void err_output(char str[])
{
		printf("%s\n", str);
}
int main(void)
{
	char computer[100];
	char man[100];
	generate(computer);
	while (1) {
		usr_input(man);
		if ((strcmp(man, "EXIT") == 0) || (strcmp(man, "exit") == 0)) {
			exit_output(computer);
			return 0;
		}
		if (!is_valid(man)) {
			err_output("Invalid input!");
			continue;
		}
		if (compare(man, computer))
			return 0;
	}
}
